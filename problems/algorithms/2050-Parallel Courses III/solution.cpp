static const int fast_io =[](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// dynamic programming + breadth first search
// Time complexity = O(N), where N is the number of the nodes in the graph
// Time = 276ms (beats 99.45%), Memory = 131.84MB (beats 74.14%)
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // dp[i] should be the minimum months taken to complet i
        // max(dp[i]) is the answer
        vector<int> dp(time);
        // get the graph
        // Don's use hash table to store the graph here
        // because the insertion of new element is time consuming 
        vector<vector<int>> graph(n,vector<int>{});
        int prev,next,res=0;
        for(int i=0;i<relations.size();i++){
            prev = relations[i][0]-1;
            next = relations[i][1]-1;
            graph[prev].push_back(next);
        }
        // find the root(s)
        // using in degree to help traverse the graph for each edge only once
        // is a common practice
        vector<int> in_deg(n,0);
        for(int i=0;i<relations.size();i++){
            next = relations[i][1]-1;
            in_deg[next]++;
        }
        queue<int> Q;
        for(int i=0;i<n;i++){
            if(!in_deg[i]) Q.push(i);
        }
        while(!Q.empty()){
            // breadth first search
            prev = Q.front();
            Q.pop();
            res = max(res,dp[prev]);// update maximum time
            for(int i=0;i<graph[prev].size();i++){
                next = graph[prev][i];
                in_deg[next]--;
                if(!in_deg[next]) Q.push(next);
                // state transition of dynamic programming
                dp[next] = max(dp[next],time[next]+dp[prev]);
            }
        }
        return res;
    }
};