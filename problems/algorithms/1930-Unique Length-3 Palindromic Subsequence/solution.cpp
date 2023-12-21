static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// hashmap + check for sides of palindrome
// Time complexity = O(N^2)
// Time = 200ms (beats 84.93%), Memory = 29.94MB (beats 18.04%)
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(),res=0;
        unordered_map<char,vector<int>> records;// record['a'] is the list of locations of char a
        for(int i=0;i<n;i++) records[s[i]].push_back(i);
        for(auto &tmp : records){
            auto record = tmp.second;
            if(record.size()>=2 && record.front()+1<record.back()){// if there are more than 2 char and they are disjoint
                unordered_map<char,bool> checkbox;
                for(int i=record.front()+1;i<record.back();i++){
                    if(!checkbox.count(s[i])) checkbox[s[i]]=true;
                }
                res += checkbox.size();
            }
        }

        return res;
    }
};

// char-to-int + array + check for sides of palindrome
// Time complexity = O(N^2)
// Time = 172ms (beats 86.53%), Memory = 23.38MB (beats 20.32%)
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(),res=0;
        vector<int> records['z'+1];// record[c-'a'] is the list of locations of char c
        for(int i=0;i<n;i++) records[s[i]].push_back(i);
        for(auto &record : records){
            if(record.size()>=2 && record.front()+1<record.back()){// if there are more than 2 char and they are disjoint
                vector<bool> checkbox('z'+1,false);
                for(int i=record.front()+1;i<record.back();i++){
                    if(!checkbox[s[i]]){
                        checkbox[s[i]]=true;
                        res++;
                    }
                }
            }
        }

        return res;
    }
};

static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// char-to-int + array + check for sides of palindrome
// Time complexity = O(N^2)
// Time = 27ms (beats 98.40%), Memory = 11.68MB (beats 91.78%)
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(),res=0;
        vector<int> start('z'+1,-1),end('z'+1,-1);// record[c-'a'] is the list of locations of char c
        for(int i=0;i<n;i++){
            if(start[s[i]]==-1) start[s[i]]=i;
            else end[s[i]] = i;
        }
        for(int i='a';i<='z';i++){
            if(start[i]+1<end[i]){// if there are more than 2 char and they are disjoint
                vector<bool> checkbox('z'+1,false);
                int tmp=0;
                for(int j=start[i]+1;j<end[i];j++){
                    if(!checkbox[s[j]]){
                        checkbox[s[j]]=true;
                        tmp++;
                    }
                    if(tmp==26) break;// break early to save more time when we already loop through the whole alphabet
                }
                res += tmp;
            }
        }

        return res;
    }
};