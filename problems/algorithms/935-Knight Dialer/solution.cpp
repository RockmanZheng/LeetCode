static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Dynamic programming approach + symmetry
// Time complexity = O(N)
// Time = 31ms (beats 88.74%), Memory = 37.34MB (beats 46.20%)
class Solution {
public:
    int knightDialer(int n) {
        int N = 1000000007;
        vector<vector<long>> dp(10,vector<long>(n,0));
        for(int i=0;i<10;i++) dp[i][0]=1;
        for(int j=1;j<n;j++){
            dp[0][j] = (2*dp[4][j-1])%N;
            dp[1][j] = (dp[8][j-1]+dp[4][j-1])%N;
            dp[2][j] = (2*dp[7][j-1])%N;
            //dp[3][j] = dp[1][j];
            dp[4][j] = (dp[0][j-1]+dp[1][j-1]+dp[7][j-1])%N;
            //dp[6][j] = dp[4][j];
            dp[7][j] = (dp[2][j-1]+dp[4][j-1])%N;
            dp[8][j] = (2*dp[1][j-1])%N;
            //dp[9][j] = dp[7][j];
        }
        long res = 0;
        res= (res + dp[0][n-1]+2*dp[1][n-1])%N;
        res= (res + dp[2][n-1]+2*dp[4][n-1])%N;
        res= (res + dp[5][n-1]+2*dp[7][n-1])%N;
        res= (res + dp[8][n-1])%N;
        return res;
    }
};