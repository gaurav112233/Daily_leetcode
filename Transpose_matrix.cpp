 
 // Leetcode Link => https://leetcode.com/problems/transpose-matrix/
 // Date => 10/12/2023


 // Approach 1=> Basic Transpose approach (arr[i][j]=arr[j[i])
 // T.C => O(m*n)
 // S.C => O(m*n)
 vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
       vector<vector<int>> ans(n,vector<int> (m,0));

     // first n loop then m loop
     // because in transpose [new_row_size=old_col_size and new_col_size=old_row_size]
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               ans[i][j]=matrix[j][i];
           }
       } 

       return ans;
    }



    // Follow up question 
    // what if our matrix is square matrix (n*n)
    // then we can reduce our space since row and col size remain same
    // also Diagonal elements remain same 


    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        int size=matrix.size();
       

       // we will run first loop to cover all rows
       // in second loop we start from [i+1 or i] because element before i in ith row are already swapeed by its correct number
       // on the other side of diagonal
      
        //  If we simply do for (int j=0; j<n; j++), we end up swapping row and column values twice, 
        //  giving us our original matrix:
        //  o avoid this, we want to make sure we're only swapping i and j once. 
        //  Therefore, start our nested for-loop at j = i+1 (the "+1" is there since we can skip the diagonals as well).

        
       
       for(int i=0;i<size;i++)
       {
           for(int j=i+1;j<size;j++)
           {
               swap(matrix[i][j],matrix[j][i]);
           }
       } 

       return matrix;
    }



