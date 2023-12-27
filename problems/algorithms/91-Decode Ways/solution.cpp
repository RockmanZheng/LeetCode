// Recursive approach
// Time complexity = O(N): The bisect takes O(log(N)), but taking substring takes O(N)
// Time = 0ms(beats 100.00%)
// Timer = 42:54
class Solution {
public:
    int numDecodings(string s) {
        // 0 can only be grouped into 10 or 20
        if(s[0]=='0') return 0;
        if(s.size()==1) return 1;
        if(s.size()==2){
            if(s[0]=='1'){
                if(s[1]=='0') return 1;
                else return 2;
            }
            else if(s[0]=='2'){
                if(s[1]=='0') return 1;
                else if(s[1]<='6') return 2;
                else return 1;
            }
            else{
                if(s[1]=='0') return 0;
                else return 1;
            }
        }
        int n = s.size();
        // find a valid mid point such that
        // s[0:mid] and s[mid:end] both have nonzero ways of decode
        int mid = n/2;
        int res=0;
        res += numDecodings(s.substr(0,mid))*numDecodings(s.substr(mid,n-mid));
        if(s[mid-1]=='0') return res;
        if(s[mid-1]>'2') return res;
        if(s[mid-1]=='2' && s[mid]>'6') return res;
        
        if(mid>1){
            res += numDecodings(s.substr(0,mid-1))*numDecodings(s.substr(mid+1,n-mid-1));
        }
        else{
            res += numDecodings(s.substr(2,n-2));
        }
        
        return res;
        
    }
};