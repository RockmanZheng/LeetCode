static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Sort x-axis + max difference approach
// Time complexity = O(N*log(N))
// Time = 170ms (beats 94.52%)
// Timer = 00:05:05
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xs;
        for(auto point : points){
            xs.push_back(point[0]);
        }
        sort(xs.begin(),xs.end());
        int res = 0;
        for(int i=1;i<xs.size();i++){
            res = max(res,xs[i]-xs[i-1]);
        }
        return res;
    }
};