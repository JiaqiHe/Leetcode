class Solution {
public:
    bool canGenerate(string s, unordered_map<char, int> &dict){
        for(int i = 0; i < s.length(); i ++){
            dict[s[i]]++;
        }
        int odd = 0;
        for(auto elem : dict){
            if(elem.second % 2 == 1) odd++;
        }
        return odd <= 1;
    }
    
    void generate(unordered_map<char, int> dict, unordered_map<char, int> &tdict, vector<string> &res, string cur, string &tcur, string odd){
        if(dict.empty()){
            string result = cur + odd;
            reverse(cur.begin(), cur.end());
            result += cur;
            res.push_back(result);
            return;
        }
        for(auto elem : dict){
            tcur = cur;
            tdict = dict;
            tcur += elem.first;
            if(elem.second == 1){
                tdict.erase(elem.first);
                generate(tdict, tdict, res, tcur, tcur, odd);
            }
            else {
                tdict[elem.first]--;
                generate(tdict, tdict, res, tcur, tcur, odd);
            }
        }
    }
    
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> dict;
        if(!canGenerate(s, dict)) return res;
        else{
            //we can generate palindromes
            //first, extract odd element, if possible, and divide number by 2
            string odd = "";
            for(auto elem : dict){
                if(elem.second % 2 == 1){
                    odd += elem.first;
                    dict[elem.first]--;
                    if(dict[elem.first] == 0) dict.erase(elem.first);
                    break;
                }
            }
            for(auto elem : dict){
                dict[elem.first] /= 2;
            }
            for(auto elem : dict){
                cout<<elem.first<<" "<<elem.second<<endl;
            }
            //generate strings
            string cur = "";
            generate(dict, dict, res, cur, cur, odd);
            return res;
        }
    }
};
