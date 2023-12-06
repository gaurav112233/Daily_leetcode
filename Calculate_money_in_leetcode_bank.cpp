// Leetcode Link =>https://leetcode.com/problems/calculate-money-in-leetcode-bank/
// Date => 6/12/2023


// Approach 1 (Using map)
// the first approach that came to my mind
// T.C => O(n)
// S.C => O(7) => O(1)
class Solution {
public:
    int totalMoney(int n) 
    {
        // brute force approach
        // start from 1st day and just add money according to condition
        int ans=0;
        // first we will keep track of money each day he put in whole week
        unordered_map<int,int> mp{{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{0,7}};
        for(int i=1;i<=n;i++)
        {
            // for first week we will simply add money from 1 till 7
            // we used i%7 because to get each weeks day value easily for other i's like 14,28
            ans+=mp[i%7]; 
          
          // if first week is finished 
          // we need to update map because now we will be adding one extra dollar for each day of the week
            if(i%7==0)
            {
                for(auto it:mp)
                {
                   mp[it.first]++;
                }
            }
        }
        return ans;
    }
};




//Approach-2 (Just doing what Qn asks - simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int result = 0;
        
        int monday_money = 1;
        
        while(n > 0) {
            
            int money = monday_money;
            for(int day = 1; day <= min(n, 7); day++) {
                result += money++;
            }
            
            
            n            -= 7;
            monday_money += 1;
        }
        
        return result;
        
    }
};


//Approach-3 (Using Maths)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) 
    {
        // Best approach => using maths
// 1st week => 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28
// 2nd week =>2 + 3 + 4 + 5 + 6 + 7 + 8 = 35
// 3rd week =>3 + 4 + 5 + 6 + 7 + 8 + 9 = 42
// summation of each week forms an A.P with commom difference  7
// so uisng A.P Sn=(n/2)(a1+an)
// so upto n/7 week we can use this formula
// for remainning days(n%7) we will calculate seprately
 
   int first_term=28; // summation 1+2+3+4..+7
   int no_of_weeks=n/7;
   int last_term=first_term+((no_of_weeks-1)*7);
   int deposit_on_no_of_weeks=((no_of_weeks)*(first_term+last_term))/2;

   int remaining_days=n%7;
   // start for remaining days
   int start=(n/7)+1;
   int last=start+(remaining_days-1);
   int remaining_sum=((remaining_days)*(start+last))/2;

   return deposit_on_no_of_weeks+remaining_sum;
        
    }
};

