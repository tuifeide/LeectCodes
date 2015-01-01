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
        int max = 2;
        int cur = 2;
        int k1 = 0, k2 = 0, s = 0, b1 = 0, b2 = 0;
        bool t = true;
        
        if(points.size() < 3) {
            return points.size();
        }
        
        vector<Point>::iterator it1 = points.begin();
        vector<Point>::iterator it2 = it1 + 1;
        vector<Point>::iterator it3 = it2 + 1;
        
        while(it1 != points.end()) {
            it2 = it1 +1;
            s = 1;
            while(it2 != points.end()) {
                if((*it1).x == (*it2).x) {
                    if((*it1).y == (*it2).y) {
                        s ++;
                        it2 ++;
                        continue;
                    }
                    else {
                        t = false;
                    }
                }
                else {
                    t = true;
                    k1 = (*it1).y - (*it2).y;
                    k2 = (*it1).x - (*it2).x;
                }
                it3 = it2 + 1;
                cur = 1 + s;
                while(it3 != points.end()) {
                    if(!t) {
                        if ((*it3).x == (*it2).x) {
                            cur ++;
                        }
                    }
                    else {
                        b1 = (*it1).y - (*it3).y;
                        b2 = (*it1).x - (*it3).x;
                        if(k1 * b2 == k2 * b1) {
                            cur ++;
                        }
                    }
                    it3 ++;
                }
                if(cur > max) {
                    max = cur;
                }
                it2 ++;
            }
            if(s > max) {
                max = s;
            }
            it1 ++;
        }
        return max;
    }
};
