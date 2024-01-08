// Leetcode Link => https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// Date => 7/1/2024

//T.C : O(n^2)
//S.C : O(n^2) - because of the 2D array mp, where each row mp[i] represents a different index in the input vector nums
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        // using DP
        // using unordered_map 
        // for current element we are asking previous A.P s if there is 
        // previous A.P with same common difference as current

        // mp stores {d,f}
        // i.e d=common difference, f=frequency
        // Also we need to store corresponding to each index how many A.P are there with common difference "d"
        // E.g mp[j][diff] => It means at index j how manp A.p s are there with difference d
        int result=0;
        int n=nums.size();
        unordered_map<long,int> mp[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                // we ensure three elements by nums[i],nums[j] and previous diff 
                auto diff=(long)nums[j]-nums[i];
                auto it=mp[j].find(diff);
                // if current common difference is not found it will point to end so count_at_j=0 or if diff is found then 
                // then at index j there is count_at_j no of A.ps with differnce "diff"
                int count_at_j = it == mp[j].end() ? 0 :mp[j][diff];
                

                mp[i][diff]+=count_at_j+1;

                result+=count_at_j;


            }
        }

        return result;


    }
};