static const int fast_io = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int S = nums[j]+nums[k];
                if(S>-nums[i]) k--;
                else if(S<-nums[i]) j++;
                else{
                    res.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    int tmp_j=j,tmp_k=k;
                    while(j<nums.size()-1 && nums[j]==nums[tmp_j]) j++;
                    while(k>=0 && nums[k]==nums[tmp_k]) k--;
                }
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};