static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// sort approach
// Time complexity = O(N*log(N))
// Time = 12ms (beats 98.38%)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return nums[n-1] * nums[n-2] - nums[0] * nums[1];
    }
};