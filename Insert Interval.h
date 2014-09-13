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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> merged;
        
        bool isInserted = false;
        for(int i = 0; i < intervals.size(); ++i) {
            Interval intv = intervals[i];
            if(isOverlapped(newInterval, intv)) {
                newInterval.start = min(newInterval.start, intv.start);
                newInterval.end = max(newInterval.end, intv.end);
            } else {
                if(!isInserted && intv.start > newInterval.end) {
                    merged.push_back(newInterval);   
                    isInserted = true;
                }
                merged.push_back(intv);
            }
        }
        
        if(!isInserted) merged.push_back(newInterval);
        
        return merged;
    }
    
    bool isOverlapped(Interval & i1, Interval & i2) {
        return !((i1.end < i2.start) || (i2.end < i1.start));
    }
};