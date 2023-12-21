static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Min heat approach
// Time complexity = O(log(N))
class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> available_seats;
    SeatManager(int n) {
        
        for(int i=1;i<=n;i++) available_seats.push(i);
    }
    
    int reserve() {
        int seat = available_seats.top();
        available_seats.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        available_seats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */