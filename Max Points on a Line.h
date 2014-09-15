/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() <  3) return points.size();
        
        int maxnum = 1;
        for(int i = 0; i < points.size(); ++i) {
            vector<double> slopes;
            int dups = 1;
            int v_points = 0;
            for(int j = 0; j < points.size(); ++j) {
                if(i == j) continue;
                Point & p1 = points[i];
                Point & p2 = points[j];
                if(p1.x == p2.x && p1.y == p2.y) {
                    dups++;
                } else {
                    if(p1.x == p2.x) {
                        v_points++;
                    } else {
                        slopes.push_back((p1.y-p2.y)*1.0/(p1.x-p2.x));
                    }
                }
            }
            int currmax = v_points;
            if(!slopes.empty()) {
                sort(slopes.begin(), slopes.end());
                int count = 1;
                for(int i = 1; i < slopes.size(); ++i) {
                    if(equals(slopes[i],slopes[i-1])) {
                        count++;
                    } else {
                        currmax = max(currmax, count);
                        count = 1;
                    }
                }
                currmax = max(currmax, count);
            }
            maxnum = max(maxnum, currmax + dups);
        }
        
        return maxnum;
    }
    
    double equals(double d1, double d2) {
        return (abs(d1-d2) < 0.000001);
    }
};