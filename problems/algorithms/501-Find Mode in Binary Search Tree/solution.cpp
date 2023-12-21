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
 // Inorder traversal + streak for finding mode in sorted array
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        stack<TreeNode*> visits;
        int curr_streak,max_streak=1,curr_num=-100001;
        auto node = root;
        while(node!=nullptr||!visits.empty()){
            if(node!=nullptr){
                visits.push(node);
                node = node->left;
            }
            else{
                node = visits.top();
                visits.pop();
                if(curr_num<node->val){
                    curr_streak=0;
                }
                curr_streak++;
                curr_num = node->val;
                if(curr_streak==max_streak){
                    modes.push_back(curr_num);
                }
                else if(curr_streak>max_streak){
                    if(modes.size()>1){
                        modes.clear();
                        modes.push_back(curr_num);
                    }
                    max_streak = curr_streak;
                }

                node = node->right;
            }
        }
        return modes;
    }
};