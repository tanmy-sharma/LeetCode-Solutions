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
    void inorder(TreeNode *root, int maxEle, int &count){
        if(!root) return;
        if(maxEle <= root->val)
            count++;
        maxEle = max(maxEle, root->val);
        inorder(root->left, maxEle, count);
        inorder(root->right, maxEle, count);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count = 0;
        inorder(root, root->val, count);
        return count;
    }
};1448. Count Good Nodes in Binary Tree
