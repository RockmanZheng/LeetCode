static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
/* Stack approach. Time = 42ms (beats 98.84%) Memory = 48.23MB (beats 84.09%) */
class Solution {
public:
    std::stack<int> mid_val;
    int third_val = INT_MIN;
    bool find132pattern(vector<int>& nums) {
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<third_val){
                return true;
            }
            while(!mid_val.empty() && mid_val.top()<nums[i]){
                third_val = mid_val.top();
                mid_val.pop();
            }
            mid_val.push(nums[i]);
        }
        return false;
    }
};