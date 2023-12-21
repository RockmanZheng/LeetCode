static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
// Dynamic programming + sort + hash map factor search
// Time complexity = O(N*log(N)+sqrt(max(arr)))
// Time = 412ms (beats 6.30%), Memory = 9.96MB (beats 37.80%)

    vector<pair<int,int>> findFactor(unordered_map<int,int>& mp,int m){
        vector<pair<int,int>> res;
        for(int i=2;i*i<=m;i++){// complexity O(sqrt(m))
            if(!(m%i) && mp.count(i)){// search cost = O(1)
                int j = m/i;
                if(mp.count(j)) res.push_back(pair{mp[i],mp[j]});
            }
        }
        return res;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        int N = 1e9+7;
        int n = arr.size();
        sort(arr.begin(),arr.end());// sort first, time complexity = O(N*log(N))
        unordered_map<int,int> mp;
        // use map to store arr to speed up search ops from O(N) to O(1)
        for(int i=0;i<n;i++) mp[arr[i]]=i;
        
        long dp[n];// arr[i] is the number of trees if arr[i] is the root
        dp[0] = 1;
        long res = 1;
        for(int i=1;i<n;i++){
            // find all pairs of children whose prodcut is equal to arr[i]
            auto pairs = findFactor(mp,arr[i]);// Time complexity O(sqrt(max(arr)))
            dp[i] = 1;
            for(int j = 0;j<pairs.size();j++){
                if(pairs[j].first==pairs[j].second)
                    dp[i] = (dp[i]+(dp[pairs[j].first]*dp[pairs[j].second]) % N) % N;
                else 
                    dp[i] = (dp[i]+(2*((dp[pairs[j].first]*dp[pairs[j].second]) % N)) % N) % N;// interchanging left and right children gives another tree
            }
            res = (res + dp[i]) % N;
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
class Solution {
public:
// Dynamic programming + sort + hash map factor search, search directly within arr
// Time complexity = O(N*log(N))
// Time = 18ms (beats = 96.06%), Memory = 10.02MB (36.61%)

    vector<pair<int,int>> findFactor(vector<int>& arr,unordered_map<int,int>& mp,int m){
        vector<pair<int,int>> res;
        float bound = sqrt(m);
        int j,k;
        for(int i=0;i<arr.size();i++){// time complexity O(N)
            k = arr[i];
            if(k>bound) break;
            if(!(m % k) && mp.count(k)){// search cost = O(1)
                j = m/k;
                if(mp.count(j)) res.push_back(pair{mp[k],mp[j]});
            }
        }
        return res;
    }

    int numFactoredBinaryTrees(vector<int>& arr) {
        int N = 1e9+7;
        int n = arr.size();
        sort(arr.begin(),arr.end());// sort first, time complexity = O(N*log(N))
        unordered_map<int,int> mp;
        // use map to store arr to speed up search ops from O(N) to O(1)
        for(int i=0;i<n;i++) mp[arr[i]]=i;
        
        long dp[n];// arr[i] is the number of trees if arr[i] is the root
        dp[0] = 1;
        long res = 1;
        for(int i=1;i<n;i++){
            // find all pairs of children whose prodcut is equal to arr[i]
            auto pairs = findFactor(arr,mp,arr[i]);// Time complexity O(sqrt(max(arr)))
            dp[i] = 1;
            for(int j = 0;j<pairs.size();j++){
                if(pairs[j].first==pairs[j].second)
                    dp[i] = (dp[i]+(dp[pairs[j].first]*dp[pairs[j].second]) % N) % N;
                else 
                    dp[i] = (dp[i]+(2*((dp[pairs[j].first]*dp[pairs[j].second]) % N)) % N) % N;// interchanging left and right children gives another tree
            }
            res = (res + dp[i]) % N;
        }
        return res;
    }
};