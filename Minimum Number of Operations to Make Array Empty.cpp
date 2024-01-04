// Leetcode Link => https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
// Date => 4/1/2024


// Approach => (by using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        unordered_map<int,int>  mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        int ans=0;
        for(auto it:mp)
        {
            // If the element is present only once it is not possible to apply 
            // any operations to make it empty so return -1;
            if(it.second==1)
            {
                return -1;
            }
            if(it.second%3==0)
            {
                ans+=(it.second/3);
            }
            else 
            {
                ans+=(it.second/3);
                // extra +1 for remaining values or count(1,2)
                ans++;
            }
           
        }
        return ans;
    }
};