static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Prefix approach
// Time complexity = O(N^2)
// TLE
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        long N = 1000000007;
        long prefix_min,prefix_sum,res=0;
        int n = strength.size();
        for(int i=0;i<n;i++){
            prefix_min = strength[i];
            prefix_sum = strength[i];
            res = (res + prefix_min * prefix_sum) % N;
            for(int j=i+1;j<n;j++){
                prefix_min = prefix_min<strength[j]?prefix_min:strength[j];
                prefix_sum = (prefix_sum + strength[j]) % N;
                res = (res + prefix_min * prefix_sum) % N;
            }
        }
        return res;
    }
};
static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Prefix approach
// Time complexity = O(N)
// Monotonic stack + double prefix sum approach
// Time = 150ms (beats 95.00%)
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        long N = 1000000007;
        long res=0;
        int n = strength.size();
        vector<int> left(n,-1), right(n,-1);
        vector<long> prefix(n+1,0), preprefix(n+2,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = (prefix[i] + strength[i]) % N;
        }
        for(int i=0;i<=n;i++){
            preprefix[i+1] = (preprefix[i] + prefix[i]) % N;
        }
        stack<int> S;
        for(int i=0;i<n;i++){
            while(!S.empty() && strength[S.top()] >= strength[i]){
                S.pop();
            }
            left[i] = S.empty()?-1:S.top();
            S.push(i);
        }
        stack<int> T;
        for(int i=n-1;i>=0;i--){
            while(!T.empty() && strength[T.top()] > strength[i]){
                T.pop();
            }
            right[i] = T.empty()?n:T.top();
            T.push(i);
        }
        
        for(int i=0;i<n;i++){
            long tmp = (((preprefix[right[i]+1]-preprefix[i+1])*(i-left[i]))%N+N*2-((preprefix[i+1]-preprefix[left[i]+1])*(right[i]-i))%N)%N;
            res = (res + strength[i] * tmp) % N;
        }
        return res;
    }
};