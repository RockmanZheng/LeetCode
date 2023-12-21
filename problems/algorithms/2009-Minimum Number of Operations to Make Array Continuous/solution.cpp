static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Direct approach: 
// Calculating the cost, or the minimum number of operations required to,
// of forming a continuous array if we choose 
// a particular element as the starting/ending point
// Then take the optimal element.
// The idea is as follows.
// Suppose we have X=[1,3,6,7,11], where the length n=5.
// Any operations would not change the length n.
// Consider inserting blanks in this array, obtaining
// A=[-,-,-,-,1,-,3,-,-,6,7,-,-,-,11,-,-,-,-]
// Choosing any particular element X[i] as the starting point, the continuous array must be 
// a range from [X[i],X[i]+n)
// The minimum number of operations is equal to the number of blanks within this range that we need to fill out in A
// For example, if we select X[0]=1 as the first element,
// There are 3 blanks within the range [1,6) in A, so the cost of starting with X[i] is 3.
// The cost of ending with a particular element is similarly calculated.
// Using this idea, it can be clearly observed that the minimum cost is 2,
// obtained by starting with 3, corresponding to a range [3,8), which only has 2 blanks in A.
// The above example assumes X is sorted and contains unique elements.
// Sorting can be down within time complexity O(N*log(N)) using quick sort.
// Minor adjustment can be made in cases of repeated elements.
//
// However, this approach would cause TLE error if we use a double loop counting method below.
// The time complexity is O(N^2).
class Solution {
public:
    int minOperations(vector<int>& nums) {
        // quick sort the array first, time complexity O(N*log(N))
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // form another array with unique elements
        // Time complexity = O(N)
        vector<int> a;
        a.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]) a.push_back(nums[i]);
        }
        int m = a.size();
        // Cost approach
        // costs[i] represents the minimum number of operations required
        // to form a continuous array if we start or end with element a[i]

        int min_cost=n-1,tmp_cost;
        int j;
        // Outer loop time complexity = O(N^2)
        for(int i=0;i<m;i++){
            // first get the cost when starting with a[i]
            // Time complexity = O(N)
            tmp_cost=n;
            j=i;
            while(j<m && a[j]>=a[i] && a[j]<a[i]+n){
                tmp_cost--;
                j++;
            }
            if(tmp_cost<min_cost) min_cost=tmp_cost;
            // next get the cost when ending with a[i]
            // Time complexity = O(N)
            tmp_cost=n;
            j=i;
            while(j>=0 && a[j]<=a[i] && a[j]>a[i]-n){
                tmp_cost--;
                j--;
            }
            if(tmp_cost<min_cost) min_cost=tmp_cost;
        }
        return min_cost;
    }
};

// Binary search speed up.
// Instead of using an inner loop to calculate each cost of starting at X[i]
// We can use a binary search to speed up by finding the first element
// falling outside the range [X[i],X[i]+n)
// Similarly, to calculate the cost of ending with X[i]
// We can use a binary search to find the first element
// falling inside the range (X[i]-n,X[i]]
//
// Since the quick sort and the cost calculation uses time complexity both O(N*log(N)) 
// The overal time complexity is also O(N*log(N))
// Time = 192ms (beats 59.42%), Memory = 69.85MB (beats 51.67%)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        // quick sort the array first, time complexity O(N*log(N))
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // form another array with unique elements
        // Time complexity = O(N)
        vector<int> a;
        a.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]) a.push_back(nums[i]);
        }
        int m = a.size();
        // Cost approach
        // costs[i] represents the minimum number of operations required
        // to form a continuous array if we start or end with element a[i]

        int min_cost=n-1,tmp_cost;
        int j;
        // Outer loop time complexity = O(N*log(N))
        for(int i=0;i<m;i++){
            // first get the cost when starting with a[i]
            // Time complexity = O(log(N))
            auto ptr = upper_bound(a.begin()+i,a.end(),a[i]+n-1);
            j=ptr-a.begin();
            tmp_cost = n-(j-i);
            if(tmp_cost<min_cost) min_cost=tmp_cost;
            // next get the cost when ending with a[i]
            // Time complexity = O(log(N))
            ptr = upper_bound(a.begin(),a.begin()+i,a[i]-n);
            j=ptr-a.begin();
            tmp_cost=n-(i-j)-1;
            if(tmp_cost<min_cost) min_cost=tmp_cost;
        }
        return min_cost;
    }
};

// Sliding window approach (best): 
// Instead of considering starting or ending at an element,
// here we just use a sliding window of length N.
// And there is no need for binary search anymore.
// Time complexity = O(N*log(N))
// Time = 92ms (beats 100.00%), Memory = 64.49MB (beats 78.87%)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        // quick sort the array first, time complexity O(N*log(N))
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int m = nums.size();
        // Cost approach
        // costs[i] represents the minimum number of operations required
        // to form a continuous array if we start or end with element a[i]

        int min_cost=n-1;
        int i=0,j=0;
        // Outer loop time complexity = O(N*log(N))
        while(j<m){
            if(nums[i]+n<=nums[j]){
                min_cost = min(n-(j-i),min_cost);
                i++;
            }
            j++;
        }
        min_cost = min(n-(j-i),min_cost);
        
        return min_cost;
    }
};