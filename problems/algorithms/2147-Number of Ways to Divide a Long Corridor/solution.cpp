static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Two pointer + counting
// Time complexity = O(N)
// Time = 65ms (beats 100.00%), Memory = 30.94MB (beats 84.57%)
class Solution {
public:
    int numberOfWays(string corridor) {
        // count the number of seats
        int n = corridor.size(),n_seats=0;
        for(int i=0;i<n;i++)
            if(corridor[i]=='S') 
                n_seats++;
        if(n_seats%2 || n_seats==0) return 0;// odd number of seats or no seat, impossible to divide
        if(n_seats==2) return 1;
        // record the number of gaps between two pairs of seats
        int count=0,N=1000000007,l=-1,r=-1;
        long res=1;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){
                count++;
                if(count==2){
                    count=0;
                    l=i;
                }
                if(count==1 && l>=0){
                    r=i;
                    res = (res*(r-l))%N;
                }
            }
        }
        return res;
    }
};