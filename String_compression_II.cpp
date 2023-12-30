// Leetcode Link => https://leetcode.com/problems/string-compression-ii/
// Date => 28/12/2023

//Approach-1 (Using Recursion + Memoization)
//T.C : Without Memoization = O(2^n), With Memoization = O(n^2 * k) , we won't visit any char state more than once.
//S.C : O(1) constant space
int t[101][27][101][101]; //It is allocated in Heap
class Solution {
public:
    //int t[101][27][101][101]; //It will allocated in Stack and will give stack overflow
    int solve(string &s, int i, int prev, int freq, int k ){
        if(k < 0)
            return INT_MAX;
        
        if(i >= s.length())
            return 0;
        
        if(t[i][prev][freq][k] != -1) {
            return t[i][prev][freq][k];
        }
        
        int delete_i = solve(s, i+1, prev, freq, k-1);
        
        int keep_i   = 0;
        
        if(s[i] - 'a' == prev) {
             int one_more_added = 0;
             if(freq == 1 || freq == 9 || freq == 99) {
                 one_more_added = 1;
             }
            keep_i = one_more_added + solve(s, i+1, prev, freq+1, k);
        } else {
            keep_i = 1 + solve(s, i+1, s[i]-'a', 1, k);
        }
        
        return t[i][prev][freq][k] = min(delete_i, keep_i);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(t, -1, sizeof(t));
        return solve(s, 0, 26, 0, k);
    }
};


//Approach-2 (Using 2D Memoization)
//T.C : O(n*k) we will visit at max n*k states after memoization
//S.C : O(n*k)
class Solution {
public:
       vector<vector<int>> t;
    int Solve(int idx,int k,string &s)
    {
        if(k<0)
        {
            return 10000;
        }
        if(idx>=s.size() || (s.size()-idx)<=k)
        {
            return 0;
        }
         if(t[idx][k] != -1) {
            return t[idx][k];
        }

        int delete_i=Solve(idx+1,k-1,s);

        int keep_i=INT_MAX;
        // check longest streak of curr_character we can keep

        int deleted=0;
        int freq=0;
        int addition=0;

        for(int j=idx;j<s.size() && deleted<=k;j++)
        {
            if(s[j]==s[idx])
            {
                freq++;
                if(freq==2 || freq==10 || freq==100)
                {
                    addition++;
                }
            }
            else
            {
                deleted++;
            }
            keep_i=min(keep_i,1+addition+Solve(j+1,k-deleted,s));
        }

        return t[idx][k]=min(keep_i,delete_i);
    }
    int getLengthOfOptimalCompression(string s, int k) 
    {
        // using 2-d memorization
           t = vector<vector<int>>(s.size() + 1, vector<int>(k + 1, -1));
        return Solve(0,k,s);
    }
};