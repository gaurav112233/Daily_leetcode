

// Approach 1 => (Based on input and output observation)
// No logic in this approach
// T.C =>0(n)
// S.C =>O(1)

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {

// In order to minimize steps, we should walk most points diagonally. If we cannot make a move then those points should be covered either horizontally or vertically.
// Example : Lets say |x2 - x1| = 5 and |y2 - y1| = 3, then we would walk 3 diagonally and remaining two have to be walked horizontally.
        int ans=0;

        for(int i=1;i<points.size();i++)
        {
              int result=max(abs(points[i][0]-points[i-1][0]),abs(points[i][1]-points[i-1][1]));
              ans+=result;
        }
        return ans;
    }

};


// Approach 2 => (Based on mathematics)
// T.C =>0(n)
// S.C =>O(1)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
// Math.min(deltaX, deltaY) is the steps that we go diagonally.
// Math.abs(deltaX - deltaY) is the steps that we go horizontally or vertically.

     int ans = 0, n = points.size();
        for (int i = 0; i < n-1; i++) {
            int deltaX = abs(points[i+1][0] - points[i][0]); 
            int deltaY =abs(points[i+1][1] - points[i][1]); 
            ans += min(deltaX, deltaY) + abs(deltaX - deltaY);
        }
        return ans;

    }

};