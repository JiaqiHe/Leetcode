class Solution {
public:
    void dfs(unordered_map<int, vector<int>> adj, int s, vector<bool> &visited){
        visited[s] = true;
        for(auto elem : adj[s]){
            if(!visited[elem]) dfs(adj, elem, visited);
        }
        return;
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int res = 0;
        unordered_map<int, vector<int>> adj;
        for(auto p : edges){
            adj[p.first].push_back(p.second);
            adj[p.second].push_back(p.first);
        }
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i ++){
            if(!visited[i]){
                res++;
                dfs(adj, i, visited);
            }
        }
        return res;
    }
};
