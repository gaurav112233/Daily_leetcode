// LeetcodeLink => https://leetcode.com/problems/largest-odd-number-in-string
// Date => 7/12/2023

// Approach 1 => (using extra string)
// T.C => O(n)
// S.C => O(n)
class Solution {
public:
    string largestOddNumber(string num) 
    {
        // simple approach
        // whenever current digit is odd
        // update the max_odd number
        string ans="";
        string other="";
        for(int i=0;i<num.size();i++)
        {
            int digit=num[i]-'0';
            other+=num[i];
            if(digit%2!=0)
            {
                // current digit is odd
               ans=other;
            }
        }

        return ans;
    }
};


// Approach 2 
// T.C => O(n)
// S.C => O(1)
class Solution {
public:
    string largestOddNumber(string num) 
    {
      // as only last digit determines if the number is odd
      // so we can get first odd digit from back and return ans from start to that index
       for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        
        return "";

    }
};
