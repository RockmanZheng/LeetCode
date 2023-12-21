static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
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
 // Breadth first search + max heap
 // Time complexity = O(N)
 // Time = 4ms (beats 91.88%), Memory = 23.02MB (beats 6.87%)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> bfs;
        vector<int> res;
        if(root!=nullptr) bfs.push(root);
        while(!bfs.empty()){
            priority_queue<int> max_heap;
            int n = bfs.size();
            for(int i=0;i<n;i++){
                auto node = bfs.front();
                bfs.pop();
                max_heap.push(node->val);
                if(node->left != nullptr) bfs.push(node->left);
                if(node->right != nullptr) bfs.push(node->right);
            }
            res.push_back(max_heap.top());
        }
        return res;
    }
};

static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
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
 // Breadth first search (no need for max heap)
 // Time = 0ms (beats 100.00%)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> bfs;
        vector<int> res;
        if(root!=nullptr) bfs.push(root);
        while(!bfs.empty()){
            int max_val=INT_MIN;
            int n = bfs.size();
            for(int i=0;i<n;i++){
                auto node = bfs.front();
                bfs.pop();
                max_val = max(max_val,node->val);
                if(node->left != nullptr) bfs.push(node->left);
                if(node->right != nullptr) bfs.push(node->right);
            }
            res.push_back(max_val);
        }
        return res;
    }
};