// Leetcode Link => https://leetcode.com/problems/construct-string-from-binary-tree/
// Date => 8/12/2023

//Approach - Simple Recursion Story
//T.C : O(n)

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
   
    string tree2str(TreeNode* root) 
    {


//         Intuition:
// Seeing tree problems, first thing that hit's your brain is Recursion.
         // using recusrsion
         // just like preorder search
         if(root==NULL)
         {
             return "";
         }
         // convert root value to string and add to ans
         string result=to_string(root->val);
         // get result from left and right child 
         string l=tree2str(root->left);
         string r=tree2str(root->right);

        // if there is no left and right child don't do anything just return the result
         if(root->left==NULL && root->right==NULL)
         {
             return result;
         }

        // if there is no right child just ignore first bracket around it
         if(root->right==NULL)
         {
             return result+"("+l+")";
         }
         // if there is no left child  we create parentheses even when there is no left child because if we don't do this answer for two trees will be same
         // E.g 1    and    1
         //      \         /  ans will be 1(2) and 1(2) which will not accept
         //      2         2
         // for right pary output is 1(2)
         // for left chuld part the output is 1()(2)
         if(root->left==NULL)
         {
             return result+"()"+"("+r+")";
         }

         return result+"("+l+")"+"("+r+")";
          
    }
};