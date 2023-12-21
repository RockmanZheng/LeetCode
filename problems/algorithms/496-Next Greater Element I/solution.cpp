static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Monotonic stack + hashmap approach.
// Time complexity = O(N)
// Time = 0ms (beats 100.00%)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(m,-1);
        unordered_map<int,int> index;// index[v] is the index of element v in nums2
        for(int i=0;i<n;i++){
            index[nums2[i]] = i;
        }
        vector<int> next_gtr(n,-1);
        stack<int> ms;// monotonic stack, ms contains the index of nums2
        ms.push(0);
        for(int i=1;i<n;i++){
            while(!ms.empty() && nums2[ms.top()]<nums2[i]){
                next_gtr[ms.top()] = nums2[i];
                ms.pop();
            }
            ms.push(i);
        }
        for(int i=0;i<m;i++){
            res[i] = next_gtr[index[nums1[i]]];
        }
        return res;
    }
};