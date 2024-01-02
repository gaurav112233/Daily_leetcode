// Leetcode Link => https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
// Date => 2/1/2024

//Approach (Using frequency of elements)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
       unordered_map<int,int> mp;
       vector<vector<int>> ans;

       // here we will push the current element in vector where vec[it] is its count of occurence till ith index (i-1)th vec

       for(auto it:nums)
       {
           // if curr element frequency is equal to 2D vector size
           // we need to create new vector
           if(mp[it]==ans.size())
           {
               ans.push_back({});
           }

           // Store the integer in the list corresponding to its current frequency
           ans[mp[it]].push_back(it);
           // update the curr element frequency
           mp[it]++;
       }
       return ans;
    }
};