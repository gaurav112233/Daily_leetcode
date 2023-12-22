// Leetcode Link => https://leetcode.com/problems/maximum-score-after-splitting-a-string
// Date => 22/12/2023


// Approach 1 => (brute force approach)
// T.C => O(N^2)
// S.C => O(1)
class Solution {
public:
    int maxScore(string s) 
    {
        // brute force approach
       // lets try for each substring
       int n=s.size();

       
       int max_score=INT_MIN;

//  till i=n-1 because both substring should have atleast one character
       for(int i=0;i<n-1;i++)
       {
         // now check till i no of zeros
         int zeros=0;
         for(int j=0;j<=i;j++)
         {
            if(s[j]=='0')
            {
                zeros++;
            }
         }
         // now check from i+1 to n no of ones
         int ones=0;
         for(int j=i+1;j<n;j++)
         {
            if(s[j]=='1')
            {
              ones++;
            }
         }

         max_score=max(max_score,zeros+ones);
       }
    
       return max_score;
    }
};


// Approach 1 => brute force approach
// T.C => O(N^2)
// S.C => O(1)
class Solution {
public:
    int maxScore(string s) 
    {
        // brute force approach
       // lets try for each substring
       int n=s.size();

       
       int max_score=INT_MIN;

       for(int i=0;i<s.size();i++)
       {
           // here j<s.size()-1 because each string should have atleast one character
           for(int j=i;j<s.size()-1;j++)
           {
              // take both strings possible and check for zeros and ones
               string str=s.substr(i,(j-i+1));
               string str1=s.substr(j+1,(n-j-1));
            
            
               int no_of_ones=0;
               int no_of_zeros=0;
               for(auto it:str)
               {
                   if(it=='0')
                   {
                       no_of_zeros++;
                   }
               }
               for(auto it:str1)
               {
                   if(it=='1')
                   {
                       no_of_ones++;
                   }
               }

               max_score=max(max_score,no_of_zeros+no_of_ones);

           }
       }


       return max_score;


    }
};

// Approach 2 => (optimal approach = (Making use of ones count - 2 Pass))
// T.C => O(N)
// S.C => O(1)
class Solution {
public:
    int maxScore(string s) 
    {
        // optimised approach 
        // we can keep count of zeros and ones as we traverse the array
        // we can easily get no_of_zeros till ith index
        // to get no_of_ones in right side 
        // we can intially keep count of total_no_of_ones 
        // so no_of_ones in right side= total_ones - no_of_ones in left side

        int n=s.size();
        int total_ones=0;
        for(auto it:s)
        {
            if(it=='1')
            {
                total_ones++;
            }
        }
        int max_score=INT_MIN;
        int zeros_count=0;
        int ones_count=0;
        for(int i=0;i<n-1;i++)
        {
           if(s[i]=='0')
          {
            zeros_count++;
          }
          else
          {
            ones_count++;
          }
          max_score=max(max_score,zeros_count+(total_ones-ones_count));
            
          
        }

        return max_score;
    }
};


//Approach-3 (1 Pass - Use equation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxScore(string s) 
    {
         // one pass approach
         // Score = Z(zeros in left) + O(ones in right)
         // O(total ones) = O(left) + O(right)
         // O(R)=O(T)-O(left)
         // Score = Z(L)+(O(T)-O(L))
         // Score = Z(L)-O(L)+O(T)
         // only left substring is required

         int ones=0;
         int zeros=0;
         int max_score=INT_MIN;
         int n=s.size();


         for(int i=0;i<s.size()-1;i++)
         {
            if(s[i]=='1')
            {
                ones++;
            }
            else
            zeros++;
            max_score=max(max_score,zeros-ones);
         }
         // if last number is '1
         if(s[n-1]=='1')
         {
             ones++;
         }
         return max_score+ones;

    }
};