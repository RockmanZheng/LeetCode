static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// String distance approach
// Time complexity = O(N)
// Time = 0ms (beats 100.00%)
// Timer = 12:45
class Solution {
public:
    int minOperations(string s) {
        int res = 0,count=0;
        // distance to 010101...
        for(int i=0;i<s.size();i++){
            if(i%2){
                 if(s[i]!= '1') count++;
            }else{
                if(s[i]!='0') count++;
            }
        }
        res = count;
        // distance to 101010...
        count = 0;
        for(int i=0;i<s.size();i++){
            if(i%2){
                 if(s[i]!= '0') count++;
            }else{
                if(s[i]!='1') count++;
            }
        }
        res = min(res,count);
        return res;
    }
};