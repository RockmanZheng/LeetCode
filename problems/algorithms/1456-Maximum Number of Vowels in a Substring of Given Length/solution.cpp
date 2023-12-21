static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int maxVowels(string s, int k) {
        int max_vow=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                max_vow++;
            }
        }
        int count=max_vow;
        for(int i=1;i<s.size()-k+1;i++){
            if(s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='o'||s[i-1]=='u'){
                count--;
            }
            if(s[i+k-1]=='a'||s[i+k-1]=='e'||s[i+k-1]=='i'||s[i+k-1]=='o'||s[i+k-1]=='u'){
                count++;
            }
            max_vow = count>max_vow ? count : max_vow;
        }
        return max_vow;
    }
};