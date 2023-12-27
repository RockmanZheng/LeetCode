static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// recursive + memoization
// Time complexity = O(n*target)
// Time = 3ms (beats 99.67%)
// Timer = 35:00
class Solution {
public:
    int N = 1000000007;
    long nrolls(int n, int k, int target, vector<vector<int>>& dp){
        if(dp[n][target]>=0) return dp[n][target];
        if(n==1 && target <= k){
            dp[n][target] = 1;
            return 1;
        }
        if(n*k<target){
            dp[n][target] = 0;
            return 0;
        }
        long res = 0;
        for(int i=1;i<=k;i++){
            if(target>i) res = (res + nrolls(n-1,k,target-i,dp)) % N;
        }
        dp[n][target] = res;
        return res;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return nrolls(n,k,target,dp);

    }
};