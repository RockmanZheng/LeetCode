static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Pointer approach
// Time complexity = O(N)
// Time = 0ms (beats 100.00%), Memory = 6.90MB (beats 31.59%)
class Solution {
public:
    string largestGoodInteger(string num) {
        int l=0,m=1,r=2;
        int record=-1;
        while(r<num.size()){
            if(num[l]==num[m] && num[m]==num[r]){
                int tmp = num[l]-'0';
                record = max(tmp,record);
            }
            l=m;
            m=r;
            r++;
        }
        if(record<0) return "";
        string res(3,(char)('0'+record));
        return res;
    }
};