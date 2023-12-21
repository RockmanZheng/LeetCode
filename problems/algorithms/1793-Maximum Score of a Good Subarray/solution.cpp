static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

// Greedy two pointers approach
// Time complexity = O(N), space complexity = O(1)
// Time = 79ms (beats 99.56%), Memory = 89.30MB (beats 99.12%)
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int l=k,r=k;
        int min_val = nums[k], res=nums[k];
        bool flag=true;
        while(flag){
            if(l>0 && r<n-1){
                if(nums[l-1]>nums[r+1]) l--;
                else r++;
            }
            else if(l==0 && r<n-1) r++;
            else if(l>0 && r==n-1) l--;
            else flag=false;
            min_val = min(nums[l],min(nums[r],min_val));
            res = max(res,min_val*(r-l+1));
        }
        return res;
    }
};