
// double hash map approach
// Time complexity = O(N)
// Time = 0ms (beats 100.00%)
// Timer = 05:20
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int,unordered_map<int,bool>> history;
        history[0][0]=true;
        vector<int> last_loc{0,0};
        for(int i=0;i<path.size();i++){
            if(path[i]=='N') last_loc[1] += 1;
            else if(path[i] == 'S') last_loc[1] -= 1;
            else if(path[i] == 'E') last_loc[0] += 1;
            else if(path[i] == 'W') last_loc[0] -= 1;

            if(history.contains(last_loc[0])){
                if(history[last_loc[0]].contains(last_loc[1]))
                    return true;
            }
            history[last_loc[0]][last_loc[1]] = true;
        }
        return false;
    }
};