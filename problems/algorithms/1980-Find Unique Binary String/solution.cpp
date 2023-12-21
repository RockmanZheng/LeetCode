static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Probabilistic approach
// Time complexity = O(1) asymptotically, Space complexity = O(N)
// Time = 0ms (beats 100.00%), Memory = 10.93MB (beats 37.61%)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // make it hashmap to speed up checking
        unordered_map<int,bool> hashmap;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int bits=0;
            for(char &c : nums[i]){
                if(c=='1') bits++;
                bits<<=1;
            }
            bits>>=1;
            hashmap[bits] = true;
        }
        int N = 1<<n;
        int rand_bits = rand()%N;
        while(hashmap.count(rand_bits)){// randomly generate bit string
            rand_bits = rand()%N;// since there are 2^n possible bit string and there are only n in nums
            // high chances are that we will hit a missing bit string
        }
        string res = "";
        int i=n;
        while(i--){
            if(rand_bits%2) res = '1'+res;
            else res = '0'+res;
            rand_bits>>=1;
        }
        return res;
    }
};