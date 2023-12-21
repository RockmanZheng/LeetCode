static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Hashmap approach
// Time complexity = O(N), Space complexity = O(N)
// Time = 7ms (beats 83.61%), Memory = 14.38MB (beats 22.61%)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> counts;
        for(int i=0;i<arr.size();i++) counts[arr[i]]++;
        int v = arr.size()/4;
        for(auto item: counts)
            if(item.second>v) return item.first;
        return arr[0];
    }
};

static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Pointer/sweeping approach
// Time complexity = O(N), Space complexity = O(N)
// Time = 4ms (beats 95.90%), Memory = 12.86MB (beats 57.06%)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 0, record = -1,v = arr.size()/4;
        for(int i=0;i<arr.size();i++){
            if(record!=arr[i]){
                count = 1;
                record = arr[i];
            }
            else count++;
            if(count>v) return arr[i];
        }
        return -1;
    }
};