// Leetcode Link => https://leetcode.com/problems/special-positions-in-a-binary-matrix
// Date => 13/12/2023



// Approach 1 => Brute force approach
// checking for each element
// T.C => O(n^3)
// S.C => O(1)

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        // using brute force approach 
        // lets check for each individual row
        int row=mat.size();
        int col=mat[0].size();
        int ans=0;

        for(int i=0;i<row;i++)
        {
          for(int j=0;j<col;j++)
          {
              int flag=0;
              // if present value is 1 then check in each row and col if there exsist other 1 in row or col
              if(mat[i][j]==1)
              {
                  // check in row
                  flag=1;
                  for(int k=0;k<col;k++)
                  {
                      // avoid the current [i][j] 
                      // so k!=j  [because i is constant in whole loop so we will check for j value]
                       if(k!=j && mat[i][k]==1)
                       {
                           flag=0;
                           break;
                       }
                  }
                  // if in row it fails no need to check in col
                  if(flag==0)
                  {
                      break;
                  }
                  // check in col
                  for(int k=0;k<row;k++)
                  {
                       // so k!=i  [because j is constant in whole loop so we will check for i value]
                      if(k!=i && mat[k][j]==1)
                      {
                        
                          flag=0;
                          break;
                      }
                  }
              }
              if(flag==1)
              {
                  ans++;
              }
          }
        }
        return ans;
    }
};


// Approach 2 => (Storing count of 1s in rows and cols)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
        // optimized approach
        // in previous approach we were checking for every element 
        // in each row and col // we were traversing multiple times through same row and col
        // we can store no of 1s in each row and each col
        // if(mat[i][j]==1) do below steps
        // when we are at mat[i][j] if at ith row [no of 1s <=1] 
        // and in jth column [no of 1s <=1] then ans+=1;


    //     store no of 1s in each row and col
        vector<int> row(m,0);
        vector<int> col(n,0);


        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int result=0;
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1 && row[i]==1 && col[j]==1)
                {
                    result++;
                }
            }
        }

        return result;




    }
};