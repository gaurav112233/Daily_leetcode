// LeetCode Link => https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// Date => 24/12/2023


// Approach 1 => (Two pass solution => (try both ways (start with '1' or start with '0'))
// T.C => O(N)
// S.C => O(1)
class Solution {
public:
    int minOperations(string s) 
    {
        // lets go one by one
        // string will either start from 0 or 1
        // lets try both ways

       // for start with one we will keep no_of_operations required
       int start_with_one=0;
      // for start with one we will keep no_of_operations required
       int start_with_zero=0;
      int n=s.size();
       for(int i=0;i<n;i++)
       {
           // if index is odd it should contain '0'
          if((i%2))
          {
              if(s[i]=='1')
              {
                  start_with_one++;
              }
          }
          else
          {
              // else index is even it should contain '1'
              if(s[i]=='0')
              {
                   start_with_one++;
              }
          }
       }
       for(int i=0;i<n;i++)
       {
          if((i%2))
          {
              if(s[i]=='0')
              {
                  start_with_zero++;
              }
          }
          else
          {
              if(s[i]=='1')
              {
                   start_with_zero++;
              }
          }
       }

       return min( start_with_zero, start_with_one);

    }
};


// Approach 2 => (one pass solution)
// T.C => O(N)
// S.C => O(1)
class Solution {
public:
    int minOperations(string s) 
    {
        // optimised approach 
        // by observation we can conclude that 

       
        //  For a given s, if we need start0 operations to create the alternating string that starts with 0, we will need exactly (n - start0) operations to create the alternating string that starts with 1.
         int start0 = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '1') {
                    start0++;
                }
            } else {
                if (s[i] == '0') {
                    start0++;
                }
            }
        }
        
        return min(start0, (int) s.size() - start0);



    }
};