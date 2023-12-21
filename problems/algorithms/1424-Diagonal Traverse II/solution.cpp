// Brute Force approach
// Time complexity = O(N^2)
// TLE
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size(),j,k,longest_n=0;
        // get the longest array first
        for(int i=0;i<m;i++){
            if(nums[i].size()>longest_n){
                longest_n = nums[i].size();
            }
        }
        vector<int> res;
        for(int i=0;i<m;i++){
            j=i;
            k=0;
            while(j>=0){
                if(k<nums[j].size()) res.push_back(nums[j][k]);
                k++;
                j--;
            }
        }
        for(int i=1;i<longest_n;i++){
            k=i;
            j=m-1;
            while(j>=0){
                if(k<nums[j].size()) res.push_back(nums[j][k]);
                k++;
                j--;
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

// Useful info: Diagonal sum of row and column indices is constant
// Diagonal sum + ordered map (hashmap) approach
// Time complexity = O(N*log(N))
// Time = 261ms (beats 24.36%), Memory = 108.65MB (beats 18.16%)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        map<int,vector<int>> hashmap;
        vector<int> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<nums[i].size();j++){
                hashmap[i+j].push_back(nums[i][j]);
            }
        }
        for(auto &item : hashmap){
            auto arr = item.second;
            for(int i=arr.size()-1;i>=0;i--){
                res.push_back(arr[i]);
            }
        }
        return res;
    }
};
// Queue approach
// Time complexity = O(N)
// Time = 75ms (beats 100.00%), Memory = 65.97MB (beats 94.66%)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        queue<pair<int,int>> Q;
        vector<int> res;
        Q.push(pair<int,int>{0,0});
        while(!Q.empty()){
            auto idx = Q.front();
            Q.pop();
            res.push_back(nums[idx.first][idx.second]);
            if(!idx.second && idx.first+1<m) 
                Q.push(pair<int,int>{idx.first+1,idx.second});
            if(idx.second+1<nums[idx.first].size()) 
                Q.push(pair<int,int>{idx.first,idx.second+1});
        }
        return res;
    }
};