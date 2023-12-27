// Leetcode Link => https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
// Date => 27/12/2023


//Approach - Greedily moving ahead
//T.C : O(n)
//S.C : O(1)

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        // using simple traversal
        int n=colors.size();
        int ans=0;

        for(int i=0;i<(n-1);i++)
        {
            if(colors[i]==colors[i+1])
            {
            ans+=min(neededTime[i],neededTime[i+1]);
            // update this value because neededTime[i+1] because it may be possible 
            // neededTime[i+1] may be minimum so we may have cleared [i+1] ballon
            // and new time will be max of time required to remove the ballon
            neededTime[i+1]=max(neededTime[i],neededTime[i+1]);
            }
        }

        return ans;
    }
};