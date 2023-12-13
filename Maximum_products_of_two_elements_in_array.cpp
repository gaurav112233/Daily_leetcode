
// Leetcode Link => https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array
// Date => 12/12/2023


// Approach 1 => (Using sorting)
// T.C=> O(nlogn)
// S.C => O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
       sort(nums.begin(),nums.end());
       int n=nums.size();

       return (nums[n-1]-1)*(nums[n-2]-1);

    }
};


// Approach 2 => (find max and next max)
// T.C=> O(n)
// S.C => O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
       int first_max=0;
       int second_max=0;

       for(auto it:nums)
       {
        // if it>first_max we have found new max so update second max and first max as well
        if(it>first_max)
        {
            second_max=first_max;
            first_max=it;
        }
        else
        {
            // first max is same lets check for second max
            second_max=max(second_max,it);
        }
       }

       return (first_max-1)*(second_max-1);

    }
};


//Approach-1 (Keep finding the max current number)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int maxNum = nums[0];
        int result = 0;
        
        for(int i = 1; i<n; i++) {
            result = max(result, (maxNum-1)*(nums[i]-1));
            maxNum = max(maxNum, nums[i]);
        }
        
        return result;
    }
};

