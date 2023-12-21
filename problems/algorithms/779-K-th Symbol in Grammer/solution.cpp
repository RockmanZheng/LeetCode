static const int fast_io = [](){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        int last_digit = kthGrammar(n-1,(k-1)/2+1);
        if(last_digit==0){
          if((k-1)%2) return 1;
          else return 0;
        }
        else{
          if((k-1)%2) return 0;
          else return 1;
        }
    }
};