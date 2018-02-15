class Solution {
public:
    struct compare {
        bool operator()(pair<string, int> a, pair<string, int> b) {
            if(a.second != b.second) return b.second < a.second;
            else return b.first > a.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
        unordered_map<string, int> dict;
        for(auto word : words) {
            dict[word]++;
        }
        for(auto p : dict) {
            if(pq.size() < k) {
                pq.push(p);
            }
            else {
                pq.push(p);
                while(pq.size() > k) pq.pop();
            }
        }
        vector<string> res;
        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//time complexity: O(n + nlogk)
//space complexity: O(n + k)
