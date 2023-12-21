
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return vector<int>{1};
        vector<int> res(rowIndex+1,1);
        vector<int> last_row = getRow(rowIndex-1);
        for(int i=1;i<rowIndex;i++){
            res[i] = last_row[i-1]+last_row[i];
        }
        return res;
    }
};