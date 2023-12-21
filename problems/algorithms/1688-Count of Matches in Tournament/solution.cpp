static const int fast_io=[](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Time = 0ms (beats 100ms), Memory = 6.27MB (Beats 73.09%)
class Solution {
public:
    int numberOfMatches(int n) {
        int res=0;
        while(n>1){
            res+=n/2;
            if(n%2) n=(n+1)/2;
            else n/=2;
        }
        return res;
    }
};