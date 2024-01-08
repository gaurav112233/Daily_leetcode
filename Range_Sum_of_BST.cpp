// LeetCode Link => https://leetcode.com/problems/range-sum-of-bst/
// Date => 8/1/2024



// Approach 1 => (traversing whole binary search tree checking for each node value)
// T.C => O(N) where N=> no of nodes in BST
// S.C => O(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        // using recursion
        if(root==NULL)
        {
            return 0;
        }
        

        int sum=0;
        if(root->val>=low && root->val<=high)
        {
            sum+=root->val;
        }
        sum+=rangeSumBST(root->left,low,high);
        sum+=rangeSumBST(root->right,low,high);

        return sum;

    }
};

//T.C : O(n)
//S.C : O(1) (Ignoging recursion stack space)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        // optimised approach
        // using property of BST 

        if(root==NULL)
        {
            return 0;
        }
        
       //Within Range
        if(root->val >= low && root->val <= high) 
        {
            return root->val + rangeSumBST(root->left, low, high) +                   rangeSumBST(root->right, low, high);
        }
        //When outside the range (Less than low) - Go right
        if(root->val<low)
        {
            return rangeSumBST(root->right, low, high);
        }

         //When outside the range (Greater than high) - Go left
        return rangeSumBST(root->left, low, high);

    }
};