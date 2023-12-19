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