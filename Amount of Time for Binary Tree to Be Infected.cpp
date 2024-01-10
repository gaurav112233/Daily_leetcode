// Leetcode Link       =>  https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
// Date => 10/1/2024

// Approach 1 => (Convert Tree to graph) (two pass solution)
// T.C => O(n) - visiting all nodes
// S.C => O(n) - storing all nodes in graph
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
    void convert(TreeNode* current, int parent,unordered_map<int,unordered_set<int>>& map)
    {
        if(current==NULL)
        {
            return;
        }
        // the root has a new value, we add it to the map and create a new adjacency list to store the adjacent vertices
        if(map.find(current->val)==map.end())
        {
            map[current->val]=unordered_set<int>();
        }
        unordered_set<int>& adjacencyList=map[current->val];
        // If current is not the root, add its parent to the adjacency list.
        if(parent!=0)
        {
           adjacencyList.insert(parent);
        }
        // If current a left child, add the child to its adjacency list.
         if (current->left != nullptr) 
         {
           adjacencyList.insert(current->left->val);
         } 
        //  If current has a right child, add the child to its adjacency list.
         if (current->right != nullptr) 
         {
           adjacencyList.insert(current->right->val);
         }
          convert(current->left, current->val, map);
          convert(current->right, current->val, map);
    }
    int amountOfTime(TreeNode* root, int start) 
    {
        // A node one level away from the start node takes 1 minute to become infected. All nodes on that level take the same amount of time to become infected.
        // We can reason that the distance of any given node from the start node will be the number of minutes it takes to infect the whole tree. Therefore, our solution will be the maximum distance from the start node.

        // to calcaulate max distance we must be able to traverse in both direction in tree forward as well as backward
        //  [since start is not a root]
        // so we will convert tree into undirected graph , so we can traverse in both direction

        unordered_map<int,unordered_set<int>> map;
        convert(root,0,map);


        // using a BFS 
//  Standard Breadth-First Search
// Add the first node to the queue
// While the queue is not empty:
// Remove the front node of the queue and mark it as visited.
// Check whether all adjacent nodes have been visited. If they have not, add them to the queue
  queue<int> q;
  // add star node to the queue
  // also mark it as visited
  q.push(start);
  int minute=0;
  unordered_set<int> visited;
  visited.insert(start);

  while(!q.empty())
  {
    //   Set levelSize, the number of vertices in this level, to the size of queue.
      int levelSize=q.size();
      while(levelSize>0)
      {
        //   Remove a vertex current from the queue .
          int current=q.front();
          q.pop();
//           For each edge in the adjacency list:
// Check whether the edge has been visited. If not, add it to queue and visited.
          for(int num:map[current])
          {
              if(visited.find(num)==visited.end())
              {
                  visited.insert(num);
                  q.push(num);
              }
          }
        //   Decrement levelSize.
          levelSize--;
      }
    //   Increment minute as the distance from startNode has increased.
      minute++;
  }



// When the queue is empty, we return minute - 1, because we have incremented minute for each level, but the time taken by the first node to infect neighbors is zero.
        
        return minute-1;


    }
};




//Approach-2 (Using DFS - one pass solution)
//T.C : O(n)
//S.C : O(n) - Max depth of recursion call stack
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
    int max_Distance=0;

    int Solve(TreeNode* root, int start)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        // calculate depth for left and right subtree 
        int LH= Solve(root->left,start);
        int RH= Solve(root->right,start);

        if(root->val==start)
        {
            // below subtree contains depth from start till end on one side
            max_Distance=max(LH,RH);
            // since we encountered start we tell it by returning negative depth to above nodes 
            return -1;
        }
        else if(LH>=0 && RH>=0)
        {
            // it means we have not encountered start node yet
            return max(LH,RH)+1;
        }
        else
        {
            // It means we have encountered the start node while traversing
            // so update the max_Distance 
            int d=abs(LH)+abs(RH);
            max_Distance=max(max_Distance,d);

            // we need to return distance from start node to node to which we return the value
            // also we encountered start node so return negative value
            return min(LH,RH)-1;
            
        }
        return 0;
    }
    int amountOfTime(TreeNode* root, int start) 
    {
        // more optimised code 
        // 1 pass solution
        // we will use concept of max depth of tree from the  start node given
        // we will use standard algorithm for finding maximum depth of tree

        // One challenge to this task is identifying whether we have encountered the start node during the traversal. We can return a negative depth when we encounter the start node. This will flag that we have found the start node, and as we traverse the tree, whenever we encounter a negative depth, we know the subtree contains the start node.
      Solve(root,start);

      return max_Distance;

    }
};
