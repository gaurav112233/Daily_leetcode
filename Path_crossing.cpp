// Leetcode Link => https://leetcode.com/problems/path-crossing/description/
// Date => 23/12/2023


//Approach (simply simulate and check visited)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool isPathCrossing(string path) 
    {
        // brute force approach
        // using set approach
        unordered_map<char,pair<int,int>> moves;
        moves['N']={0,1};
        moves['S']={0,-1};
        moves['W']={-1,0};
        moves['E']={1,0};

        unordered_set<string> visited;
        // Initially, we are at the coordinates (0, 0). At each step, we walk in one of four directions:
        // We can map each direction instruction in path to a change in (x, y) coordinates with a hash map moves
        // 'N' : (0, 1)
       // 'S' : (0, -1)
      // 'W' : (-1, 0)
     // 'E' : (1, 0)
        visited.insert("0,0");

        int x=0;
        int y=0;

        for(char c:path)
        {
            pair<int,int> curr=moves[c];
            int dx=curr.first;
            int dy=curr.second;
            // then we move either in north,south,east,west
            x+=dx;
            y+=dy;

            string hash=to_string(x)+","+to_string(y);
            // check if we already visited that location
            // if visited then return true
            if(visited.find(hash)!=visited.end())
            {
                return true;
            }
            visited.insert(hash);
        }

        return false;

        
    }
};