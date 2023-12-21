// Leetcode Link => https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points
// Date => 21/12/2023



// Approach 1 => Using sorting
// T.C => O(n logn)
// S.c => O(1)
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
      // The problem is to find the widest vertical area between any two points without having any other point in between.
      // only x-coordinate is important one 

      // sort according to the x-coordinates

      sort(points.begin(),points.end());
      int ans=INT_MIN;

      for(int i=1;i<points.size();i++)
      {
          ans=max(ans,points[i][0]-points[i-1][0]);
      }

      return ans;
    }
};