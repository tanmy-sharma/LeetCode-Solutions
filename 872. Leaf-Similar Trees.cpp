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
    void solve(TreeNode* root, vector <int> &vec){
        if(!root) return;
        solve(root->left, vec);
        if(!root->left && !root->right)
            vec.emplace_back(root->val);
        solve(root->right, vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> vec1, vec2;
        solve(root1, vec1);
        solve(root2, vec2);
        return vec1 == vec2;
    }
};
