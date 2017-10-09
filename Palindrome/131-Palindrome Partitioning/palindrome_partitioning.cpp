class Solution {
public:
    vector<vector<string>> res;
    vector<string> temp;
    void part(string s, int index, vector<string> &temp){
        if(index == s.length()){
            res.push_back(temp);
            return;
        }
        for(int i = index; i < s.length(); i++){
            int left = index, right = i;
            while(left < right && s[left] == s[right]) left++, right--;
            if(left >= right){
                temp.push_back(s.substr(index, i-index+1));
                part(s, i+1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        part(s, 0, temp);
        return res;
    }
};
