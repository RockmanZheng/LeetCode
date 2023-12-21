const static int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Dynamic programming approach
// Time complexity = O(N)
// Time = 4ms (beats 61.59%)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n];
        dp[n-1]=cost[n-1];
        dp[n-2]=cost[n-2];
        for(int i=n-3;i>=0;i--){
            dp[i] = cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};