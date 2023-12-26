// Leetcode Link => https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Date => 26/12/2023


//Approach-1 (Recur + Memo) - It's Just Like coin change-2 (Only in this qn, assume that coin has k faces having different values)
//T.C : O(n*target*k) (But without memoization - it will be O(k^n)
//S.C : O(31*1001) ~= O(1)
class Solution {
public:
    int m=1e9+7;
    int t[31][1001];
    int Solve(int n,int k,int target)
    {
        if(n==0 && target==0)
        {
            return t[target][n]=1;
        }
        if(target<0 || !n)
        {
            return 0;
        }
        if(t[n][target]!=-1)
        {
            return t[n][target];
        }

        // for each dice there is possibility for numbers from 1 to k to occur
        long long ans=0;
        for(int i=1;i<=k;i++)
        {
          ans+=Solve(n-1,k,target-i)%m;
        }
        return t[n][target]=ans%m;
    }
    int numRollsToTarget(int n, int k, int target) 
    {
        // using memorization
        memset(t,-1,sizeof(t));
        int ans=Solve(n,k,target);

        return ans;

    }
};