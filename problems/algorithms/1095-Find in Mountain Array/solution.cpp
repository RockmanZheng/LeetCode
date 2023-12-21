/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
// Three binary search approach
// Time complexity = O(log(N))
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // Use binary search to find the mountain top first
        // Time complexity = O(log(N))
        int n=mountainArr.length();
        int left = 0,right = n-1,mid,val_0,val_1,val_2;
        while(left<right){
            mid = (left+right)/2;
            val_0 = mountainArr.get(mid-1);
            val_1 = mountainArr.get(mid);
            val_2 = mountainArr.get(mid+1);
            if(val_0<val_1 && val_1<val_2){// the top must be on the right
                left = mid+1;
            }
            else if(val_0>val_1 && val_1>val_2){// the top must be on the left
                right = mid;
            }
            else{
                break;
            }
        }

        // If the target is out of the range between the mountain top and the mountain feet
        // output -1
        int top_idx = mid;
        int top_val = mountainArr.get(top_idx);
        int left_val = mountainArr.get(0);
        int right_val = mountainArr.get(n-1);
        if(target>top_val || target< min(left_val,right_val)){
            return -1;
        }
        else if(target == top_val){// first rule out the top
            return top_idx;
        }

        // Use two binary search to find within the two sides of the mountain the target
        // Time complexity = O(log(N))
        
        left=0;
        right=top_idx;
        while(left<right){
            mid = (left+right)/2;
            val_0 = mountainArr.get(mid);
            if(val_0>target){// target on the left
                right = mid;
            }
            else if(val_0<target){// target on the right
                left = mid+1;
            }
            else{
                return mid;
            }
        }
        if(mountainArr.get(left)==target) return left;
        left=top_idx;
        right=n-1;
        while(left<right){
            mid = (left+right)/2;
            val_0 = mountainArr.get(mid);
            if(val_0>target){
                left=mid+1;
            }
            else if(val_0<target){
                right=mid;
            }
            else{
                return mid;
            }
        }
        if(mountainArr.get(left)==target) return left;
        return -1;
    }
};