

//  Date => 25/11/2023
//  Leetcode Link =>https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/


// Approach 1 => Brute Force approach
// T.C => O(N^2)
// S.c => O(1)  [TLE]
class Solution 
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
         vector<int> ans;

         int n=nums.size();
         

         for(int i=0;i<n;i++)
         {
             int distance=0;
            for(int j=0;j<n;j++)
            {
                distance+=(abs(nums[j]-nums[i]));
            }
            ans.push_back(distance);
         }

         return ans;
    }
}

// Approach 2 => Using prefix sum
// T.C => O(n)
// S.C => O(n) [for prefix sum]
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        int n=nums.size();
      // using prefix sum
      // Lets scale down our solution using maths
      // for nums[i] the answer is
      // result[i]=abs(nums[i]-nums[0])+abs(nums[i]-nums[1])+abs(nums[i]-nums[2])+......+abs(nums[i]-nums[i-1]) +abs(nums[i]-nums[i-1])+abs(nums[i]-nums[i+1])+...+(nums[i]-nums[n-1])

      // Now as array is sorted till nums[i-1] no need to take absolute difference
      // also from i+1 till n-1 always nums[i+1] > nums[i]
      // so we can take nums[i+1] as first and remove abs

      // now modified answer is result[i]=(nums[i] - nums[0]) + (nums[i] - nums[1]) + ... + (nums[i] - nums[i-1]) + (nums[i+1] - nums[i]) + (nums[i+2] - nums[i]) + ... + (nums[n-1] - nums[i]).

      // It can be simplified to 
      // result[i]=(nums[i]*i)-(nums[0]+nums[1]+..nums[i-1])+(nums[i+1]+nums[i+2]+....nums[n-1])+(n-i-1)*(nums[i])

      // result[i]=[(nums[i]*i)-(0 to i-1 ka sum)]+[(i+1 to n-1 ka sum)-(nums[i]*(n-i-1))]

      vector<int> prefixsum(n);
      vector<int> result(n);

      prefixsum[0]=nums[0];
      for(int i=1;i<n;i++)
      {
        prefixsum[i]=prefixsum[i-1]+nums[i];
      }

// now to get sum till i-1 we can do prefixsum[i]-nums[i]
// also to get sum from i+1 to n-1  prefixsum[n-1]-prefix[i]
for(int i=0;i<n;i++)
{
    int leftSum   = prefixsum[i] - nums[i];
    int rightSum  = prefixsum[n-1] - prefixsum[i];

      int leftCount  = i;
      int rightCount = n-i-1;
            
      int leftTotal  = (leftCount * nums[i]) - leftSum;
      int rightTotal = rightSum - (nums[i]*rightCount);
            
       result[i] = leftTotal + rightTotal;
}
return result;

    }
    
};


// Approach 3 => Using prefix sum
// T.C => O(n)
// S.C => O(1)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
      // withouth using extra space 
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);

        vector<int> result(n);
        int prefixSum = 0;

        for(int i=0;i<n;i++)
        {
            int leftSum=prefixSum;
            int rightSum=sum-prefixSum-nums[i];

             int leftCount  = i;
            int rightCount = n-i-1;
            
            int leftTotal  = (leftCount * nums[i]) - leftSum;
            int rightTotal = rightSum - (nums[i]*rightCount);
            
            result[i] = leftTotal + rightTotal;
            prefixSum += nums[i];

        }

        return result;

    }
    
};

