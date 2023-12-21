static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increase_flag = false;
        bool decrease_flag = false;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                increase_flag = true;
            }
            else if(nums[i]>nums[i+1]){
                decrease_flag = true;
            }
            if(increase_flag && decrease_flag){
                return false;
            }
        }
        return true;
    }
};