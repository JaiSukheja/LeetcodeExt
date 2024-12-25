/*Can you solve this real interview question? Find Largest Value in Each Tree Row - Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

Example 1:

[https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg]


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]


Example 2:


Input: root = [1,2,3]
Output: [1,3]


 

Constraints:

 * The number of nodes in the tree will be in the range [0, 104].
 * -231 <= Node.val <= 231 - 1*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(vector<int> &v,TreeNode* root, int level){
        if(!root){
            return;
        }
        if(v.size() > level){
            v[level] = max(v[level],root->val);
        }
        else{
            v.push_back(root->val);
        }
        solve(v,root->left,level+1);
        solve(v,root->right,level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>v;
        solve(v,root,0);
        return v;
    }
};