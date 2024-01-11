// Leetcode Link => https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// Date => 11/1/2024

//Approach-1 (Brute Force) - O(n^2) - n = number of nodes in the Tree
/*
  Just simply take a root, find all the differences of it from its childres and find max one
  Again go to root->left and do the same as above
  Again go to root->right and do the same as above
*/
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
    int max_diff=INT_MIN;
    void findmaxUtil(TreeNode* root,TreeNode* child)
    {
        if(!root || !child)
        {
            return;
        }
        max_diff=max(max_diff,abs(child->val-root->val));

        // check the distance from all its childs
        findmaxUtil(root,child->left);
        findmaxUtil(root,child->right);
    }
    void findmaxDiff(TreeNode* root)
    {
        // if current node is null or it doesn't have both child then no child exsist so just return 
        if(!root || (!root->left && !root->right))
        {
            return;
        }
        // find maxDiff of this root with all its children
        findmaxUtil(root,root->left);
        findmaxUtil(root,root->right);

        // now again go to left side of root and do same thing
        findmaxDiff(root->left);
        findmaxDiff(root->right);

    }
    int maxAncestorDiff(TreeNode* root) 
    {
        /*
       Just simply take a root, find all the differences of it from its      children  and find max one
  Again go to root->left and do the same as above
  Again go to root->right and do the same as above
  */
     // brute force approach
     findmaxDiff(root);
     return max_diff;

    }
};


//Approach-2
//Optimal (O(n)) using min and max value for |min-max|
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
   
   int findmaxDiff(TreeNode* root,int minV,int maxV)
   {
       if(root==NULL)
       {
           return abs(minV-maxV);
       }
       // update minV and maxV at current node
       minV=min(minV,root->val);
       maxV=max(maxV,root->val);
        int l=findmaxDiff(root->left,minV,maxV);
        int r=findmaxDiff(root->right,minV,maxV);

        return max(l,r);
   }
    
    int maxAncestorDiff(TreeNode* root) 
    {
        // optimal approach 
        // For each subtree, find the minimum value and maximum value of its descendants.
        int minV=root->val;
        int maxV=root->val;

        // along each path we get difference of max and min value
        // if this difference is greater than ans then update the ans
        return findmaxDiff(root,minV,maxV); 


    }
};