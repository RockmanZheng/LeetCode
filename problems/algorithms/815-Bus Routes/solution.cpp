static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Breadth first search + Queue + Layer indicator
// Time complexity = O(N)
// Time = 142ms (98.60%), Memory = 67.46MB (beats 69.15%)
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        int n_route = routes.size();
        //for(auto &route:routes){// sort route first (not necessary?)
        //    sort(route.begin(),route.end());
        //}
        vector<bool> visited_route(n_route,false);
        unordered_map<int,bool> visited_stop;
        unordered_map<int,vector<int>> adj;// adj[i] is a list of routes that pass bus stop i
        for(int i=0;i<n_route;i++){
            for(const int &stop : routes[i]){
                adj[stop].push_back(i);
                
            }
        }
        queue<int> Q;
        for(const int &route:adj[source]){
            Q.push(route);
            visited_route[route]=true;
        }
        Q.push(-1);// layer indicator
        int res=1;
        while(Q.size()>1){
            int route = Q.front();
            Q.pop();
            if(route==-1){// encounter a layer indicator
                res++;// increase layer count
                Q.push(-1);// push the layer indicator back to indicate the next layer
                continue;
            }
            
            // push all connected routes
            for(const int &stop:routes[route]){
                // check if target is in this route
                if(stop == target) return res;
                if(visited_stop.count(stop)) continue;// skip visited stop to further save time
                else visited_stop[stop] = true;
                for(const int &another_route:adj[stop]){
                    if(!visited_route[another_route]){
                        visited_route[another_route] = true;
                        Q.push(another_route);
                    }
                }
            }
        }
        return -1;
    }
};