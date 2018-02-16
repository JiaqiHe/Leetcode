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
    static bool compare(Interval a, Interval b) {
        if(a.start != b.start) return a.start < b.start;
        else return b.end < a.end;
    };
    
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int ptr = 0;
        for(int i = 1; i < intervals.size(); i ++) {
            if(intervals[i].start <= intervals[ptr].end) {
                intervals[ptr].end = max(intervals[ptr].end, intervals[i].end);
            }
            else {
                intervals[++ptr] = intervals[i];
            }
        }
        while(intervals.size() > ptr + 1) intervals.pop_back();
        return intervals;
    }
};

//time complexity: O(nlogn)
