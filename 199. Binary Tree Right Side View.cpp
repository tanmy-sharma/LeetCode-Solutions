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
    void solver(TreeNode *root, vector <int> &ans, int level){
        if(!root) return;
        if(level == ans.size()) ans.emplace_back(root->val);
        solver(root->right, ans, level + 1);
        solver(root->left, ans, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector <int> ans;
        solver(root, ans, 0);
        return ans;
    }
};
