static const int fast_io = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Heap approach: Time = 58ms (beats 96.96%), Memory = 56.69MB (beats 23.16%)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int,std::vector<int>,std::greater<int>> Q(nums.begin(),nums.begin()+k);
        for(int i=k;i<nums.size();i++){
            if(Q.top()<nums[i]){
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();
    }
};