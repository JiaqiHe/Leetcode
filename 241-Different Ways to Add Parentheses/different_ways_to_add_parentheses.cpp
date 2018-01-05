namespace std {
        template <> struct hash<pair<int, int>> {
            inline int operator ()(const pair<int, int> &p) const {
                hash<int> int_hasher;
                return int_hasher(p.first) + int_hasher(p.second);
            }
        };
    }
class Solution {
public:
    vector<int> divide(string input, int begin, int end, unordered_map<pair<int, int>, vector<int>> &dict) {
        vector<int> res;
        if(begin > end) return res;
        if(dict.find(make_pair(begin, end)) != dict.end()) return dict[make_pair(begin, end)];
        for(int i = begin; i <= end; i ++){
            if(!isdigit(input[i])) {
                vector<int> left = divide(input, begin, i - 1, dict);
                vector<int> right = divide(input, i + 1, end, dict);
                for(auto l : left) {
                    for(auto r : right) {
                        if(input[i] == '+') res.push_back(l + r);
                        else if(input[i] == '-') res.push_back(l - r);
                        else if(input[i] == '*') res.push_back(l * r);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(input.substr(begin, end - begin + 1)));
        dict[make_pair(begin, end)] = res;
        return res;
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if(input.empty()) return res;
        unordered_map<pair<int, int>, vector<int>> dict;
        return divide(input, 0, input.length() - 1, dict);
    }
};
