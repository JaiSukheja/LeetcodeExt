/*Can you solve this real interview question? Recover a Tree From Preorder Traversal - We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.

 

Example 1:

[https://assets.leetcode.com/uploads/2024/09/10/recover_tree_ex1.png]


Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]


Example 2:

[https://assets.leetcode.com/uploads/2024/09/10/recover_tree_ex2.png]


Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]


Example 3:

[https://assets.leetcode.com/uploads/2024/09/10/recover_tree_ex3.png]


Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]


 

Constraints:

 * The number of nodes in the original tree is in the range [1, 1000].
 * 1 <= Node.val <= 109*/


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
    string s;
    int idx = 0, level = 0;

    TreeNode* recoverFromPreorder(string traversal) {
        s = traversal;
        TreeNode* node = new TreeNode(-1);
        helper(node, 0);
        return node->left;
    }

    void helper(TreeNode* parent, int lvl) {
        while (idx < s.length() && lvl == level) {
            int num = 0;
            while (idx < s.length() && isdigit(s[idx])) {
                num = num * 10 + (s[idx++] - '0');
            }
            TreeNode* node = new TreeNode(num);
            if (!parent->left)
                parent->left = node;
            else
                parent->right = node;
            level = 0;
            while (idx < s.length() && s[idx] == '-') {
                level++;
                idx++;
            }
            helper(node, lvl + 1);
        }
    }
};