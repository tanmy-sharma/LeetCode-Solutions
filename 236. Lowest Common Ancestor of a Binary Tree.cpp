// time complexity : 95.15%
// space complexity : 88.5%

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right){
            return root;
        }
        if(left || right){
            return left? left : right;
        }
        return nullptr;
    }
};
