static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Brute force approach
// Time complexity = O(M*N*log(N))
// Time = 31ms (beats 93.99%), Memory = 26.33MB (beats 64.29%)
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size(), n = nums.size();
        vector<bool> res;
        for(int i=0;i<m;i++){
            vector<int> sample(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(sample.begin(),sample.end());
            int diff = sample[1]-sample[0];
            for(int j=1;j<sample.size()-1;j++){
                if(diff!=sample[j+1]-sample[j]){
                    res.push_back(false);
                    break;
                }
            }
            if(res.size()<=i) res.push_back(true);
        }
        return res;
    }
};