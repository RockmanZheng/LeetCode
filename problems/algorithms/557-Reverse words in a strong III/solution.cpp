static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    string reverseWords(string s) {
        int l=0,r=0;
        while(l<s.size()){
            while(r<s.size() && s[r]!=' ') r++;
            std::reverse(s.begin()+l,s.begin()+r);
            l=r+1;
            r=l;
        }
        return s;
    }
};