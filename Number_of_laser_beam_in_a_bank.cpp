// Leetcode Link => https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
// Date => 3/1/2024


// Approach => (greedy + extra space)
// T.C => O(m*n)
// S.c => O(m) // To store count of one in each row
class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
      // we can keep extra array to store count of ones in each row
      int row=bank.size();
      vector<int> count_of_one(row,0);

      for(int i=0;i<bank.size();i++)
      {
          int one=0;
          for(auto c:bank[i])
          {
              if(c=='1')
              {
                  one++;
              }
          }
          count_of_one[i]=one;
      }
    
      // lets keep previous_ones in mind while calculating the total beams
      int prev_beam=0;
      int ans=0;
      int count=0;
      for(int i=0;i<bank.size();i++)
      {
          if(count_of_one[i]!=0)
          {
              count++;
          }

          int curr_beam=count_of_one[i];
          
          if(curr_beam>0)
          {
           if(prev_beam!=0)
           {
               ans+=(curr_beam*prev_beam);
           }
        
           prev_beam=curr_beam;
          }
       
      }

      // if there is only single row which conains 1 in it
      // so there is no beam in 2d array
      if(count==1)
      {
          return 0;
      }
      return ans;


    }
};


//Approach (Simple iterate and count)
//T.C : O(m*n) - Total number of characters in all string
//S.C : O(1)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
      // without using extra space

       int prev=0,ans=0;
      for(int i=0;i<bank.size();i++)
      {
          int one=0;
          for(auto c:bank[i])
          {
              if(c=='1')
              {
                  one++;
              }
          }
          // if curr count_of_one is not zero then
          // then multiply curr with previous count_of_ones
          if(one!=0)
          {
            ans+=(prev*one);
            prev=one;
          }
      }
          return ans;
      
    
    


    }
};

