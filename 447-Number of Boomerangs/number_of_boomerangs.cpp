class Solution {
public:
    int dis(pair<int, int> a, pair<int, int> b){
        return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
    }
    
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if(points.empty()) return 0;
        int res = 0;
        int n = points.size();
        for(int i = 0; i < n; i ++){
            unordered_map<int, int> distance;
            for(int j = 0; j < n; j ++){
                if(j == i) continue;
                distance[dis(points[i], points[j])]++;
            }
            for(auto elem : distance){
                if(elem.second > 1) res += elem.second * (elem.second-1);
            }
        }
        return res;
    }
};
