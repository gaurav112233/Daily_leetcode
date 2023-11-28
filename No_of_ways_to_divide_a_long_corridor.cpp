
// Leetcode Link => https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/

//Approach-1 (Using simple iteration)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M=1e9+7;
    int numberOfWays(string corridor) 
    {
       
        

        // We know we can't divide a string unless we found two s in partition
        // so starting from 0 move till we encounter two s
        // now from next index after 2nd s(i+1) was found till another s is found (j)
        // no of ways =(j-i) 

        // E.g SPSPPSPPSPPSS
        // after 2 s was found i=2 and after this next s was found at index(j=5)
        // no of ways to divide=(j-i)=(5-2)=3


        int count=0;
        vector<int> pos; // To store only index of string where s was occured
        for(int i=0;i<corridor.size();i++)
        {
           if(corridor[i]=='S')
           {
               pos.push_back(i);
           }
        }
         // Every section must have 2 seats and any no of plants 
        // so there must be even no of seats in string for Dividing a long corridor

        // if(no_of_seats%2!=0) return 0;
       // if pos_size=0 then no Seats are there in corridor
        if(pos.size()%2 || pos.size()==0)
        {
            return 0;
        }
           long long result=1;
           int prev=pos[1];// //End index of the starting subarray having 2 seats
        for(int i=2;i<pos.size();i+=2)
        {
          int length=pos[i]-prev; // length for partitioning
          result=(result*length)%M;
          prev=pos[i+1]; // New  End index of the starting subarray having 2 seats
        }

        return result;

    }
};


// Approach 2 (Using DP)