class Solution {
public:
    /*
    greedy
    */
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stop_pos = 0;
        int res = 0;
        int stop_index = 0;
        int cur_fuel = startFuel;
        priority_queue<int> pq;
        
        while(stop_pos < target) {
            stop_pos += cur_fuel;
            if(stop_pos >= target) return res;
            while(stop_index < stations.size() && stations[stop_index][0] <= stop_pos) {
                pq.push(stations[stop_index++][1]);
            }
            if(pq.empty()) {
                return -1;
            }
            else {
                cur_fuel = pq.top();
                pq.pop();
            }
            res++;
        }
        return res;
    }
}
