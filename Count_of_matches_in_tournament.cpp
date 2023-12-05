// Leetcode Link => https://leetcode.com/problems/count-of-matches-in-tournament
// Date => 5/12/2023

// Approach 1 => (using simulation)
// Do what the question says
// T.C => O(logn)
// S.C => O(1)
class Solution {
public:
    int numberOfMatches(int n) 
    {
        // using brute force approach
        // Just do what question says
        int ans=0;
        while(n>1)
        {
          if(n%2==0)
          {
            ans+=(n/2);
            n=n/2;
          }
          else
          {
              ans+=(n-1)/2;
              n=(n-1)/2+1;
          }
        }

        return ans;
    }
};

// Approach 2 => (Logic)
// T.C =>O(1)
// S.C => O(1)
// There are n teams, and 1 winner. Thus, n - 1 teams will be eliminated.
// Each match is played between two teams. One team wins, one team loses. 
// Thus, each match eliminates exactly one team.
// As n - 1 teams will be eliminated, there will be n - 1 matches played, 
// with each match eliminating a team.

class Solution {
public:
    int numberOfMatches(int n) 
    {
        return n-1;
    }
};