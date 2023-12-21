static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Linked list + HashMap
// Linked list to store the subarrays, hashmap to store the location of elements in the subarray list and indicator for whether it is front element
// Time complexity = O(N^2), Space Complexity = O(N)
// Time = 326ms (beats 86.06%), Memory = 111.96MB (beats 78.18%)
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<list<int>> subarray;
        unordered_map<int,int> loc;// locs[num] is the location of num in subarrays
        unordered_map<int,bool> is_front;// is_front[num] indicates whether num is at the front of the subarray

        int n = adjacentPairs.size();
        for(int i=0;i<n;i++){
            int num_1 = adjacentPairs[i][0], num_2 = adjacentPairs[i][1];
            if(loc.count(num_1)==0 and loc.count(num_2)==0){// if both num are new
                // append new subarray
                subarray.push_back(list<int>{num_1,num_2});
                loc[num_1] = subarray.size()-1;
                loc[num_2] = subarray.size()-1;
                is_front[num_1] = true;
                is_front[num_2] = false;
            }else if(loc.count(num_1) && loc.count(num_2)){// if both num are old
                // connect two existing subarrays
                if(is_front[num_1] && is_front[num_2]){
                    auto it = subarray[loc[num_1]].begin();
                    subarray[loc[num_2]].reverse();
                    subarray[loc[num_1]].splice(it,subarray[loc[num_2]]);
                    int new_num_1 = subarray[loc[num_1]].front(), new_num_2 = subarray[loc[num_1]].back();
                    loc[new_num_1] = loc[num_1];
                    loc[new_num_2] = loc[num_1];
                    is_front[new_num_1] = true;
                    is_front[new_num_2] = false;
                }else if(is_front[num_1] && !is_front[num_2]){
                    auto it = subarray[loc[num_1]].begin();
                    subarray[loc[num_1]].splice(it,subarray[loc[num_2]]);
                    int new_num_1 = subarray[loc[num_1]].front(), new_num_2 = subarray[loc[num_1]].back();
                    loc[new_num_1] = loc[num_1];
                    loc[new_num_2] = loc[num_1];
                    is_front[new_num_1] = true;
                    is_front[new_num_2] = false;
                }else if(!is_front[num_1] && is_front[num_2]){
                    auto it = subarray[loc[num_2]].begin();
                    subarray[loc[num_2]].splice(it,subarray[loc[num_1]]);
                    int new_num_1 = subarray[loc[num_2]].front(), new_num_2 = subarray[loc[num_2]].back();
                    loc[new_num_1] = loc[num_2];
                    loc[new_num_2] = loc[num_2];
                    is_front[new_num_1] = true;
                    is_front[new_num_2] = false;
                }else{
                    subarray[loc[num_2]].reverse();
                    auto it = subarray[loc[num_2]].begin();
                    subarray[loc[num_2]].splice(it,subarray[loc[num_1]]);
                    int new_num_1 = subarray[loc[num_2]].front(), new_num_2 = subarray[loc[num_2]].back();
                    loc[new_num_1] = loc[num_2];
                    loc[new_num_2] = loc[num_2];
                    is_front[new_num_1] = true;
                    is_front[new_num_2] = false;
                }
            }else{// if one is new while the other is old
                if(loc.count(num_1)){
                    if(is_front[num_1]) subarray[loc[num_1]].push_front(num_2);
                    else subarray[loc[num_1]].push_back(num_2);
                    loc[num_2] = loc[num_1];
                    is_front[num_2] = is_front[num_1];
                }
                else{
                    if(is_front[num_2]) subarray[loc[num_2]].push_front(num_1);
                    else subarray[loc[num_2]].push_back(num_1);
                    loc[num_1] = loc[num_2];
                    is_front[num_1] = is_front[num_2];
                }

            }
        }
        vector<int> res;
        for(int i=0;i<subarray.size();i++){
            if(subarray[i].size()){
                for(auto it=subarray[i].begin();it!=subarray[i].end();advance(it,1)){
                    res.push_back(*it);
                }
                break;
            }
        }
        return res;
    }
};

// For each number, record its neighbours using a hash map. The number with only one neighbour is the head (or the tail) of the list.
// Find the head, and keep going.
// Hash map + neighbor search approach
// Time complexity = O(N), Space complexity = O(N)
// Time = 283ms (beats 99.39%), Memory = 105.32MB (beats 95.15%)
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> neighbors;
        for(auto &p : adjacentPairs){ 
            neighbors[p[0]].push_back(p[1]);
            neighbors[p[1]].push_back(p[0]);
        }
        int num;
        for(auto &u : neighbors){
            if(u.second.size()==1){
                num = u.first;
                break;
            }
        }
        vector<int> res;
        int n_neighbors = 2;
        res.push_back(num);
        int last_num = num;
        num = neighbors[num][0];
        while(n_neighbors>1){
            res.push_back(num);
            n_neighbors = neighbors[num].size();
            for(auto &i : neighbors[num]){
                if(i!=last_num){
                    last_num = num;
                    num = i;
                    break;
                }
            }
        }
        return res;
    }
};