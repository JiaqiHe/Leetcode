/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool myComp(Interval a, Interval b){
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), myComp);
        vector<int> room;
        for(int i = 0; i < intervals.size(); i ++){
            int j = 0;
            for(j = 0; j < room.size(); j ++){
                if(intervals[i].start >= room[j]){
                    room[j] = intervals[i].end;
                    break;
                }
            }
            if(j >= room.size()) room.push_back(intervals[i].end);
        }
        return room.size();
    }
};
