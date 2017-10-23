class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty()) return 0;
        vector<int> chara(26,0);
        for(int i = 0; i < tasks.size(); i ++) chara[tasks[i]-'A']++;
        sort(chara.begin(), chara.end());
        int ptr = 25;
        while(ptr>=0 && chara[ptr] == chara[25]) ptr--;
        int res = (chara[25]-1)*(n+1)+25-ptr;
        int len = tasks.size();
        return max(res, len);
    }
};
