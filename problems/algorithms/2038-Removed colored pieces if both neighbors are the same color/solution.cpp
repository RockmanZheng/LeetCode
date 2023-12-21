static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Direct count approach: Time = 20ms (beats 99.03%), Memory = 13.53MB (beats 23.75%)
class Solution {
public:
    bool winnerOfGame(string colors) {
        int count_a=0,count_b=0,count_alice = 0,count_bob = 0;
        for(int i=0;i<colors.size();i++){
            if(colors[i]=='A'){
                count_b = 0;
                count_a++;
            }
            else{
                count_a = 0;
                count_b++;
            }
            if(count_a>2) count_alice++;
            if(count_b>2) count_bob++;
        }
        return count_alice>count_bob;
    }
};