// Leetcode Link => https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column
// Date => 14/12/2023


// Approach 1 (Taking four arrays to store zeros and ones in row and col)
// T.C => O(m*n)
// S.c => O(2*(m+n))
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        // brute force approach
        // store no of ones and no of zeros in row in different array
        int m=grid.size();
        int n=grid[0].size();

        vector<int> row_zeros(m,0);
        vector<int> col_zeros(n,0);
        vector<int> row_ones(m,0);
        vector<int> col_ones(n,0);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    row_ones[i]++;
                    col_ones[j]++;
                }
                else
                {
                    row_zeros[i]++;
                    col_zeros[j]++;
                }
            }
        }

        vector<vector<int>> ans(m,vector<int> (n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]=row_ones[i]+col_ones[j]-row_zeros[i]-col_zeros[j];
            }
        }

        return ans;

    }
};


// Approach 2 (Taking two arrays to store no of ones in row and col)
// (no of zeros can be calculated easily by [length-no_of_1s])
// T.C => O(m*n)
// S.c => O(m+n))
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        // brute force approach
        // store no of ones and no of zeros in row  and col in different array
        int m=grid.size();
        int n=grid[0].size();

          // we can only take two array 
          // because we can calculate no_of_zeros=(length-no_of_ones)
        vector<int> row_ones(m,0);
        vector<int> col_ones(n,0);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    row_ones[i]++;
                    col_ones[j]++;
                }
            }
        }

      // diff[i][j]=row_ones[i]+col_ones[j]-(N - row_ones[i])-(M-col_ones[j])
        vector<vector<int>> ans(m,vector<int> (n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]=row_ones[i]+col_ones[j]-(n - row_ones[i])-(m-col_ones[j]);
            }
        }

        return ans;

    }
};
