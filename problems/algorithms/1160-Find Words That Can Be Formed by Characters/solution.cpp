static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Hashmap approach
// Time complexity = O(N)
// Time = 67ms (beats 54.67%), Memory = 27.89MB (beats 46.56%)
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> budget;
        for(char c : chars){
            if(!budget.count(c)) budget[c]=1;
            else budget[c]++;
        }
        int res=0;
        bool flag;
        for(string word : words){
            unordered_map<char,int> cost;
            flag=true;
            for(char c: word){
                if(!budget.count(c)){
                    flag=false;
                    break;
                }
                if(!cost.count(c)) cost[c]=1;
                else cost[c]++;
                if(cost[c]>budget[c]){
                    flag=false;
                    break;
                }
            }
            if(flag) res+=word.size();
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
// Vector approach
// Time complexity = O(N)
// Time = 28ms (beats 99.69%), Memory = 23.14MB (beats 51.61%)
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> budget(26,0);
        for(char c : chars){
            budget[c-'a']++;
        }
        int res=0;
        bool flag;
        for(string word : words){
            vector<int> cost(26,0);
            flag=true;
            for(char c: word){
                if(!budget[c-'a']){
                    flag=false;
                    break;
                }
                cost[c-'a']++;
                if(cost[c-'a']>budget[c-'a']){
                    flag=false;
                    break;
                }
            }
            if(flag) res+=word.size();
        }
        return res;
    }
};