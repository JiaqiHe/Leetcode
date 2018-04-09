class Solution {
public:
    double dfs(int a, int b, unordered_map<string, double> &dict) {
        if(a <= 0 && b <= 0) return 0.5;
        else if(a <= 0) return 1.0;
        else if(b <= 0) return 0.0;
        else {
            string str = to_string(a) + "," + to_string(b);
            if(dict.find(str) != dict.end()) return dict[str];
            double ans = 0.25 * (dfs(a-100, b, dict) + dfs(a-75, b-25, dict) + dfs(a-50, b-50, dict) + dfs(a-25, b-75, dict));
            dict[str] = ans;
            return ans;
        }
        
        
    }
    double soupServings(int N) {
        if(N >= 4800) return 1.0;
        unordered_map<string, double> dict;
        return dfs(N, N, dict);
    }
};
