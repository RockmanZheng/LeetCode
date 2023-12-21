static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Hash Map approach: Time = 4ms (beats 93.15%), Memory = 16.57MB (beats 9.38%)
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash_map;
        vector<int> res;
        for(int i=0;i<nums.size();i++) hash_map[nums[i]]++;
        int major_num = nums.size()/3;
        for(auto ptr=hash_map.begin();ptr!=hash_map.end();ptr++)
            if(ptr->second>major_num) 
                res.push_back(ptr->first);
        
        return res;
    }
};
// Boyer-Moore Majority Voting approach: Time = 8ms (beats 68.48%), Memory = 16.36MB (beats 9.38%)
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int count1=0,count2=0,candidate1,candidate2;
        for(int i=0;i<nums.size();i++){
            if(count1==0 && nums[i] != candidate2) {
                candidate1 = nums[i];
                count1++;
            }
            else if(count2==0 && nums[i]!= candidate1){
                candidate2 = nums[i];   
                count2++;    
            }
            else if(candidate1==nums[i]) count1++;
            else if(candidate2==nums[i]) count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<nums.size();i++){
            if(candidate1==nums[i]) count1++;
            else if(candidate2==nums[i]) count2++;
        }
        int threshold = nums.size()/3;
        if(count1>threshold) res.push_back(candidate1);
        if(count2>threshold) res.push_back(candidate2);
        return res;
    }
};
