/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Direct queue approach
// Time = 7ms (beats 61.11%), Memory = 16.68MB (beats 8.67%)
// Spend too much time in looping already flatten integers
// Spend too much space holding NestedInteger object
class NestedIterator {
public:
    queue<NestedInteger> Q1;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i=0;i<n;i++) Q1.push(nestedList[i]);
        bool all_integer=true;
        int count = 0;
        while(true){
            auto obj = Q1.front();
            Q1.pop();
            if(obj.isInteger()) Q1.push(obj);
            else{
                all_integer = false;
                auto list = obj.getList();
                int m = list.size();
                for(int i=0;i<m;i++) Q1.push(list[i]);
            }
            count++;
            if(count==n){// initialize next loop through the queue
                n = Q1.size();// update the length of queue
                count=0;
                if(all_integer || Q1.empty()) break;// the list is flatten
                all_integer = true;
            }
        }
    }
    
    int next() {
        auto res = Q1.front();
        Q1.pop();
        return res.getInteger();
    }
    
    bool hasNext() {
        return !Q1.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */