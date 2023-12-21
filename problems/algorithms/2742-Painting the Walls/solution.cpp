static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Dynamic programming approach + knapsack problem
// Time complexity = O(N*T), where T is the sum of the time array
// TLE error
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // Since using dynamic programming approach to solve the knapsack problem
        // requires space complexity proportional to the total cost
        // And in the problem constraint the maximal cost is 1e6
        // while the maximum time is only 500
        // So to limit the space complexity, we use the time as the cost

        // get total time first
        // time complexity = O(N)
        int T=0,C=0;
        int n=time.size();
        for(int i=0;i<n;i++){
            T+=time[i];
            C+=cost[i];
        }
        
        // Suppose all walls are painted by the paid workers first
        // the time cost is T
        // Suppose now that we let the free worker to paint m walls
        // with the original total time cost t
        // Then in order for the plan to be feasible, we need to ensure
        // T>=m+t
        // This essentially is equivalent to a constraint in the knapsack 
        // problem where the cost of item i is t[i]+1
        // The goal is to maximize the costs cut subject to this constraint
        // Let V[i,T] represent the maximum costs cut possible when considering
        // only the first i walls and given the total time cost T
        // Then, we have
        // V[0,T]=0
        // V[i,T]=V[i-1,T] if t[i]+1>T
        // because when there is only one wall, we have to let the paid painter do it
        // And
        // V[i,T]=max(V[i-1,T],V[i-1,T-t[i]-1]+c[i])
        vector<vector<int>> V(n+1,vector<int>(T+1,-1));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=T;j++){
                if(time[i-1]+1>j) V[i][j]=V[i-1][j];
                else{
                    V[i][j]=max(V[i-1][j],V[i-1][j-time[i-1]-1]+cost[i-1]);
                }
            }
        }

        return C-V[n][T];
    }
};
// Dynamic programming approach - More efficient
// Time complexity = O(N^2)
// Time = 88ms (beats 95.16%), Memory = 89.67MB (beats 91.42%)
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // dp[j] represents the minimum cost of painting j walls
        int n=cost.size();
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){// if wall i is painted by the paid worker
            for(int j=n;j>=0;j--){
                // if wall i is painted by the paid worker
                // then the free worker can paint time[i] walls when the paid worker is occupied at no cost
                // So effectively, we have only j-time[i]-1 walls to paint
                dp[j] = min(dp[j],dp[max(0,j-time[i]-1)]+cost[i]);
                // using a backward dynamic programming in the inner loop
                // we can make use of the dp value under the cases where the paid worker
                // is not available to paint wall i
                // Naturally, when the paid worker is not available to paint any wall
                // the cost is infinite because the free worker can only paint walls
                // when the paid worker is occupied
                // As the outer loop iterates from 0 to n-1
                // We are gradually increasing the availability of the paid worker
                // so that the minimum cost is improved in the inner loop

                // To make the idea easier to understand, there is a dynamic programming 
                // matrix dp[i][j], where
                // dp[i][j] represents the minimum cost when we have to paint j walls
                // and the paid worker is only available to paint walls from 1 to i
                // The state transition equation is
                // dp[i][j] = min(dp[i-1][j],dp[i-1][max(0,j-time[i]-1)]+cost[i]) 
                // Here, the equation is obtained by choosing between whether or not
                // we let the paid worker to paint wall i
                // If the paid worker does not work on wall i, then it is the same case
                // as the paid worker is not available to work on wall i,
                // so the minimum cost of painting j walls is dp[i-1][j]
                // If the paid worker works on wall i, then only j-time[i]-1 needs to be painted
                // with costs by allocating the paid worker to work on the first i-1 walls
                // so the cost is dp[i-1][max(0,j-time[i]-1)]+cost[i]
                // Since the state transition is only related to i-1
                // We can speed up the program by a single vector dp[j] and use nested loops
                // to solve the problem
            }
        }
        return dp[n];
    }
};