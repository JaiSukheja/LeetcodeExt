/*Can you solve this real interview question? Map of Highest Peak - You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

 * If isWater[i][j] == 0, cell (i, j) is a land cell.
 * If isWater[i][j] == 1, cell (i, j) is a water cell.

You must assign each cell a height in a way that follows these rules:

 * The height of each cell must be non-negative.
 * If the cell is a water cell, its height must be 0.
 * Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).

Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

 

Example 1:

[https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-82045-am.png]


Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.


Example 2:

[https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-82050-am.png]


Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.


 

Constraints:

 * m == isWater.length
 * n == isWater[i].length
 * 1 <= m, n <= 1000
 * isWater[i][j] is 0 or 1.
 * There is at least one water cell.

 

Note: This question is the same as 542: https://leetcode.com/problems/01-matrix/ [https://leetcode.com/problems/01-matrix/description/]*/


class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int R = isWater.size();
        int C = isWater[0].size();
        vector<vector<int>> height(R, vector<int>(C, R + C)); // Initialize with a safe sentinel value

        // First pass: set water cells to 0 and propagate height from top-left to bottom-right
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0; // Water cell has height 0
                } else {
                    if (i > 0) 
                        height[i][j] = min(height[i][j], height[i - 1][j] + 1); // Check from top
                    if (j > 0) 
                        height[i][j] = min(height[i][j], height[i][j - 1] + 1); // Check from left
                }
            }
        }

        // Second pass: propagate height from bottom-right to top-left
        for (int i = R - 1; i >= 0; i--) {
            for (int j = C - 1; j >= 0; j--) {
                if (i < R - 1) 
                    height[i][j] = min(height[i][j], height[i + 1][j] + 1); // Check from bottom
                if (j < C - 1) 
                    height[i][j] = min(height[i][j], height[i][j + 1] + 1); // Check from right
            }
        }

        return height;
    }
};