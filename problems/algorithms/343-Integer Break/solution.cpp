static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Optimization approach + recursive approach to power calculation
// Time Complexity = O(log(N)), Space Complexity = O(1)
// Time = 0ms (beats 100.00%), Memory = 6.27MB (beats 53.64%)
class Solution {
public:

    int my_pow(int n,int k){
        if(k==0) return 1;
        if(k==1) return n;
        if(k%2==0) return my_pow(n*n,k/2);
        else return my_pow(n*n,k/2)*n;
    }

    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int r = n%3;
        int res = my_pow(3,n/3-1);
        if(2*r>3) return res*3*r;
        else return res*(3+r);
    }
};