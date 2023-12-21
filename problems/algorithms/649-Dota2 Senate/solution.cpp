static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    std::queue<int> radiant;
    std::queue<int> dire;
    string predictPartyVictory(string senate) {
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                radiant.push(i);
            }
            else{
                dire.push(i);
            }
        }
        int tag = senate.size();
        while(!radiant.empty() && !dire.empty()){
            if(radiant.front()<dire.front()){
                dire.pop();
                radiant.pop();
                radiant.push(tag);
                
            }
            else{
                radiant.pop();
                dire.pop();
                dire.push(tag);
            }
            tag++;
        }
        if(radiant.empty()){
            return "Dire";
        }
        else{
            return "Radiant";
        }
    }
};