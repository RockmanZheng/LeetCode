static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Dynamic programming approach.
// Time complexity = O(N1*N2), Space Complexity = O(N1*N2)
// Time = 8ms (beats 97.94%), Memory = 10.41MB (beats 81.75%)
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int dp[n1][n2];// use array is faster than vector, and also more memory-saving
        dp[0][0]=nums1[0]*nums2[0];
        int ii,jj,prod;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                prod = nums1[i]*nums2[j];
                if(i==0 || j==0){
                    if(j>0) dp[0][j] = max(prod,dp[0][j-1]);// use max function is faster than if-else
                    if(i>0) dp[i][0] = max(prod,dp[i-1][0]);
                }
                else{
                    ii=i-1,jj=j-1;
                    dp[i][j] = max(dp[i][jj],max(dp[ii][j],max(prod,prod+dp[ii][jj])));
                }
                
            }
        }
        return dp[n1-1][n2-1];
    }

};