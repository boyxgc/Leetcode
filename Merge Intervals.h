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
    struct compare{
        bool operator() (const Interval i1, const Interval i2) {
            return i1.start < i2.start;
        }
    };
    
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> merged;
        if(intervals.empty()) return merged;
        sort(intervals.begin(), intervals.end(), compare());
        
        Interval prev = intervals[0];
        for(int i = 1; i < intervals.size(); ++i) {
            if(isOverlap(prev, intervals[i])) {
                prev.end = max(prev.end, intervals[i].end);
            } else {
                merged.push_back(prev);
                prev = intervals[i];
            }
        }
        merged.push_back(prev);
        
        return merged;
    }
    
    bool isOverlap(Interval &i1, Interval &i2) {
        return !(i1.end < i2.start || i1.start > i2.end);
    }
};