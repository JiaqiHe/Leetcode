class Solution {
public:
    /*
    * 思路如下：
    * 首先创建一个map1，source-> (target, time)
    * 从规定的起始点开始，放到一个queue里面
    * 创建一个用来存node -> time的map2
    * 做bfs，查看当前节点能到达的其他点，算一下从这个点到下一个点的时间，如果在map2里没有目标点或者当前记录的时间长于从当前节点出发的时间，那么说明我们要将这个节点放入queue，用于稍后的更新
    * 一直做下去，把queue做到空
    */
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(times.empty()) return 0;
        unordered_map<int, vector<pair<int, int>>> dict;// soucre -> (target, time)
        for(auto vec : times) {
            dict[vec[0]].push_back(make_pair(vec[1], vec[2]));
        }
        queue<pair<int, int>> q;
        q.push(make_pair(K,0));
        unordered_map<int, int> transtime;
        transtime[K] = 0;
        while(!q.empty()) {
            pair<int, int> source = q.front();
            int curTime = source.second;
            q.pop();
            for(auto p : dict[source.first]) {
                if(transtime.find(p.first) == transtime.end() || transtime[p.first] > curTime + p.second) {
                    // never visited this node OR time is shorter
                    transtime[p.first] = curTime + p.second;
                    q.push(make_pair(p.first, transtime[p.first]));
                }
            }
        }
        if(transtime.size() != N) return -1;
        int res = 0;
        for(auto p : transtime) res = max(res, p.second);
        return res;
    }
};
