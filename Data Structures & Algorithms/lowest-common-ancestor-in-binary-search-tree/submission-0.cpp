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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return 0 ;
        if(root == p) return root;
        if(root == q)return root;

        TreeNode*leftlca = lowestCommonAncestor(root->left , p ,q );
        TreeNode*rightlca = lowestCommonAncestor(root->right , p ,q);

        if(leftlca != nullptr && rightlca != nullptr)return root;
        if(leftlca!= nullptr) return leftlca;
        if(rightlca!= nullptr) return rightlca ;

        return nullptr;
        
    }
};
