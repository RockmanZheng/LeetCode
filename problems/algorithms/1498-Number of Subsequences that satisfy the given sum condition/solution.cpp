static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int count=0;
        int N = 1e9+7;
        std::vector<int> pows(nums.size(),1);
        if(!std::is_sorted(nums.begin(),nums.end())){
            std::sort(nums.begin(),nums.end());
        }
        for(int i=1;i<nums.size();i++){
            pows[i]=(pows[i-1]<<1) % N;
        }
        int l=0, r=nums.size()-1;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                count = (count+pows[r-l]) % N;
                l++;
            }
            else r--;
        }
        return count;
    }
};