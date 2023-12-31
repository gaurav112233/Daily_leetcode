// Leetcode Link => https://leetcode.com/problems/largest-substring-between-two-equal-characters/
// Date => 31/12/2023

////Approach-1 (Using Brute Force) 
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int result = -1;
        int n      = s.length();
        
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j<n; j++) {
                
                if(s[i] == s[j]) {
                    result = max(result, j-i-1);
                }
            
            }
        }
        
        return result;
    }
};

//Approach-2 (Using Hashmap) - ACCEPTED
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
       // using map
       // we will store first occurence of every character 
       // and if that character is found again we will update the max length
       int result=-1;
       unordered_map<char,int> mp;
       for(int i=0;i<s.size();i++)
       {
           if(mp.find(s[i])!=mp.end())
           {
              result=max(result,i-mp[s[i]]-1);
           }
           else
           {
               mp[s[i]]=i;
           }
       }

       return result;
    }
};

