static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Brute force approach
// Time complexity = O(N^2)
// TLE
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(),tmp;
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                tmp = nums[i]-nums[j];
                tmp = tmp>0? tmp : -tmp;
                res[i]+=tmp;
                res[j]+=tmp;
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
// Math + Prefix sum approach
// res[i] = (i-(n-i-1))*nums[i]+sum(nums[i+1:])-sum(nums[:i])
// Time complexity = O(N)
// Time = 68ms (beats 98.92%), Memory = 94.36 (beats 5.95%)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix,res;
        prefix.push_back(nums[0]);
        for(int i=1;i<n;i++) prefix.push_back(nums[i]+prefix.back());
        res.push_back(prefix.back()-n*nums[0]);
        for(int i=1;i<n;i++){
            res.push_back((2*i-n+1)*nums[i]+prefix.back()-prefix[i]-prefix[i-1]);
        }
        
        return res;
    }
};