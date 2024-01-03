static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Brute force approach
// Time complexity = O(M+N)
// Time = 22ms (beats 77.03%), Memory = 90.78MB (beats 5.53%)
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> comb;
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(comb));
        if(comb.size()%2){
            return comb[comb.size()/2];
        }
        else{
            int mid = comb.size()/2;
            return ((double)comb[mid-1]+(double)comb[mid])/2;
        }
    }
};

// Binary search approach
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        int l1 = 0, r1 = m, mid1, l2 = 0, r2 = n, mid2;
        if((m+n)%2){// if it is odd
            while(l1<r1){
                mid1 = (l1+r1)/2;
                while(l2<r2){// find the upper bound of nums1[mid1] in nums2
                    mid2 = (l2+r2)/2;
                    if(nums2[mid2]>nums1[mid1]) 
                }
            }
        }

    }
};