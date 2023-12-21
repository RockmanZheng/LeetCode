static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Sort + greedy approach
// Time complexity = O(N*log(N))
// Time = 71ms (beats 98.09%), Memory = 54.20MB (beats 5.22%)
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size()/3;
        sort(piles.begin(),piles.end());
        int res=0,i=piles.size()-2;
        while(n--){
            res += piles[i];
            i-=2;
        }
        return res;
    }
};