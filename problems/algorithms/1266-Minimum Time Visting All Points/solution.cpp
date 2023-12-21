static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Time complexity = O(N)
// Time = 3ms (beats 95.33%), Memory = 10.51MB (beats 35.67%)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i=1;i<points.size();i++){
            res+=max(abs(points[i][0]-points[i-1][0]),abs(points[i][1]-points[i-1][1]));
        }
        return res;
    }
};