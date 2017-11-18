class Solution {
public:
    int sq_length(vector<int>& p1, vector<int>& p2){
        return pow(p1[0]-p2[0], 2) + pow(p1[1]-p2[1], 2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> edges;
        edges.insert(sq_length(p1, p2));
        edges.insert(sq_length(p1, p3));
        edges.insert(sq_length(p1, p4));
        edges.insert(sq_length(p2, p3));
        edges.insert(sq_length(p2, p4));
        edges.insert(sq_length(p3, p4));
        if(edges.size() != 2) return false;
        else{
            int a = 0, b = 0;
            for(auto elem : edges){
                // cout<<elem<<" ";
                if(a == 0) a = elem;
                else b = elem;
            }
            return a*2 == b || b*2 ==a;
        }
    }
};
