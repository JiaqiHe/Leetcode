class Solution {
public:
    int findparent(int i, vector<int> &parent){
        if(i != parent[i]) parent[i] = findparent(parent[i], parent);
        return parent[i];
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> parent(n);
        for(int i = 0; i < n; i ++){
            parent[i] = i;
        }
        for(auto p : edges){
            int p_i = findparent(p.first, parent);
            int p_j = findparent(p.second, parent);
            if(p_i != p_j){
                parent[p_i] = p_j;
            } 
        }
        for(int i = 0; i < n; i ++){
            parent[i] = findparent(i, parent);
        }
        unordered_set<int> dict(parent.begin(), parent.end());
        return dict.size();
    }
};
