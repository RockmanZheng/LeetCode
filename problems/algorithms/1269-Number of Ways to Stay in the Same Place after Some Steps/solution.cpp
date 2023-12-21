
// Dynamic programming approach 1
// Time complexity O(steps^2), space complexity O(steps)
// Time = 15ms (beats 70.28%), memory = 6.74MB (beats 91.97%)
class Solution {
public:
    int numWays(int steps, int arrLen) {
        // dp[i][j] represents the number of ways starting from i
        // in exactly j steps, return to 0
        // The answer will be dp[0][steps]
        // the base case is dp[i][i]=1, there is only one way for a pointer
        // starting from i to return 0 in i steps
        // And dp[i][j]=0 for j<i, never return
        // the bellman equation is
        // dp[i][j] = dp[i-1][j-1]+dp[i+1][j-1]+dp[i][j-1]
        // each term corresponding to left, right, and stay
        //
        // Since the rhs of the transition equation is dependent on
        // only j-1
        // we can use two vector dp1[i] and dp2[i] and use a double loop
        // to save some memory
        // furthermore, since dp[i]=0 for i>steps, we can just discard them to further save memory
        int N=1e9+7;
        if(steps+1>=arrLen){
            vector<int> dp1(arrLen,0),dp2(arrLen,0);
            dp1[0]=1;
            for(int j=1;j<=steps;j++){
                if(j%2){
                    if(arrLen>=2){
                        dp2[arrLen-1]=(dp1[arrLen-2]+dp1[arrLen-1])%N;
                        dp2[0]=(dp1[0]+dp1[1])%N;
                    }
                    else dp2[0]=dp1[0];
                    for(int i=1;i<arrLen-1;i++){
                        dp2[i]=((dp1[i-1]+dp1[i+1])%N+dp1[i])%N;
                    }
                }
                else{
                    if(arrLen>=2){
                        dp1[arrLen-1]=(dp2[arrLen-2]+dp2[arrLen-1])%N;
                        dp1[0]=(dp2[0]+dp2[1])%N;
                    }
                    else dp1[0]=dp2[0];
                    
                    for(int i=1;i<arrLen-1;i++){
                        dp1[i]=((dp2[i-1]+dp2[i+1])%N+dp2[i])%N;
                    }
                }
            }
            if(steps%2) return dp2[0];
            else return dp1[0];
        }
        else{
            vector<int> dp1(steps+1,0),dp2(steps+1,0);
            dp1[0]=1;
            for(int j=1;j<=steps;j++){
                if(j%2){
                    
                    dp2[steps]=(dp1[steps-1]+dp1[steps])%N;
                    dp2[0]=(dp1[0]+dp1[1])%N;
                    for(int i=1;i<steps;i++){
                        dp2[i]=((dp1[i-1]+dp1[i+1])%N+dp1[i])%N;
                    }
                }
                else{
                    dp1[steps]=(dp2[steps-1]+dp2[steps])%N;
                    dp1[0]=(dp2[0]+dp2[1])%N;
                    for(int i=1;i<steps;i++){
                        dp1[i]=((dp2[i-1]+dp2[i+1])%N+dp2[i])%N;
                    }
                }
            }
            if(steps%2) return dp2[0];
            else return dp1[0];
        }

    }
};