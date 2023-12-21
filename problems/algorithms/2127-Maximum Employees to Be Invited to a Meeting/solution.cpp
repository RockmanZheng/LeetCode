static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

// Topological sort
// Topological sort automatically leaves cycles behind
// Time complexity = O(N)
// Time = 86ms (beats 99.05%), Memory = 89.27MB (beats 91.89%)
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indeg(n,0);// in-degree of each node
        queue<int> Q;// queue for topological sort
        vector<int> dp(n,1);// dp[i] is the depth at node i
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++) indeg[favorite[i]]++;
        for(int i=0;i<n;i++){
            if(!indeg[i]){
                Q.push(i);
            }
        }
        // topological sort
        while(!Q.empty()){
            int i = Q.front();
            Q.pop();
            indeg[favorite[i]]--;
            visited[i]=true;
            dp[favorite[i]] = max(dp[i]+1,dp[favorite[i]]);
            if(!visited[favorite[i]] && indeg[favorite[i]]==0) Q.push(favorite[i]);
        }
        // only loops are left
        int res1 = 0,res2=0;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            if(favorite[favorite[i]]==i){
                res1 += dp[i]+dp[favorite[i]];// any subgraph with 2 interdependent persons can be added to the meeting as long as they are bigger than loop with over 3 persons
                visited[i]=true;
                visited[favorite[i]]=true;
            }
            else{
                int count=0,j=i;
                while(!visited[j]){
                    count++;
                    visited[j] = true;
                    j = favorite[j];
                }
                res2 = max(res2,count);
            }
        }

        return max(res1,res2);
    }
};