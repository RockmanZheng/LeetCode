static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0,idx=mat.size()-1;
        for(int i=0;i<mat.size();i++,idx--)
            idx!=i ? sum+=mat[i][idx]+mat[i][i] : sum+=mat[i][i];
        return sum;
    }
};