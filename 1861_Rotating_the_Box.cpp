/*Can you solve this real interview question? Rotating the Box - You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:

 * A stone '#'
 * A stationary obstacle '*'
 * Empty '.'

The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

 

Example 1:

[https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcodewithstones.png]


Input: boxGrid = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]


Example 2:

[https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode2withstones.png]


Input: boxGrid = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]


Example 3:

[https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode3withstone.png]


Input: boxGrid = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]


 

Constraints:

 * m == boxGrid.length
 * n == boxGrid[i].length
 * 1 <= m, n <= 500
 * boxGrid[i][j] is either '#', '*', or '.'.*/


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> transposed(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                transposed[i][j] = box[j][i];
            }
        }
        for(vector<char>& row:transposed){
            reverse(begin(row),end(row));
        }

        for(int j=0;j<m;j++){
            int space = n-1;
            for(int i=n-1;i>=0;i--){
                if(transposed[i][j]=='*'){
                    space=i-1;
                    continue;
                }
                if(transposed[i][j] == '#'){
                    transposed[i][j] = '.';
                    transposed[space][j] = '#';
                    space--;
                }
            }
        }
        
        return transposed;
    }
};