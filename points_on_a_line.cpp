

/****
Now comes the idea to solve this problem. 
We start from a specific point p, and compute all the slopes of the lines between p and the remaining points. 
Then those with the same slopes will be the same line. 
We can find out the maximum number of points fall on a line containing p. 
We exhaust all possible p's and record the largest number we have seen. This number is just answer.
Well, there are still two special cases to handle:

Duplicate points: a pair of duplicate points give no determined line, so we just count the number of duplicates and add them to the result.
Vertical lines: the slope of these lines is infinity mathematically. We simply set it to be INT_MAX in the following code.
Now we have the following code, using an unordered_map<float, int> slopes to record how many points fall in the line of a specific slope and containing points[i]. Since all the operations of unordered_map is O(1), this code is of O(n^2) complexity.
****/


class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<float, int> slopes;
        int maxp = 0, n = points.size();
       
        for (int i = 0; i < n; i++) 
		{
            slopes.clear();
            int duplicate = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicate++;
                    continue;
                }
                float slope = (points[j].x == points[i].x) ? INT_MAX : 
                              (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                slopes[slope]++;
            }
            maxp = max(maxp, duplicate);
            for (auto slope : slopes)
                if (slope.second + duplicate > maxp) 
                    maxp = slope.second + duplicate; 
        }
        return maxp;
    }
};