static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Prefix sum approach
// But not just simple prefix sum
// More like partial prefix sum
// For each row i, the prefix sum represents the height of 1's up to this row
// If there is 0 in between, the prefix sum will be restarted
// Time complexity = O(M*N*log(N))
// Time = 115ms (beats 99.43%), Memory = 66.18MB (beats 96.02%)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]) matrix[i][j]+=matrix[i-1][j];
            }
        }
        for(int i=0;i<m;i++)
            sort(matrix[i].begin(),matrix[i].end());
        
        
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                res = max(res,matrix[i][j]*(n-j));
            }
        }
        return res;
    }
};