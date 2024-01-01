// Leetcode Link => https://leetcode.com/problems/assign-cookies/
// Date => 1/1/2024

// Approach 1 => (sorting only one array)
// T.C => O(m*n)
// S.C => O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        // brute force approach
        int ans=0;
        // sorting is required because in some scenario the cookie with much greater greed will be given to smaller greed required for child which can be utilized by greater child greed
        // Example => g={1,3,2,7} s={8,3,1,2}
        // without sorting child with greed 1 will take cookie with greed 8
        // but we can use this cookie with 7 greed child
        // so sorting is required
        sort(s.begin(),s.end());
        for(int i=0;i<g.size();i++)
        {
           for(int j=0;j<s.size();j++)
           {
               if(s[j]!=0 && s[j]>=g[i])
               {
                   ans++;
                   s[j]=0;
                   break;
               }
           }
        }
        return ans;
    }
};


//Approach (Sort and choose)
//T.C : O(mlogm + nlogn)
//S.C : O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
       // greedy approach
       // sort both the array
       // for each g[i] we need to find cookie with minimum greed greater than or equal to g[i]
       // minimum(s[j]) such that s[j]>=g[i]

       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int m=g.size();
       int n=s.size();

       int i=0;
       int j=0;

       while(i<m && j<n)
       {
            if(s[j]>=g[i])
            {
                i++;
            }
            j++;
       }
// we have satisfied requirment of children till (i-1)th index that is i children
       return i;
    }
};