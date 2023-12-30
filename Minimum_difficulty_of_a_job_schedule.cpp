// Leetcode Link => https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// Date => 29/12/2023

//Approach - 1 (Recursion + Memoization)
//T.C : O(n^2*d)
//S.C : O(301*11) ~= O(1)
class Solution {
public:
    int t[301][11];
    int Solve(vector<int>& jd,int n,int idx,int d)
    {
        // base case
        // If there is only 1 day left ,then you have to do all remaining jobs in that one day and find the max difficulty of that day
        if(d==1)
        {
            int maxD=jd[idx];
            for(int i=idx;i<n;i++)
            {
                maxD=max(maxD,jd[i]);
            }
            return maxD;
        }
        if(t[idx][d]!=-1)
        {
            return t[idx][d];
        }


        int maxD=jd[idx];
        int final_result=INT_MAX;
        // Try one by one with all possibility
         /*
            Take 1 job in one day
            Take 2 jobs in one day
            Take 3 jobs in one day
            and so on
            
            Then find the optimal one among all the results
        */

        for(int i=idx;i<=(n-d);i++)
        {
            maxD=max(maxD,jd[i]);
            int result=maxD+Solve(jd,n,i+1,d-1);
            final_result=min(final_result,result);
        }

        return t[idx][d]=final_result;
    }
    int minDifficulty(vector<int>& jd, int d) 
    {
       int n=jd.size();
       if(n<d)
       {
           return -1;
       }
       memset(t,-1,sizeof(t));

       return Solve(jd,n,0,d);

    }
};
