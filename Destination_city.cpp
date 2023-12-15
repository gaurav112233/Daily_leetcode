// leetcode Link => https://leetcode.com/problems/destination-city
// Date => 15/12/2023


// Approach 1 => (Brute Force Approach)
// T.C => O(N^2)
// S.C => O(1)
class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        // brute force approach 
        // check for each city
        for(auto it:paths)
        {
           string start=it[0];
           string destination=it[1];
           int flag=1;
           for(auto vec:paths)
           {
               if(destination==vec[0])
               {
                   flag=0;
                   break;
               }
           }
           if(flag==1)
           {
               return destination;
           }
        }
        return "";
        
    }
};



// Approach 2 => (Brute Force Approach)
// T.C => O(N)
// S.C => O(N)
class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
       // using unordered map
       // store all the starting city in unordered map
       unordered_map<string,int> startcity;
       for(auto it:paths)
       {
        startcity[it[0]]++;
       }
        
        // now traverse through detinations city 
        // check if that city is found in startcity
        // if not then return that string as answer
        for(auto it:paths)
        {
            if(startcity.find(it[1])==startcity.end())
            {
                return it[1];
            }
        }
        return "";
    }
};
