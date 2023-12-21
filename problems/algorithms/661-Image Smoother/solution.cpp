static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// double prefix sum approach
// Time complexity = O(M*N)
// Time = 32ms (beats 96.92%)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        if (m == 1){
            if(n == 1){
                return img;
            }
            else{
                vector<int> prefix(n + 1, 0);
                for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + img[0][i-1];
                res[0][0] = prefix[2] / 2;
                res[0][n-1] = (prefix[n] - prefix[n-2]) / 2;
                for(int j = 1; j < n - 1; j++) res[0][j] = (prefix[j+2] - prefix[j-1]) / 3;
                return res;
            }
        }
        else{
            if(n==1){
                vector<int> prefix(m + 1, 0);
                for(int i = 1; i <= m; i++) prefix[i] = prefix[i-1] + img[i-1][0];
                res[0][0] = prefix[2] / 2;
                res[m-1][0] = (prefix[m] - prefix[m-2]) / 2;
                for(int i = 1; i < m - 1; i++) res[i][0] = (prefix[i+2] - prefix[i-1]) / 3;
                return res;
            }
        }
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                prefix[i][j] = prefix[i][j-1] + img[i-1][j-1];
            }
        }
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= m; i++){
                prefix[i][j] += prefix[i-1][j];
            }
        }
        
        res[0][0] = (prefix[2][2] - prefix[2][0]) / 4;
        res[0][n-1] = (prefix[2][n]  - prefix[2][n-2]) / 4;
        res[m-1][0] = (prefix[m][2] - prefix[m-2][2]) / 4;
        res[m-1][n-1] = (prefix[m][n] - prefix[m-2][n] - prefix[m][n-2] + prefix[m-2][n-2]) /4;
        for(int j = 1; j < n - 1; j++){
            res[0][j] = (prefix[2][j+2] - prefix[2][j-1]) / 6;
            res[m-1][j] = (prefix[m][j+2] - prefix[m-2][j+2] - prefix[m][j-1] + prefix[m-2][j-1]) / 6;
        }
        for(int i = 1; i < m - 1; i++){
            res[i][0] = (prefix[i+2][2] - prefix[i-1][2]) / 6;
            res[i][n-1] = (prefix[i+2][n] - prefix[i-1][n] - prefix[i+2][n-2] + prefix[i-1][n-2]) / 6;
        }
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                res[i][j] = (prefix[i+2][j+2] - prefix[i-1][j+2] - prefix[i+2][j-1] + prefix[i-1][j-1]) / 9;
            }
        }
        return res;
    }
};
static const int fast_io  = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Brute-force approach
// Time complexity = O(M*N)
// Time = 30ms (beats 99.38%)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int> > ans(n, vector<int> (m, 0));    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = 0, cnt = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int nx = dx + i, ny = dy + j;
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        ++cnt;
                        sum += img[nx][ny];
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};