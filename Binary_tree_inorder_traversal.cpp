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



// Approach 2 -> (using morris traversal)
// T.C => O(n)
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
  
    vector<int> inorderTraversal(TreeNode* root) 
    {
     // using morris traversal
     // use left,visit,right
     // in recursion we always trace back to previous node
     // allowing us to visit [left root right] in order
     // Without recursion if we have to trace back
      
//       If current does not have left child

//     a. Add current’s value

//     b. Go to the right, i.e., current = current.right

// Else

//     a. In current's left subtree, make current the right child of the rightmost node

//     b. Go to this left child, i.e., current = current.left

/*
          1
        /   \
       2     3
      / \   /
     4   5 6
     
     First, 1 is the root, so initialize 1 as current, 1 has left child which is 2, the current's left subtree is

         2
        / \
       4   5

So in this subtree, the rightmost node is 5, then make the current(1) as the right child of 5. Set current = current.left (current = 2).

The tree now looks like:
         2
        / \
       4   5
            \
             1
              \
               3
              /
             6
     For current 2, which has left child 4, we can continue with the same process as we did above

        4
         \
          2
           \
            5
             \
              1
               \
                3
               /
              6

then add 4 because it has no left child, then add 2, 5, 1, 3 one by one, for node 3 which has left child 6, do the same as above.
Finally, the inorder traversal is [4,2,5,1,6,3].
     */

        vector<int> result;
        TreeNode* curr = root;
        TreeNode* pre;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            } else 
            {
                pre = curr->left;
                
                while (pre->right != nullptr) {
                    pre = pre->right;
                }
                
                pre->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }

        return result;

    
    }
};
