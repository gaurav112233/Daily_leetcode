// Leetcode Link => https://leetcode.com/problems/buy-two-chocolates
// Date => 20/12/2023


// Approach 1 => using sorting
// T.C => O(nlogn)
// S.C => O(1)
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) 
    {

        int ans=money;
        sort(prices.begin(),prices.end());
      // if he need to buy two choclates with minimum sum
      // then he should buy two choclates with minimum price
      // so after sorting buy the upfront two choclates
        ans=money-prices[0];
        ans=ans-prices[1];
           // after buying if money left is greter than 0 return that left money
        if(ans>=0)
        {
            return ans;
        }


        // if not possible to buy return the intial money
        return money;
    }
};


// Approach 1 => (Without sorting`)
// T.C => O(n)
// S.C => O(1)
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) 
    {

       // second approach
       // without sorting

       // keep track of two minimum values in array to buy chocolates with minimum sum
       int first_min=INT_MAX;
       int second_min=INT_MAX;

       for(auto it:prices)
       {
           if(it<first_min)
           {
               second_min=first_min;
               first_min=it;
           }
           else
           {
               second_min=min(second_min,it);
           }
       }

       if((money-first_min-second_min)>=0)
       {
           return (money-first_min-second_min);
       }

       return money;
    }
};