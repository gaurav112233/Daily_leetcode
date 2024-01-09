// Leetcode Link => https://leetcode.com/problems/leaf-similar-trees/
// Date => 9/1/2024


// Approach => using inorder traversal 
// in inorder traversal we travel along with the leaves in a same sequence 
// T.C => O(N)
// S.C => O(N)
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
    void Solve(TreeNode* root1,vector<int>& leaves)
    {
        if(root1==NULL)
        {
            return;
        }
        if(root1->left==NULL && root1->right==NULL)
        {
        leaves.push_back(root1->val);
        }

        Solve(root1->left,leaves);
        Solve(root1->right,leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        // by inorder travrsal
        vector<int> leaves1;
        Solve(root1,leaves1);
         vector<int> leaves2;
         Solve(root2,leaves2);

         if(leaves1.size()!=leaves2.size())
         {
             return false;
         }

         for(int i=0;i<leaves1.size();i++)
         {
             cout<<leaves1[i]<<" "<<leaves2[i]<<endl;
             if(leaves1[i]!=leaves2[i])
             {
                 return false;
             }
         }

         return true;

    }
};