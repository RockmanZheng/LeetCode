static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size(),0);
        if(seq.empty()) return res;
        int count=1;
        for(int i=1;i<seq.size();i++){
            if(seq[i]=='(') count++%2 ? res[i]=1 : res[i]=0;
            else count++%2 ? res[i]=0 : res[i]=1;
        }
        return res;
    }
};