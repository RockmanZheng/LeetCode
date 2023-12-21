static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    std::unordered_map<int,int> indices;
    int n_flipped=0;
    int n_;
    int N;
    Solution(int m, int n) {
        n_=n;
        N = m*n;
    }
    
    vector<int> flip() {
        int idx = rand() % (N-n_flipped);
        int key = indices.count(idx)>0 ? indices[idx] : idx;
        std::vector<int> return_idx {key/n_, key%n_};
        int loc = N-n_flipped-1;
        int tmp = indices.count(loc)>0 ? indices[loc] : loc;
        indices[loc] = indices.count(idx)>0 ? indices[idx] : idx;
        indices[idx] = tmp;
        n_flipped++;
        return return_idx;
    }
    
    void reset() {
        n_flipped=0;
    }
};
