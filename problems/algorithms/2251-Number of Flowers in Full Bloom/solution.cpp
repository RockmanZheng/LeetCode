static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Random walk approach
// The number of flowers alive at time t can be expressed as a random walk:
// S[t]=sum(X[0:t]-Y[0:t])
// where X[i] is the number of flowers that bloom at time i
// and Y[i] is the number of flowers that die at time [i]
// The array X can be calculated from the start column of the flowers array after a sort
// The array Y can be calculated from the end column of the flowers array after a sort
// Suppose that people array is sorted
// Then the res[i] is just S[people[i]]=sum(X[0:people[i]])-sum(Y[0:people[i]])
//
// Due to the sorting, the complexity of the following algorithm is
// Time complexity = O(N*log(N)+M*log(M))
// Time = 157ms (beats 100.00%), Memory = 80.84MB (92.38%)
class Solution {
public:
    // Custom comparator that compares elements based on their values
    static bool compareWithIndex(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m=flowers.size(),n=people.size();
        vector<int> start(m,0),end(m,0);
        vector<int> res(n,0);
        // Get start and end times separately
        // Time complexity = O(M)
        for(int i=0;i<m;i++){
            start[i]=flowers[i][0];
            end[i]=flowers[i][1];
        }
        // Sort start and end times separately
        // Time complexity = O(M*log(M))
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());


        std::vector<std::pair<int, int>> indexedPeople(n);

        // Populate the indexed array with elements and their indexes
        // Time complexity = O(N)
        for (int i = 0; i < n; ++i) {
            indexedPeople[i] = std::make_pair(people[i], i);
        }

        // Sort the indexed array using the custom comparator
        // Time complexity = O(N*log(N))
        std::sort(indexedPeople.begin(), indexedPeople.end(), compareWithIndex);

        // Time complexity = O(M+N)
        int j=0,k=0;
        int count_start=0,count_end=0;
        for(int i=0;i<n;i++){
            while(j<m && start[j]<=indexedPeople[i].first){
                count_start++;
                j++;
            }
            while(k<m && end[k]<indexedPeople[i].first){
                count_end++;
                k++;
            }
            res[indexedPeople[i].second]=count_start-count_end;
        }
        return res;
    }
};