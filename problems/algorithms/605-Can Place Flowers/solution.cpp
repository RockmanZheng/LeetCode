static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(!n) return true;
        if(m==1){
            if(!flowerbed[0]) return true;
            else return false;
        }
        else if(!flowerbed[0] && !flowerbed[1]){
            flowerbed[0] = 1;
            n--;
        }
        for(int i=1;i<m-1;i++){
            if(n && !flowerbed[i-1] && !flowerbed[i+1] && !flowerbed[i]){
                flowerbed[i] = 1;
                n--;
            }
        }
        if(n && !flowerbed[m-2] && !flowerbed[m-1]){
            flowerbed[m-1]=1;
            n--;
        }
        return !n;
    }
};