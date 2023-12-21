static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int totalMoney(int n) {
        int n_weeks = n/7;
        int n_days = n%7;
        //int res = 28*n_weeks+(n_weeks-1)*n_weeks/2*7+n_weeks*n_days+(n_days+1)*n_days/2;
        if(n_weeks) return (28+n_days)*n_weeks+(n_weeks-1)*n_weeks/2*7+(n_days+1)*n_days/2;
        else return (n_days+1)*n_days/2;
    }
};