class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int res = 0;
        unordered_map<int, vector<int>> adj;
        for(auto p : edges){
            adj[p.first].push_back(p.second);
            adj[p.second].push_back(p.first);
        }
        vector<bool> visited(n, false);
        queue<int> que;
        for(int i = 0; i < n; i ++){
            if(visited[i]) continue;
            else{
                res++;
                que.push(i);
                visited[i] = true;
                while(!que.empty()){
                    int cur = que.front();
                    que.pop();
                    for(auto elem : adj[cur]){
                        if(!visited[elem]){
                            visited[elem] = true;
                            que.push(elem);
                        }
                    }
                }
            }
        }
        return res;
    }
};
