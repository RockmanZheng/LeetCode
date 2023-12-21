
// Brute force approach + memoization
// Time complexity = O(N^2)
// TLE
class Solution {
public:
    unordered_map<int,int> rev_hashmap;
    int rev(int x){
        if(!rev_hashmap.count(x)){
            int res=0,denom=1000000000;
            while(!(x/denom)) denom/=10;
            int factor=1;
            while(x){
                int digit = x/denom;
                x-=digit*denom; 
                res+=digit*factor;
                factor*=10;
                denom/=10;
            }
            rev_hashmap[x]=res;
            return res;
        }
        else{
            return rev_hashmap[x];
        }
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int res=0;
        int N=1000000007;
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(nums[i]+rev(nums[j])==nums[j]+rev(nums[i])) 
                    res=(res+1)%N;
        return res;
    }
};

static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Reformulate equation + memoization
// a nice pair also satisfies n - rev(n) == m - rev(m)
// so we just need to count the frequency of x - rev(x)
// and if there are K of them, the number of nice pairs is K*(K-1)/2
// Time complexity = O(N)
// Time = 54ms (beats 100.00%), Memory = 56.14MB (beats 99.02%)
class Solution {
public:
    unordered_map<int,int> hashmap;

    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long res=0,m;
        int N=1000000007,diff;

        for(int i=0;i<n;i++){
            int rev=0,y=nums[i];
            while(y){
                rev = rev*10 + y%10;
                y/=10; 
            }
            diff=nums[i]-rev;
            if(!hashmap.contains(diff)) hashmap[diff]=0;
            else hashmap[diff]+=1;// count the frequency of x-rev(x), minus 1
        }
        for(auto item:hashmap){
            m = item.second;
            res = (res+(m*(m+1))/2)%N;
        }
            
        return res;
    }
};