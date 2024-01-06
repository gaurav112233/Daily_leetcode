// Leetcode Link => https://leetcode.com/problems/maximum-profit-in-job-scheduling/
// Date => 6/1/2024

// Approach 1 => Recursion [TLE]
// T.C => O(2^N)
// S.C => O(N)
class Solution {
public:
    static bool comp(vector<int>& vec1,vector<int> & vec2)
    {
        return vec1[0]<=vec2[0];
    }
    int Solve(vector<vector<int>> array,int ind,int prev)
    {
        if(ind==array.size())
        {
            return 0;
        }

        // not take
        int not_take=Solve(array,ind+1,prev);

        // Take
        // we can only take current job if the start time of current job is greater tham or equal to current time of previous job
        int take=0;
        if(prev==INT_MIN || array[ind][0]>=prev)
        {
         take=array[ind][2]+Solve(array,ind+1,array[ind][1]);
        }

        return max(take,not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        // using recursion
        // brute force approach
        // Either we can take current job or ignore it
        // standard pick or non-pick question

        // Sort the job based on starting time
        // to do this we can create separate array of array where each index represent a array which consists {s,e,p} [starting time,ebding time , profit] of that particular job
        int n=startTime.size();
        vector<vector<int>> array(n,vector<int> (3,0));

        for(int i=0;i<n;i++)
        {
            array[i][0]=startTime[i];
            array[i][1]=endTime[i];
            array[i][2]=profit[i];
        }

        // now sort the job based on start time
        int prev=INT_MIN;
        sort(array.begin(),array.end(),comp);
        
        return Solve(array,0,prev);


    }
};


// Approach 2 => (Using LIS method) [TLE] [recursion + memorization]
// (go through each possibility of take or not take)
// T.C  => O(N^2)
// S.C => O(N)
  
class Solution {
public:
    
    static bool comp(vector<int>& vec1,vector<int> & vec2)
    {
        return vec1[0]<=vec2[0];
    }
    int Solve(vector<vector<int>> &array,int ind,int prev,int n,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }

       if(prev!=-1 && dp[ind][prev]!=-1)
       {
           return dp[ind][prev];
       }
        // not take
        int not_take=Solve(array,ind+1,prev,n,dp);

        // Take
        // we can only take current job if the start time of current job is greater tham or equal to current time of previous job
        int take=0;
        if(prev==-1 || array[ind][0]>=array[prev][1])
        {
         take+=array[ind][2]+Solve(array,ind+1,ind,n,dp);
        }
        if(prev!=-1)
        {
            dp[ind][prev]=max(take,not_take);
        }
        return max(take,not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        // using recursion
        // brute force approach
        // Either we can take current job or ignore it
        // standard pick or non-pick question
        

        // Sort the job based on starting time
        // to do this we can create separate array of array where each index represent a array which consists {s,e,p} [starting time,ebding time , profit] of that particular job 
      
        int n=startTime.size();
         vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<vector<int>> array(n,vector<int> (3,0));
    
        for(int i=0;i<n;i++)
        {
            array[i][0]=startTime[i];
            array[i][1]=endTime[i];
            array[i][2]=profit[i];
        }

        // now sort the job based on start time
        int prev=-1;
        // memset(t,-1,sizeof(t));
        sort(array.begin(),array.end(),comp);
        // memset(t,-1,sizeof(t));
        return Solve(array,0,prev,n,dp);


    }
};


// Approach 3 => (Using recursion + memorization + linear_search)
// T.C => O(N^2)
// S.C => O(N)
class Solution {
public:
    static bool comp(vector<int>& vec1,vector<int> & vec2)
    {
        return vec1[0]<=vec2[0];
    }
    int findNext(int ind,vector<vector<int>>& array)
{
        int n=array.size();
        for(int i=ind+1;i<n;i++)
        {
            if(array[i][0]>=array[ind][1])
            {
                return i;
            }
        }
        return n+1;
    }
    int Solve(vector<vector<int>>& array,int ind,vector<int>& dp)
    {
        if(ind>=array.size())
        {
            return 0;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        // now find next possible job
        int next=findNext(ind,array);
        int taken=array[ind][2]+Solve(array,next,dp);
        int not_taken=Solve(array,ind+1,dp);
        return dp[ind]=max(taken,not_taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        // optimised approach (recursion + memo + Linear search)
        // Linear search is used for finding next possible job where
        // job start time >= prev selected job end_time

      // Sort the job based on starting time
        // to do this we can create separate array of array where each index represent a array which consists {s,e,p} [starting time,ebding time , profit] of that particular job 
      
        int n=startTime.size();
        vector<int> dp(n, -1);
        vector<vector<int>> array(n,vector<int> (3,0));
    
        for(int i=0;i<n;i++)
        {
            array[i][0]=startTime[i];
            array[i][1]=endTime[i];
            array[i][2]=profit[i];
        }

        sort(array.begin(),array.end(),comp);

        return Solve(array,0,dp);


    }
};


// Approach 4 => (Using recursion + memorization + binary_search)
// T.C => O(N log N)
// S.C => O(N)
class Solution {
public:
    static bool comp(vector<int>& vec1,vector<int> & vec2)
    {
        return vec1[0]<=vec2[0];
    }
    int findNext(int l,vector<vector<int>>& array,int prevjobend)
{
        int n=array.size();
         int r=n-1;
         int ans=n+1;

         while(l<=r)
         {
             int mid=l + (r-l)/2;
             if(array[mid][0]>=prevjobend)
             {
               ans=mid;
               r=mid-1;
             }
             else
             {
                 l=mid+1;
             }
         }
         return ans;
    }
    int Solve(vector<vector<int>>& array,int ind,vector<int>& dp)
    {
        if(ind>=array.size())
        {
            return 0;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        // now find next possible job
        int next=findNext(ind+1,array,array[ind][1]);
        int taken=array[ind][2]+Solve(array,next,dp);
        int not_taken=Solve(array,ind+1,dp);
        return dp[ind]=max(taken,not_taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        // optimised approach (recursion + memo + binary_seacrh)
        // binary_seacrh is used for finding next possible job where
        // job start time >= prev selected job end_time
        // can use binary search because we sorted the array based on start time

      // Sort the job based on starting time
        // to do this we can create separate array of array where each index represent a array which consists {s,e,p} [starting time,ebding time , profit] of that particular job 
      
        int n=startTime.size();
        vector<int> dp(n, -1);
        vector<vector<int>> array(n,vector<int> (3,0));
    
        for(int i=0;i<n;i++)
        {
            array[i][0]=startTime[i];
            array[i][1]=endTime[i];
            array[i][2]=profit[i];
        }

        sort(array.begin(),array.end(),comp);

        return Solve(array,0,dp);


    }
};
