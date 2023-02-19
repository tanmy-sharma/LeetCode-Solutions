// time : 7 %
// space : 88 %
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

//time : 100 %
//space : 47 %
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        TreeNode* const left = root->left;
        TreeNode* const right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};
