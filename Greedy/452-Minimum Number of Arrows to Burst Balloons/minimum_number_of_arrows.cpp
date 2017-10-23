class Solution {
public:
    static bool myComp(pair<int,int> a, pair<int, int> b){
        if(a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    }
    
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end(), myComp);
        int res = 1;
        int ptr = points[0].second;
        for(int i = 0; i < points.size(); ){
            while(i < points.size() && points[i].first <= ptr) i++;
            if(i == points.size()) break;
            res++;
            ptr = points[i].second;
        }
        return res;
    }
};
