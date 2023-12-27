// Prefix approach
// Time complexity = O(N)
// Time = 0ms (beats 100.00%)
// Timer = 05:29
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            if(s[i]=='0') prefix[i+1] = prefix[i] + 1;
            else prefix[i+1] = prefix[i];
        }
        int res=0;
        for(int i=0;i<n-1;i++){
            res = max(res, prefix[i+1] + (n-i-1)-(prefix[n]-prefix[i+1]));
        }
        return res;
    }
};