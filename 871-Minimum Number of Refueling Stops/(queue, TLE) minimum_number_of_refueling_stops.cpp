class Solution {
public:
    struct status {
        int pos;
        int fuel;
        int stops;
        int stop_index;
        
        status(int pos, int fuel, int stops, int stop_index) {
            this->pos = pos;
            this->fuel = fuel;
            this->stops = stops;
            this->stop_index = stop_index;
        }
    };
    
    /*
    TLE: queue
    */
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        status *start = new status(0, startFuel, 0, -1);
        queue<status*> q;
        q.push(start);
        while(!q.empty()) {
            status *cur =  q.front();
            q.pop();
            int stop_index = cur->stop_index;
            if(cur->pos + cur->fuel >= target) return cur->stops;
            stop_index++;
            while(stop_index < stations.size() && stations[stop_index][0] <= cur->pos + cur->fuel) {
                status *new_status = new status(stations[stop_index][0], 
                                                stations[stop_index][1] + cur->fuel - (stations[stop_index][0] - cur->pos), 
                                                cur->stops + 1, 
                                                stop_index);
                q.push(new_status);
                stop_index++;
            }
        }
        return -1;
    }
}
