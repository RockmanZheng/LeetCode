static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Two stack approach: Time = 11ms (beats 99.25%), Memory = 10.81MB (beats 27.15%)
// Time complexity = O(N), Space complexity = O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int zero_count=0,one_count=0,res=0;
        if(s[0]=='0') zero_count++;
        else one_count++;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'){
                if(s[i-1]=='1') zero_count=1;
                else zero_count++;
                if(one_count>0){
                    res++;
                    one_count--;
                }
            }
            else if(s[i]=='1'){
                if(s[i-1]=='0') one_count=1;
                else one_count++;
                if(zero_count>0){
                    res++;
                    zero_count--;
                }
            }
        }
        return res;
    }
};