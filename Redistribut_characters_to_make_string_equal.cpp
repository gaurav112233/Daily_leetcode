// Leetcode Link => https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
// Date => 30/12/2023


//Approach-1 (Using hashmap to store frequency)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        unordered_map<char,int> mp;
        // Characters are independent—only the frequency of characters matters
        // It is possible to distribute characters if all characters can be divided equally among all strings.
        // so we count frequency of each character and check if that character can equally distributed among all strings
        // so we check (freq%n)==0 or not

        for(auto it:words)
        {
            for(auto vec:it)
            {
                mp[vec]++;
            }
        }

        int n=words.size();
        int flag=1;

        for(auto it:mp)
        {
            if((it.second%n)!=0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            return true;
        }

        return false;
    }
};


//Approach-2 (Using array as hashmap for storing frequency)
//T.C : O(n)
//S.C : O(26)
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> counts(26, 0);
        for (string word : words) {
            for (char c : word) {
                counts[c - 'a']++;
            }
        }
        
        int n = words.size();
        for (int val : counts) {
            if (val % n != 0) {
                return false;
            }
        }
        
        return true;
    }
};