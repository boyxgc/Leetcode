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
    bool same(const Point &p1, const Point &p2){
        return p1.x==p2.x && p1.y==p2.y;
    }
    int maxPoints(vector<Point> &points) {
        if(points.size() == 0) return 0;
        int maxsofar = 1;
        vector<double> slopes;
        
        for(int i = 0; i < points.size(); ++i){
            slopes.clear();
            int dups = 1;
            for(int j = 0; j < points.size(); ++j){
                if(i == j) continue;
                
                Point p1 = points[i];
                Point p2 = points[j];
                if(same(p1, p2)){
                    dups++;
                    continue;
                }
                if(p1.x != p2.x){
                    slopes.push_back((p1.y-p2.y)*1.0/(p1.x-p2.x));
                } else {
                    slopes.push_back(12345.6789);
                }
            }
            sort(slopes.begin(), slopes.end());
            
            int tmpmax = (slopes.size() > 0) ? 1 : 0;
            maxsofar = max(maxsofar, dups+tmpmax);
            for(int i = 1; i < slopes.size(); ++i){
                if(slopes[i] == slopes[i-1])
                    tmpmax++;
                else
                    tmpmax = 1;
                maxsofar = max(maxsofar, tmpmax+dups);
            }
        }
        return maxsofar;
    }
};