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
 static const int fast_io = [](){
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     return 0;
 }();
 // Recursive approach + reference to save copy/memory allocation overhead
 // Time complexity = O(N), Space complexity = O(N)
// Time = 11ms (beats 82.27%), Memory = 23.73MB (beats 89.04%)
class Solution {
public:

    void tree2str_impl(TreeNode* root,string& res){
        if(root==nullptr) return;
        res+=to_string(root->val);
        if(root->left!=nullptr||root->right!=nullptr){
            res+="(";
            tree2str_impl(root->left,res);
            res+=")";
        }
        if(root->right!=nullptr){
            res+="(";
            tree2str_impl(root->right,res);
            res+=")";
        }
        
    }

    string tree2str(TreeNode* root) {
        string res;
        tree2str_impl(root,res);
        return res;

    }
};