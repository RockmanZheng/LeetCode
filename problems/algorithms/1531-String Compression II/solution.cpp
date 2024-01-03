// Recursive + memoization
// Time complexity = O(2^N)
// TLE
class Solution {
public:
    int runLengthEncoding(string s){
        int n = s.size();
        if(n==0) return 0;
        int count = 1;
        char letter = s[0];
        int l = 1;
        for(int i=1;i<n;i++){
            if(s[i]==letter) count++;
            else{
                l++;
                if(count>1){
                    l+=to_string(count).size();
                    count=1;
                }
                letter = s[i];
            }

        }
        if(count>1){
            l+=to_string(count).size();
        }

        return l;
    }
    int internal_impl(string s, int k, vector<unordered_map<string,int>>& dp){
        if(dp[k].contains(s)) return dp[k][s];
        if(k==0){
            int l = runLengthEncoding(s);
            dp[k][s] = l;
            return l;
        }
        int n = s.size();
        int min_len = n+1;
        for(int i=0;i<n;i++){
            // delete s[i]
            string ss;
            if(i==0) ss = s.substr(1,n-1);
            else if(i==n-1) ss = s.substr(0,n-1);
            else ss = s.substr(0,i) + s.substr(i+1,n-i-1);
            int l = internal_impl(ss,k-1,dp);
            if(l<min_len) min_len = l;
        }
        dp[k][s] = min_len;
        return min_len;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        // dp[k][s] is the minimum length we get after deleting k chars from s and after compression
        vector<unordered_map<string,int>> dp(k+1,unordered_map<string,int>());
        return internal_impl(s,k,dp);
    }
};

static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Dynamic programming
// Time complexity = O(N^2*K)
// Time = 70ms (beats 65.76%)
class Solution {
public:

    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        int dp[n+1][k+1];// dp[i][j] is the minimum length of the substring containing the first i characters after deleting at most j elements of it
        for(int j=0;j<=k;j++) dp[0][j]=0;// base case
        for(int i=1;i<=n;i++){// for each substring
            for(int j=0;j<=k;j++){
                if(j) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = INT_MAX;
                int count = 0, n_delete = 0;
                for(int l=i;l>=1;l--){
                    if(s[i-1]==s[l-1]) count++;
                    else n_delete++;
                    if(j>=n_delete){
                        if(count==1) dp[i][j] = min(dp[i][j],dp[l-1][j-n_delete]+1);
                        else if(count<10) dp[i][j] = min(dp[i][j],dp[l-1][j-n_delete]+2);
                        else if(count<100) dp[i][j] = min(dp[i][j],dp[l-1][j-n_delete]+3);
                        else dp[i][j] = min(dp[i][j],dp[l-1][j-n_delete]+4);
                    }
                }
            }
        }
        return dp[n][k];
    }

};