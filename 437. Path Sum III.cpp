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
    void solve(TreeNode* root, int &count, vector <int> &path, const int &target, long long sum = 0){
        if(!root) return;

        path.emplace_back(root->val);

        for(int i = path.size() - 1 ; i >= 0 ; --i){
            sum += path[i];
            if(sum == target) ++count;
        }
        solve(root->left, count, path, target);
        solve(root->right, count, path, target);

        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int count = 0;
        vector <int> path;
        solve(root, count, path, targetSum);
        return count;
    }
};
