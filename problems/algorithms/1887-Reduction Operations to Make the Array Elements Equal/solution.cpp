static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Prefix difference to check for gap and skip those gaps in counting operation
// Time complexity = O(N)
// Time = 113ms (beats 99.08%), Memory = 83.64MB (beats 49.08%)
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<bool> has_gaps;
        has_gaps.push_back(false);
        for(int i=1;i<n;i++){
            has_gaps.push_back(nums[i]-nums[i-1]);
        }
        int i=n-1,res = 0;
        while(i){
            if(has_gaps[i]) res+=n-i;
            i--;
        }
        return res;
    }
};