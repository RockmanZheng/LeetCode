// Recursive + memoization
// Time complexity = O(N^k)
// TLE
class Solution {
public:
    int runLengthEncoding(string s){
        int n = s.size();
        if(n==0) return 0;
        int count = 1;
        char letter = s[0];
        int l = 1;
        for(int i=1;i<n;i++){
            if(s[i]==letter) count++;
            else{
                l++;
                if(count>1){
                    l+=to_string(count).size();
                    count=1;
                }
                letter = s[i];
            }

        }
        if(count>1){
            l+=to_string(count).size();
        }

        return l;
    }
    int internal_impl(string s, int k, vector<unordered_map<string,int>>& dp){
        if(dp[k].contains(s)) return dp[k][s];
        if(k==0){
            int l = runLengthEncoding(s);
            dp[k][s] = l;
            return l;
        }
        int n = s.size();
        int min_len = n+1;
        for(int i=0;i<n;i++){
            // delete s[i]
            string ss;
            if(i==0) ss = s.substr(1,n-1);
            else if(i==n-1) ss = s.substr(0,n-1);
            else ss = s.substr(0,i) + s.substr(i+1,n-i-1);
            int l = internal_impl(ss,k-1,dp);
            if(l<min_len) min_len = l;
        }
        dp[k][s] = min_len;
        return min_len;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        // dp[k][s] is the minimum length we get after deleting k chars from s and after compression
        vector<unordered_map<string,int>> dp(k+1,unordered_map<string,int>());
        return internal_impl(s,k,dp);
    }
};

// Recursive + memoization + delete lowest frequency characters
// Time complexity = O(N^k)
// Wrong Answer
class Solution {
public:
    int runLengthEncoding(string s){
        int n = s.size();
        if(n==0) return 0;
        int count = 1;
        char letter = s[0];
        int l = 1;
        for(int i=1;i<n;i++){
            if(s[i]==letter) count++;
            else{
                l++;
                if(count>1){
                    l+=to_string(count).size();
                    count=1;
                }
                letter = s[i];
            }

        }
        if(count>1){
            l+=to_string(count).size();
        }

        return l;
    }
    int internal_impl(string s, int k, vector<unordered_map<string,int>>& dp){
        if(dp[k].contains(s)) return dp[k][s];
        if(k==0){
            int l = runLengthEncoding(s);
            dp[k][s] = l;
            return l;
        }
        int n = s.size();
        int min_len = n+1;
        for(int i=0;i<n;i++){
            // delete s[i]
            string ss;
            if(i==0) ss = s.substr(1,n-1);
            else if(i==n-1) ss = s.substr(0,n-1);
            else ss = s.substr(0,i) + s.substr(i+1,n-i-1);
            int l = internal_impl(ss,k-1,dp);
            if(l<min_len) min_len = l;
        }
        dp[k][s] = min_len;
        return min_len;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        // count the frequency first
        unordered_map<char,int> freq;
        int n = s.size();
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        vector<pair<char,int>> freq_arr;
        for(auto item : freq){
            freq_arr.push_back(pair<char,int>{item.first,item.second});
        }
        sort(freq_arr.begin(),freq_arr.end(),[](pair<char,int>& a, pair<char,int>& b) { return a.second < b.second;});
        // make deletion plan
        unordered_map<char,int> delete_num;
        for(auto item : freq_arr){
            if(item.second<k){
                delete_num[item.first] = item.second;
                k-=item.second;
            }
        }
        // delete those lowest frequency first
        string ss;
        for(int i=0;i<n;i++){
            if(delete_num.contains(s[i])&& delete_num[s[i]]>0){
                delete_num[s[i]]--;
            } 
            else{
                ss.push_back(s[i]);
            }
        }
        vector<unordered_map<string,int>> dp(k+1,unordered_map<string,int>());
        return internal_impl(ss,k,dp);
    }
};