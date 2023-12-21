static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Direct dynamic programming approach.
// Time complexity = O(n*m^2*k), Space complexity = O(n*m*k)
// Time = 215ms (beats 17.97%), Memory = 10.03MB (beats 34.56%)
class Solution {
public:
    int N = 1e9+7;
    
    int numOfArrays(int n, int m, int k) {
        if(k>m) return 0;
        if(n==1) return m;
        // dp[len][mx][cost] number of arrays with length len+1, the maximum exactly equal mx+1,
        // and search cost cost+1
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,0)));
        for(int mx=0;mx<m;mx++){
            dp[0][mx][0]=1;
        }

        for(int len=1;len<n;len++){
            for(int mx=0;mx<m;mx++){
                for(int cost=0;cost<k;cost++){
                    dp[len][mx][cost] = (1LL*dp[len-1][mx][cost]*(mx+1))%N;
                    if(cost>0){
                        for(int v=0;v<mx;v++){
                            dp[len][mx][cost] = (1LL*dp[len][mx][cost]+dp[len-1][v][cost-1])%N;
                        }
                    }
                }
            }
        }

        int res=0;
        for(int v=k-1;v<m;v++){
            res = (res + dp[n-1][v][k-1])%N;
        }

        return res;
    }
};
// Dynamic programming approach + optimized with Prefix sum trick.
// Time complexity = O(n*m*k), Space complexity = O(n*m*k)
// Time = 21ms (beats 85.71%), Memory = 12.91MB (beats 6.91%)
class Solution {
public:
    int N = 1e9+7;
    
    int numOfArrays(int n, int m, int k) {
        if(k>m) return 0;
        if(n==1) return m;
        // dp[len][mx][cost] number of arrays with length len+1, the maximum exactly equal mx+1,
        // and search cost cost+1
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,0)));
        vector<vector<vector<int>>> pre(n,vector<vector<int>>(m,vector<int>(k,0)));

        for(int mx=0;mx<m;mx++){
            dp[0][mx][0]=1;
            pre[0][mx][0]=mx+1;
        }
        for(int len=0;len<n;len++){
            dp[len][0][0]=1;
            pre[len][0][0]=1;
        }

        for(int len=1;len<n;len++){
            for(int mx=1;mx<m;mx++){
                dp[len][mx][0] = (1LL*dp[len-1][mx][0]*(mx+1))%N;
                pre[len][mx][0] = (pre[len][mx-1][0] + dp[len][mx][0]) % N;
                for(int cost=1;cost<k;cost++){
                    dp[len][mx][cost] = (1LL*dp[len-1][mx][cost]*(mx+1))%N;
                    dp[len][mx][cost] = (dp[len][mx][cost]+pre[len-1][mx-1][cost-1]) % N;
                    pre[len][mx][cost] = (pre[len][mx-1][cost] + dp[len][mx][cost]) % N;
                }
            }
        }
        return pre[n-1][m-1][k-1];
    }
};