static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Dynamic programming approach I: TLE error
// Time Complexity = O(N^2)
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> longest_dist(obstacles.size(),1);
        int j;
        for(int i=1;i<obstacles.size();i++){
            j=i-1;
            while(j+2>longest_dist[i]){
                if(obstacles[i]>=obstacles[j] && longest_dist[j]+1>longest_dist[i]){
                    longest_dist[i]=longest_dist[j]+1;
                }
                j--;
            }
        }
        return longest_dist;
    }
};
// Dynamic programming + binary search approach: Time = 178ms (beats 97.21%), Memory = 118.18MB (beats 47.61%)
// Time Complexity = O(N*log(N))
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> longest_dist(obstacles.size(),1);
        // loc_at_dist[i] represents the last value of
        // the longest non-decreasing subsequence of length i+1
        vector<int> val_at_dist;
        int l,r,mid,k;
        for(int i=0;i<obstacles.size();i++){
            l=0;
            r=val_at_dist.size()-1;
            while(l<=r){// Binary searching valid longest distance
                mid = (r+l)/2;
                val_at_dist[mid]<=obstacles[i] ? l=mid+1 : r=mid-1;
            }
            if(l==val_at_dist.size()) val_at_dist.push_back(obstacles[i]);
            else val_at_dist[l]=obstacles[i];// update the last value because obstacles[i] must be smaller than val_at_dist[l], replacing with a smaller value facilitates longer courses in latter steps
            longest_dist[i]=l+1;
        }
        return longest_dist;
    }
};