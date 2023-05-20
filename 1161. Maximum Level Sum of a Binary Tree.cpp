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

const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}(); 

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN, max_level = 0, level = 0;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            level++;
            while(size--){
                root = q.front();
                q.pop();
                sum += root->val;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            if(sum > maxSum){
                maxSum = sum;
                max_level = level;
            }
        }
        return max_level;
    }
};
