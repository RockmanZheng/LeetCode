static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Binary search approch.
// Time complexity = O(log(N)), Space complexity = O(1)
// Time = 3ms (beats 91.96%), Memory = 14.18MB (beats 8.57%)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return vector<int>{-1,-1};
        if(n==1 && nums[0]==target) return vector<int>{0,0};
        if(nums[0]>target || nums[n-1]<target) return vector<int>{-1,-1};
        int start,end;
        int left,right,mid;
        // binary search for start
        if(nums[0]==target) start=0;
        else{
            left=1;
            right=n;
            while(left<right){
                mid = (left+right)/2;
                if(nums[mid]<target && nums[mid-1]<target) left = mid+1;
                else right = mid;
            }
            if(nums[left]!=target) start = -1;
            else start = left;
        }
        if(start==-1) return vector<int>{-1,-1};
        // binary search for end
        if(nums[n-1]==target) end=n-1;
        else{
            left=start;
            right=n-1;
            while(left<right){
                mid = (left+right)/2;
                if(nums[mid]<=target && nums[mid+1]<=target) left = mid+1;
                else right = mid;
            }
            end = left;
        }
        return vector<int>{start,end};
    }
};