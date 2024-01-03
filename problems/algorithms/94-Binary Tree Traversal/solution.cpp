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
 // Recursive approach
 // Time complexity = O(N), space complexity = O(N)
 // Time = 0ms (beats 100.00%), memory = 8.60MB (beats 97.89%)
class Solution {
public:

    void inorderTraversal_impl(TreeNode* root, vector<int>& res){
        if(root==nullptr) return;
        inorderTraversal_impl(root->left,res);
        res.push_back(root->val);
        inorderTraversal_impl(root->right,res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversal_impl(root,res);
        return res;
    }
};