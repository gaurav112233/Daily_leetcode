
// Date => 27/11/2023
// Leetcode Link => https://leetcode.com/problems/knight-dialer/

// Approach 1 => Recursion (Brute force)
// T.C => O(3^n)
// S.C => O(1)
class Solution {
public:
      int M = 1e9+7;
    vector<vector<int>> adj = 
    {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    int Solve(int n,int cell)
    {
        if(n==0)
        {
            // if we have reached the size of phone number return 1
            return 1;
        }
        int ans=0;
        for(int next_cell:adj[cell])
        {
            ans+=Solve(n-1,next_cell);
        }

        return ans;
    }
    int knightDialer(int n) 
    {
        // try all possibilities  [All cells]

        // Steps to solve
        // first create adjacency list 
        // from 0 we can got to =>{4,6}
        // from 1 we can go  to =>{6,8}
        // similarly for others 

        // using recursion 
        // better approach

        int ans=0;

        for(int cell=0;cell<=9;cell++)
        {
            ans+=Solve(n-1,cell);
        }
        return ans;


    }
};


// Approach 2 => Recursion + memorization
// T.C => O(n*k) k=10
// S.c => O(n*k)

class Solution {
public:
      int M = 1e9+7;
    vector<vector<int>> adj = 
    {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

     int t[5001][10];

    int Solve(int n,int cell)
    {
        if(n==0)
        {
            // if we have reached the size of phone number return 1
            return 1;
        }

        if(t[n][cell]!=-1)
        {
            return t[n][cell];
        }
        int ans=0;
        for(int next_cell:adj[cell])
        {
            ans=(ans+Solve(n-1,next_cell))%M;
        }

        return t[n][cell]=ans;
    }
    int knightDialer(int n) 
    {
        // try all possibilities  [All cells]

        // Steps to solve
        // first create adjacency list 
        // from 0 we can got to =>{4,6}
        // from 1 we can go  to =>{6,8}
        // similarly for others 

        // using recursion +memorization
        // better approach

        int ans=0;
        memset(t,-1,sizeof(t));

        for(int cell=0;cell<=9;cell++)
        {
            ans=(ans+Solve(n-1,cell))%M;
        }
        return ans;


    }
};


// Approach 3 => using DP [Will add later after learning it properly]