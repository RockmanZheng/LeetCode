static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Bucket approach: Time = 97ms (beats 89.22%), Memory = 55.65MB (beats 59.30%)
class MyHashMap {
public:
    int n_buckets = 1000;
    vector<vector<vector<int>>> buckets;
    MyHashMap() {
        buckets = vector<vector<vector<int>>>(n_buckets,vector<vector<int>>());
    }
    
    void put(int key, int value) {
        int idx = key % n_buckets;
        int i;
        for(i=0;i<buckets[idx].size();i++){
            if(buckets[idx][i][0]==key){
                buckets[idx][i][1]=value;
                break;
            }
        }
        if(i>=buckets[idx].size()) buckets[idx].push_back(vector<int>{key,value});
    }
    
    int get(int key) {
        int idx = key % n_buckets;
        int i;
        for(i=0;i<buckets[idx].size();i++){
            if(buckets[idx][i][0]==key) return buckets[idx][i][1];
        }
        if(i>=buckets[idx].size()) return -1;
        return -1;
    }
    
    void remove(int key) {
        int idx = key % n_buckets;
        for(int i=0;i<buckets[idx].size();i++){
            if(buckets[idx][i][0]==key){
                buckets[idx].erase(buckets[idx].begin()+i);
                break;
            }
        }
    }
};
