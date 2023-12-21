// Prefix difference approach
// Time complexity = O(N^2)
// TLE
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // calculate prefix difference first
        vector<int> diff;
        diff.push_back(0);
        int n = nums.size();
        for(int i=1;i<n;i++){
            diff.push_back(nums[i]-nums[i-1]);
        }
        int l=n-1,r=n-1,res=1,freq,prefix,step;
        while(l){
            step=k;
            freq=1;
            prefix=diff[r];
            while(step>0 && r>0){
                step-=prefix;
                r--;
                prefix+=diff[r];
                if(step>=0) freq++;
            }
            res = max(res,freq);
            l--;
            r=l;
        }
        return res;
    }
};
// Prefix difference approach, avoid repeated calculation using multiplication
// Time complexity = O(N*log(N))
// Time = 137ms (beats 96.84%), Memory = 110.59MB (5.28%)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // calculate prefix difference first
        vector<int> diff;
        diff.push_back(0);
        int n = nums.size();
        for(int i=1;i<n;i++){
            diff.push_back(nums[i]-nums[i-1]);
        }
        int l=n-1,r=n-1,res=1,cost=diff[r],budget=k;
        while(l){
            while(budget>=cost&& r>0){
                budget-=cost;
                r--;
                cost+=diff[r];
            }
            res = max(res,l-r+1);
            budget+=diff[l]*(l-r);
            cost-=diff[l];
            l--;
        }
        return res;
    }
};