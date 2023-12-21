static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Shortest path approach
// Time = 0ms (beats 100.00%)
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx&&sy==fy){
            return t!=1;
        }
        else{
            return t>=max(abs(sx-fx),abs(sy-fy));
        }
        
    }
};