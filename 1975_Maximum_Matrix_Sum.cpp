/*Can you solve this real interview question? Maximum Matrix Sum - You are given an n x n integer matrix. You can do the following operation any number of times:

 * Choose any two adjacent elements of matrix and multiply each of them by -1.

Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

 

Example 1:

[https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex1.png]


Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.


Example 2:

[https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex2.png]


Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.


 

Constraints:

 * n == matrix.length == matrix[i].length
 * 2 <= n <= 250
 * -105 <= matrix[i][j] <= 105*/


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        long long sum=0;
        int targetNum = INT_MAX,count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<=0){
                    count++;
                    sum += matrix[i][j]*(-1);
                }
                else{
                    sum+=matrix[i][j];
                }
                targetNum = min(targetNum,abs(matrix[i][j]));
            }
        }
        return count%2 ? sum - 2*targetNum : sum;
    }
};