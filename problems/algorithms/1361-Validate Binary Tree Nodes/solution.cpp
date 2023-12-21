static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Bread first search approach
// Time Complexity = O(N), Space Complexity = O(N)
// Time = 30ms (beats 89.59%), Memory = 32.20MB (beats 97.16%)
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> is_root(n,true);
        vector<bool> visited(n,false);
        stack<int> visit_schedule;
        // first find the root, which does not have parent
        
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1) is_root[leftChild[i]]=false;
            if(rightChild[i]!=-1) is_root[rightChild[i]]=false;
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(is_root[i]){
                root=i;
                break;
            }
        }
        if(root==-1) return false;// There is no root in the graph, hence not a tree
        visit_schedule.push(root);
        
        while(!visit_schedule.empty()){
            int node = visit_schedule.top();
            visit_schedule.pop();
            if(visited[node]) return false;// this node has already been visited, hence not a tree
            visited[node]=true;
            if(rightChild[node]!=-1) visit_schedule.push(rightChild[node]);
            if(leftChild[node]!=-1) visit_schedule.push(leftChild[node]);
        }
        // check if there is unvisited node, if so the graph is not connected, hence not a tree
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        // otherwise, since each node has at most two children, we have a binary tree
        return true;
    }
};

