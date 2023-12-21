static const int fast_io = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i<0) reverse(nums.begin(),nums.end());
        else{
            int j=nums.size()-1;
            while(j>i && nums[j]<=nums[i]) j--;
            swap(nums[i],nums[j]);
            sort(nums.begin()+i+1,nums.end());
        }
    }
};