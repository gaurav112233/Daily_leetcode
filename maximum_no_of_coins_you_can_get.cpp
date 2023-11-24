

// Date 24/11/2023
// Question link =>  https://leetcode.com/problems/maximum-number-of-coins-you-can-get/



// First approach that came to my mind
// T.c => O(n log n)
// S.c => O(1)
class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        // better approach
        // as we need to max middle value of each 3 pile we select
        // our first element of each pile will be smallest
        // second element will be 2nd max from remainng element
        // third element will be max from remaining element

        // So first we need to sort the array

        sort(piles.begin(),piles.end());
        int result=0;
        int count=0;

        int max_count=piles.size()/3; // max element we can take in our result

        // each time select 2nd last element from our array until we reach max_count
        for(int i=piles.size()-2;i>=0;i-=2)
        {
            cout<<piles[i]<<" ";
            result+=piles[i];
            count++;
            if(count==max_count)
            {
                break;
            }
        } 

        return result;
    }
};


// Approach => (Greedy approach + 3 pointers)
//T.C : O(nlogn) - Sorting
//S.C : O(1)
class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        int n=piles.size();

       // greedy approach

       // first sort the array
       sort(piles.begin(),piles.end());

       // Alice always picks big number 
       int Alice=n-1;
       // you always pick 2nd biggest
       int Me=n-2;
       // Bob always pick smaller one
       int Bob=0;

       int result=0;
       while(Bob < Me)
       {
           result+=piles[Me];

           // Now after first round next max will be n-3 (i.e Alice-2)
           // 2nd max will be n-4 (i.e Me-2)
           // smallest will be 1 (i.e Bob+1)

           Alice-=2;
           Me-=2;
           Bob+=1;

       }

       return result;
    }
};


//Approach-2 (Using Greedy without 3 pointers)
//T.C : O(nlogn) - Sorting
//S.C : O(1)
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        
        sort(begin(piles), end(piles));
        
        int result = 0;

        // bob always take  starting (n/3) elements in all possible piles
        // YOu [Me] Always start from 2nd last till (n/3)+1 th element
        for(int i = n/3; i <n; i+=2) {
            result += piles[i];
        }
        
        return result;
    }
};





