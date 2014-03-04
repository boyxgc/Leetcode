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
    static bool compare(const Interval &p1, const Interval &p2) {
        return p1.start < p2.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        int size = intervals.size();
        if(size == 0)
            return res;
        std::sort(intervals.begin(), intervals.end(), compare);
        int pos = 0;
        while(pos < size) {
            int tmppos = pos+1;
            int tmpstart = intervals[pos].start;
            int tmpend = intervals[pos].end;
            while(tmppos < size && intervals[tmppos].start <= tmpend){
                tmpend = max(intervals[tmppos].end, tmpend);
                tmppos++;
            }
            Interval intv(tmpstart, tmpend);
            res.push_back(intv);
            pos = tmppos;
        }
        return res;
    }
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        intervals.push_back(newInterval);
        res = merge(intervals);
        return res;
    }
};