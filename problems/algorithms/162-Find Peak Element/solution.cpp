static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Binary search approach: Time = 2ms (beats 66.59%), Memory = 9.22MB (beats 8.35%)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0,j=nums.size()-1,mid;
        if(i==j) return 0;
        while(i<=j){
            mid=i+(j-i)/2;
            if(mid>=1 && mid<nums.size()-1){
                if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) return mid;  
                else if(nums[mid-1]>=nums[mid]) j=mid-1;
                else i=mid+1;
            }
            else if(mid==0){
                if(nums[mid]>nums[mid+1]) return mid;
                else i=mid+1;
            }
            else if(mid==nums.size()-1){
                if(nums[mid-1]<nums[mid]) return mid;
                else j=mid-1;
            }
        }
        return -1;
    }
};