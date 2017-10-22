class Solution {
public:   
    static bool myComp(pair<int, int> a, pair<int, int> b){
        if(a.first != b.first) return a.first > b.first;
        else return a.second < b.second;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        if(people.empty()) return people;
        sort(people.begin(), people.end(), myComp);
        vector<pair<int, int>> res;
        for(int i = 0; i < people.size(); i ++){
            res.insert(res.begin()+people[i].second, people[i]);
        }
        return res;
    }
};
