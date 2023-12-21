static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Sort approach
// Time complexity = O(N*log(N)), Space complexity = O(N)
// Time = 40ms (beats 62.00%), Memory = 17.50MB (beats 8.87%)
class Solution {
public:
    bool isVowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
    }
    string sortVowels(string s) {
        int l=0,r=1,n=s.size();
        if(n==1) return s;
        vector<int> buf;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                buf.push_back(s[i]);
            }
        }
        sort(buf.begin(),buf.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                s[i] = buf[j];
                j++;
            }
        }
        return s;
    }
};

static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Frequentist approach
// Time complexity = O(N), Space complexity = O(1)
// Time = 14ms (beats 100.00%), Memory = 12.77MB (beats 60.09%)
class Solution {
public:
    bool isVowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
    }
    
    string sortVowels(string s) {
        vector<int> freq(123,0);
        int n=s.size();
        if(n==1) return s;
        
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                freq[(int)s[i]]++;
            }
        }
        
        int idx=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                while(!freq[idx]) idx++;
                s[i] = (char)idx;
                freq[idx]--;
            }
        }
        return s;
    }
};