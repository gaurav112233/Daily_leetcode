
// Leetcode Link => https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2023-11-26


//Approach-1 (Using sorting)
//T.C : (m * nlogn)
//S.C : O(m*n)
class Solution 
{
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        // Consecutive 1's count are important
        // The intution behind this solution is that
        // we always try to keep two columns close having bigger heights and consecutive one's

        // We will store count of consecutive one's in column [store height] as we traverse in the 2-d matrix
        // once one row traversal is finsished 
        // we will store curr row in array
        // and sort arr in descending order
        // now we will again traverse this row 
        // as we have current column height in ith index base is calculated as (i+1)
        // since array is already sorted // previous element is surely going to contain one => so(i+1) as base

        int Area=INT_MIN;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                // now if curr cell has one in it 
                // if the previous cell also has positive number in it
                // just add one to store the max height possible
                if(matrix[i][j]==1 && (i-1)>=0)
                {
                    matrix[i][j]=matrix[i-1][j]+1;
                }
            }
            vector<int> currrow=matrix[i];
            sort(currrow.begin(),currrow.end(),greater<int>());
            for(int col=0;col<currrow.size();col++)
            {
                int base=(col+1);
                int height=currrow[col];
                Area=max(Area,base*height);
            }

        }


        return Area;

        


    }
};



//Approach-2 (Without modifying the given input)
//T.C : (m * nlogn)
//S.C : O(m*n)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        // without modifying the orignal matrix

        // Same approach as previous

        int m=matrix.size();
        int n=matrix[0].size();
        int Area=INT_MIN;
        
         vector<int> prev(n,0);
        for(int row=0;row<m;row++)
        {
            vector<int> curr_height(n,0);
            for(int col=0;col<n;col++)
            {
               if(matrix[row][col]==1)
               {
                curr_height[col]=prev[col]+matrix[row][col];
               }
            }
            
            cout<<endl;
            prev=curr_height;
            sort(curr_height.begin(),curr_height.end(),greater<int>());
            for(int col=0;col<n;col++)
            {
                int base=(col+1);
                int height=curr_height[col];

                Area=max(Area,base*height);
            }
           
        }
        return Area;
    }
};



//Approach-3 (Without sorting)
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
      // Without Sorting 
      // We can solve without sorting but we need to maintain the descending order of heihts
      // We can use {height,col} for it 
      // In previous row which column has highest height will evaluated first in current row and then next column in descending order
      // so by this we will able to keep descending order without sorting\
      

       int m=matrix.size();
        int n=matrix[0].size();
        int Area=0;

        vector<pair<int,int>> prevHeights; // {height,col}

        for(int row=0;row<m;row++)
        {
            vector<pair<int,int>> currHeights;
            vector<bool> seen = vector<bool>(n, false);

            // I will see those columns which had got height in prevHeights
            for(auto [height,col]:prevHeights)
            {
                if(matrix[row][col]==1)
                {
                     currHeights.push_back({height+1,col});
                     seen[col]=true;
                }
            }

            for(int col=0;col<n;col++)
            {
                if(seen[col]==false && matrix[row][col]==1)
                {
                    // if col is not yet visited
                    currHeights.push_back({1,col});
                }
            }

            for(int i=0;i<currHeights.size();i++)
            {
                int height=currHeights[i].first;
                int base=(i+1);
                Area=max(Area,base*height);
            }
            prevHeights=currHeights;
        }

        return Area;
    }

};