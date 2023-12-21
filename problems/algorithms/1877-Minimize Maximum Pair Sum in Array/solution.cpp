static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Make the pair sum as even as possible, fixed point of the minimax problem must be balanced
// Time complexity = O(N*log(N))
// Time = 119ms (beats 99.80%), Memory = 96.52MB (61.58%)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1,res = 0;
        while(l<r){
            res = max(res,nums[l]+nums[r]);
            l++;
            r--;
        }
        return res;
    }
};