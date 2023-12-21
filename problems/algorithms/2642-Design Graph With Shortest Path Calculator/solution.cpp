static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
// Dijkstra's algorithm + priority queue
// Time complexity = O(V+E*log(E)), Space complexity = O(V+E)
// Time = 135ms (beats 97.48%), Memory = 76.14MB (beats 73.95%)
class Graph {
public:
    int n_nodes;
    vector<vector<pair<int,int>>> next;
    Graph(int n, vector<vector<int>>& edges) {
        next = vector<vector<pair<int,int>>>(n,vector<pair<int,int>>());// reverse graph
        n_nodes = n;
        for(auto &edge : edges){
            next[edge[0]].push_back(pair<int,int>{edge[1],edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        next[edge[0]].push_back(pair<int,int>{edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(n_nodes,INT_MAX);// dist[i] = unknown shortest distance from node1 to i
        dist[node1] = 0;
        auto compare = [](pair<int,int> &left, pair<int,int> &right){return left.second>right.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(compare)> Q;
        
        Q.push(pair<int,int>{node1,0});
        
        while(!Q.empty()){
            auto node = Q.top();
            Q.pop();
            if(node.second>dist[node.first]) continue;
            if(node.first==node2) return node.second==INT_MAX?-1:node.second;
            for(auto &neighbor : next[node.first]){
                int len = neighbor.second + dist[node.first];
                if(len<dist[neighbor.first]){
                    dist[neighbor.first] = len;
                    Q.push(pair<int,int>{neighbor.first,dist[neighbor.first]});
                }
            }
        }
        return dist[node2]==INT_MAX?-1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */