static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

// Min Heap
// Time complexity = O(N*log(N))
// Time = 117ms (beats 36.8%), Memory = 85.17MB (59.47%)
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        priority_queue<int,vector<int>,greater<int>> deadlines;
        
        for(int i=0;i<n;i++){
            if(dist[i]%speed[i]) deadlines.push(dist[i]/speed[i]+1);
            else deadlines.push(dist[i]/speed[i]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            auto deadline = deadlines.top();
            deadlines.pop();
            if(res<deadline) res++;
            else break;
        }
        return res;
    }
};

// Sort
// Time complexity = O(N*log(N))
// Time = 83ms (99.20%), Memory = 85.31MB (49.33%)
// No need to use mean heap
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> deadlines;
        
        for(int i=0;i<n;i++){
            if(dist[i]%speed[i]) deadlines.push_back(dist[i]/speed[i]+1);
            else deadlines.push_back(dist[i]/speed[i]);
        }
        sort(deadlines.begin(),deadlines.end());
        int res=0;
        for(int i=0;i<n;i++){
            if(res<deadlines[i]) res++;
            else break;
        }
        return res;
    }
};