// Leetcode Link => https://leetcode.com/problems/binary-tree-inorder-traversal/
// Date => 9/12/2023

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
   void Solve(vector<int> &ans,TreeNode *root)
   {
       if(root==NULL)
       {
           return;
       }

       Solve(ans,root->left);
       ans.push_back(root->val);
       Solve(ans,root->right);
   }
    vector<int> inorderTraversal(TreeNode* root) 
    {
       // inorder traversal 
       // left => root => right
       vector<int> ans;
       Solve(ans,root); 
       return ans;
    }
};