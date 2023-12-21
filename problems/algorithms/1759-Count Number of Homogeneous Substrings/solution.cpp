static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// two pointer approach
// Time complexity = O(N), Space Complexity = O(1)
// Time = 13ms (beats 99.35%), Memory = 12.14MB (beats 33.48%)
class Solution {
public:
    int countHomogenous(string s) {
        int m = s.size();
        long res = 0;
        int N = 1e9+7;
        int l=0,r=0;
        long n;
        while(l<m){
            while(r<m && s[r]==s[l]) r++;
            n = r-l;
            res = (res+n*(n+1)/2)%N;
            l = r;
        }
        return res;
    }
};