// Leetcode Link => https://leetcode.com/problems/image-smoother
// Date => 19/12//2023


// Approach 1=> (check all possible cell for each cell)
// T.C => O(m*n*8);
// S.c => O(m*n)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int m=img.size();
        int n=img[0].size();
        // do what is asked in question for each cell
        vector<vector<int>> ans(m,vector<int> (n,0));
        for(int i=0;i<img.size();i++)
        {
            for(int j=0;j<img[0].size();j++)
            {
                // lets add all possible neighbours to it
                int sum=img[i][j];
                int count=1;
                if((i-1)>=0 && (j-1)>=0)
                {
                    sum+=img[i-1][j-1];
                    count++;
                }
                if((i-1)>=0 && j>=0)
                {
                    sum+=img[i-1][j];
                    count++;
                }
                if((i-1)>=0 && (j+1)<n)
                {
                    sum+=img[i-1][j+1];
                    count++;
                }
                if(i>=0 && (j-1)>=0)
                {
                    sum+=img[i][j-1];
                    count++;
                }
                if(i>=0 && (j+1)<n)
                {
                    sum+=img[i][j+1];
                    count++;
                }
                if((i+1)<m && (j-1)>=0)
                {
                    sum+=img[i+1][j-1];
                    count++;
                }
                if((i+1)<m && j>=0)
                {
                    sum+=img[i+1][j];
                    count++;
                }
                if((i+1)<m && (j+1)<n)
                {
                    sum+=img[i+1][j+1];
                    count++;
                }
                ans[i][j]=floor(sum/count);

            }
        }
        return ans;
    }
};


// Approach 2 => (same approach but using for loop)
// T.C => O(m*n*3*3);
// S.c => O(m*n)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Save the dimensions of the image.
        int m = img.size();
        int n = img[0].size();

        // Create a new image of the same dimension as the input image.
        vector<vector<int>> smoothImg(m, vector<int>(n));

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count 
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }

                // Store the rounded down value in smoothImg[i][j].
                smoothImg[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return smoothImg;
    }
};


//Approach-3 (Using Optimized Space)
//T.C : O(m*n)
//S.C : O(n)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int m=img.size();
        int n=img[0].size();
      // optimized approach => reducing the space
      // for calculating grid[i][j] value we need previous rows value and one left index of it
      // and this value [previous rows value and one left index value] will be changed in previous smoothing 
      // so we can use extra array[prev_row[n]] to store previous row value before updating
      // also one edge case may be sometime the left neighbour will update prev_row[i]
      // but we may require top row value // so we need an extra variable
      // so to store top_corner value of that we will use extra variable top_corner for it
      // before updating prev[i] value we will store it it top_corner variable

      // for any index(i,j)
      // 1.bottom neighbour  => will get from img
      // 2.right neighbour   => will get from img
      // 3.top neighbour     => prev_row array
      //   top corner        => from variable(top_corner)
      // 4.left neighbour    => will get from prev_row array

      vector<int> prev_row(n,0);
      int top_corner=0;

       // Iterate over the cells of the image
      for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {
               // Initialize the sum and count 
              int count=0;
              int sum=0;

               // bottom neighbours (i+1)th row
               if((i+1)<m)
               {
                   // neighbours are [i+1][j-1] ,[i+1][j], [i+1][j+1]
                   if((j-1)>=0)
                   {
                       sum+=img[i+1][j-1];
                       count++;
                   }
                   sum+=img[i+1][j];
                   count++;
                   if((j+1)<n)
                   {
                       sum+=img[i+1][j+1];
                       count++;
                   }
               }
               // right neighbours [i][j+1]
               if((j+1)<n)
               {
                    sum+=img[i][j+1];
                    count++;
               }
              
              // just left neighbour [i][j-1]
              if((j-1)>=0)
              {
                  sum+=prev_row[j-1];
                  count++;
              }

               // current cell
               sum+=img[i][j];
               count++;

               // top neighbours // (i-1)th row
               // [i-1][j-1],[i-1][j],[i-1][j+1]
               if((i-1)>=0)
               {
                   // [i-1][j-1] => previous top_corner value
                   if((j-1)>=0)
                   {
                         sum+=top_corner;
                         count++;
                   }
                   // [i-1][j]=> get from prev_row value
                   sum+=prev_row[j];
                   count++;
                   // [i-1][j+1]
                   if((j+1)<n)
                   {
                       sum+=prev_row[j+1];
                       count++;
                   }
                   
               }
               // if previous row exist
               if((i-1)>=0)
               {
                   // update top_corner because we will be updating prev_row[j] with new row value
               top_corner=prev_row[j];
               }
               // store the current row value for next row calculation
               prev_row[j]=img[i][j];
               // update after applying smoothing
               img[i][j]=floor(sum/count);




          }
      } 
      return img;
    }
};
