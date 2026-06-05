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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;
        f(root,diameter);
        return diameter;
         
    }
    int f(TreeNode*root , int& diameter){
        if(!root) return 0;
        int ld = f(root->left, diameter);
        int rd =f(root->right ,diameter);
        int pathtrav =ld + rd ;
        diameter = max(diameter,pathtrav);
        return 1 + max(ld ,rd);
    }
};
