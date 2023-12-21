

// Find the interleaving pattern
// Time complexity = O(log(N))
// Time = 0ms (beats 100.00%), Memory = 6.32MB (beats 52.13%)
class Solution {
public:

    int minimumOneBitOperations(int n) {
        int res=0,count=1;
        bool flag=false;
        while(n){
            if(n%2){
                if(flag) res+=(1<<count)-1;
                else res-=(1<<count)-1;
                flag = !flag;
            }
            n>>=1;
            count++;
        }
        res = res>0?res:-res;
        return res;
    }
};