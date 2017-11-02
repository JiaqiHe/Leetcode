class Solution {
public:
    class Compare {
        public: 
        bool operator() (pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> count;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pri;
        for(int i = 0; i < nums.size(); i ++) count[nums[i]]++;
        for(auto elem : count){
            pri.push(make_pair(elem.second, elem.first));
        }
        for(int i = 0; i < k; i ++){
            pair<int, int> cur = pri.top();
            pri.pop();
            res.push_back(cur.second);
        }
        return res;
    }
};
