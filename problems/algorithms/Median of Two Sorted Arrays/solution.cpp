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