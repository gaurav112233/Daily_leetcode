// LeetCode Link => https://leetcode.com/problems/longest-increasing-subsequence/
// Date => 5/1/20204


// Approach 1 => using recursion
// T.C => O(2^N)
// S.C => O(N)
class Solution {
public:
    void Solve(vector<int>& nums,int ind,int length,int* ans,int prev)
    {
        if(ind==nums.size())
        {
           *ans=max(*ans,length);
           return;
        }

        // pick the element
        // we can only pick element if it is greater than previous element taken
        // Take
        if(nums[ind]>prev)
        {
            Solve(nums,ind+1,length+1,ans,nums[ind]);
        }
        // don't take
        Solve(nums,ind+1,length,ans,prev);


    }
    int lengthOfLIS(vector<int>& nums) 
    {
       // brute force approach using recursion
       // for each element we can either take it in the subsequence or not
       // pick or not pick

       int ans=INT_MIN;
       int prev=INT_MIN;
       int len=0;
       Solve(nums,0,len,&ans,prev);
       return ans;
    }
};

// Approach 1 => using recursion
// T.C => O(2^N)
// S.C => O(N)
class Solution {
public:
    int Solve(vector<int>& nums,int ind,int prev)
    {
        if(ind==nums.size())
        {
            return 0;
        }

        // pick or non_pick
        // non_pick
        int not_take=Solve(nums,ind+1,prev);

        // pick 
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev])
        {
           take=1+Solve(nums,ind+1,ind);
        }

        return max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        // Recursion approach
        return Solve(nums,0,-1);
    }
};


// Approach 2=> using recursion + memorization
// T.C => O(N^2)
// S.C => O(N)
class Solution {
public:
   int t[2501][2501];
    int Solve(vector<int>& nums,int ind,int prev)
    {
        if(ind==nums.size())
        {
            return 0;
        }
        if(prev!=-1 && t[ind][prev]!=-1)
        {
            return t[ind][prev];
        }

        // pick or non_pick
        // non_pick
        int not_take=Solve(nums,ind+1,prev);

        // pick 
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev])
        {
           take=1+Solve(nums,ind+1,ind);
        }
        if(prev!=-1)
        t[ind][prev]=max(take,not_take);

        return max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        // Recursion + Memorization
        memset(t,-1,sizeof(t));
        return Solve(nums,0,-1);
    }
};
