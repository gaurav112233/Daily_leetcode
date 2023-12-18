// Lettcode Link => https://leetcode.com/problems/maximum-product-difference-between-two-pairs
// Date    => 18/12/2023

// Approach 1 => (sorting)
// T.C => O(n logn)
// S.C => o(1)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) 
    {
//         Because the values of nums are non-negative, we can maximize a product by choosing the two largest elements in nums. Similarly, we can minimize a product by choosing the two smallest elements in nums. Thus, we will choose the following elements:

// a as the largest value in nums.
// b as the second-largest value in nums.
// c as the smallest value in nums.
// d as the second smallest value in nums.
        sort(nums.begin(),nums.end());

        int a=nums[nums.size()-1];
        int b=nums[nums.size()-2];
        int c=nums[0];
        int d=nums[1];
        
        return (a*b)-(c*d);
    }
};

// Approach 2 => (without sorting keeping track in single loop)
// T.C => O(n)
// S.C => o(1)


class Solution {
public:
    int maxProductDifference(vector<int>& nums) 
    {
//         Because the values of nums are non-negative, we can maximize a product by choosing the two largest elements in nums. Similarly, we can minimize a product by choosing the two smallest elements in nums. Thus, we will choose the following elements:

// a as the largest value in nums.
// b as the second-largest value in nums.
// c as the smallest value in nums.
// d as the second smallest value in nums.

// keeep a track of a,b,c,d using single loop
        int a=INT_MIN; // first max
        int b=INT_MIN; // second mac
        int c=INT_MAX;  // first min
        int d=INT_MAX; // second min
        
       for(auto it:nums)
       {
           if(it>a)
           {
               b=a;
               a=it;
           }
           else
           {
               b=max(b,it);
           }

           if(it<c)
           {
               d=c;
               c=it;
           }
           else
           {
               d=min(d,it);
           }
       }

       return (a*b)-(c*d);
    }
};