static const int fast_io=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

/* Dynamic programing approach: Time = 163ms (beats 40.28%) Memory = 23.32MB (beats 31.82%) */
class Solution {
public:
    string longestPalindrome(string s) {
        int max_len=1;
        
        int start = 0;
        std::vector<std::vector<bool>> M(s.size(),std::vector<bool>(s.size(),false));
        for(int i=0;i<s.size();i++){
            M[0][i] = true;
        }
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == s[i+1]){
                M[1][i] = true;
                max_len=2;
                start = i;
            }
        }
        for(int d=2;d<s.size();d++){
            for(int i=0;i<s.size()-d;i++){
                if (s[i]==s[i+d] && M[d-2][i+1]){
                    // checking s[i]==s[i+d] before M[d-2][i+1] is very important to save time (315ms -> 163ms)
                    // because evaluating M[d-2][i+1] involves two arithmetic calculations
                    // while s[i]==s[i+d] only involves one
                    M[d][i] = true;
                    max_len=d+1;
                    start = i;
                }
            }
        }
        return s.substr(start,max_len);
    }
};
/* Central expansion approach: Time = 7ms (beats 94.78%) Memory = 7.24MB (beats 74.96%) */
class Solution {
public:
    int expand(string& s, int l, int r){// The input type string& is important to save time and space
        while(l>=0 && r<s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int final_len=1;
        int center = 0;
        string max_pa=s.substr(0,1);
        int l=0,r=0;
        for(int i=0;i<s.size();i++){
            int max_odd_len = expand(s,i,i);
            int max_even_len = expand(s,i,i+1);
            int max_len = max(max_odd_len,max_even_len);
            if(max_len>final_len){
                final_len = max_len;
                center = i;
            }
        }
        if(final_len%2==0){
            max_pa = s.substr(center-final_len/2+1,final_len);
        }
        else{
            max_pa = s.substr(center-final_len/2,final_len);
        }
        return max_pa;
    }
};