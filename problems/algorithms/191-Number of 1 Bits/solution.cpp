static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Bit shift
// Time complexity = O(N)
// Time = 0ms (beats 100.00%), Memory = 6.30MB (beats 94.23%)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n){
            if(n%2) res++;
            n>>=1;
        }
        return res;
    }
};