/*Can you solve this real interview question? Minimum Cost to Make at Least One Valid Path in a Grid - Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:

 * 1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
 * 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
 * 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
 * 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])

Notice that there could be some signs on the cells of the grid that point outside the grid.

You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.

 

Example 1:

[https://assets.leetcode.com/uploads/2020/02/13/grid1.png]


Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
The total cost = 3.


Example 2:

[https://assets.leetcode.com/uploads/2020/02/13/grid2.png]


Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
Output: 0
Explanation: You can follow the path from (0, 0) to (2, 2).


Example 3:

[https://assets.leetcode.com/uploads/2020/02/13/grid3.png]


Input: grid = [[1,2],[4,3]]
Output: 1


 

Constraints:

 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 100
 * 1 <= grid[i][j] <= 4*/


const int di[4] = {0, 0, 1, -1};
const int dj[4] = {1, -1, 0, 0};
class Solution {
public:
    static inline bool isOutside(int i, int j, int r, int c) {
        return i < 0 || i >= r || j < 0 || j >= c;
    }
    static inline unsigned pack(unsigned d, unsigned i, unsigned j) {
        return (d << 16) + (i << 8) + j;
    }
    static inline array<int, 3> unpack(unsigned info) {
        array<int, 3> ans;
        ans[0] = info >> 16, ans[1] = (info >> 8) & 255, ans[2] = info & 255;
        return ans;
    }
    static unsigned int idx(int i, int j, int c) { return i * c + j; }

    static int minCost(vector<vector<int>>& grid) {
        const int r = grid.size(), c = grid[0].size();
        priority_queue<unsigned, vector<unsigned>, greater<>> pq;
        unsigned* dist = (unsigned*)alloca(r * c * sizeof(unsigned));
        bitset<10000> viz = 0;
        fill(dist, dist + r * c, UINT_MAX);
        pq.push(pack(0, 0, 0));
        dist[0] = 0;
        viz[0] = 1;
        while (!pq.empty()) {
            auto info = pq.top();
            pq.pop();
            auto [d, i, j] = unpack(info);
            viz[idx(i, j, c)] = 1;
            if (i == r - 1 && j == c - 1)
                return d;
            int x = grid[i][j];
            for (int a = 0; a < 4; a++) {
                int s = i + di[a], t = j + dj[a];
                if (isOutside(s, t, r, c) || viz[idx(s, t, c)])
                    continue;
                int new_d = d + 1 - (a + 1 == x);
                int b = idx(s, t, c);
                if (new_d < dist[b]) {
                    dist[b] = new_d;
                    pq.push(pack(new_d, s, t));
                }
            }
        }
        return INT_MAX;
    }
};