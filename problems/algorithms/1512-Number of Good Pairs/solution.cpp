static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int i=0,j,count=0;
        while(i<nums.size()-1){
            j=i+1;
            while(j<nums.size()){
                if(nums[i]==nums[j]) count++;
                j++;
            }
            i++;
        }
        return count;
    }
};