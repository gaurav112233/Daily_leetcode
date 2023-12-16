  /*
    Company Tags                : Uber
    Leetcode Link               : https://leetcode.com/problems/valid-anagram/
    Date                        : 16/12/2023
    
    Follow Up - What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
    Answer - Either use a hashmap to store or an interger array of size 128 will work (in Approach-2)
*/



//Approach-1 (Using sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(begin(s), end(s));
        sort(begin(t), end(t));
        
        return s == t;
    }
};

//Approach-2 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char,int> mp;

        for(auto it:s)
        {
            mp[it]++;
        }
        int count=mp.size();

        for(auto it:t)
        {
         mp[it]--;
         if(mp[it]==0)
         {
             count--;
         }
        }
        if(count)
        {
            return false;
        }

        return true;
    }

};


//Approach-2 (Using frequency array)
//T.C : O(n)
//S.C : O(n)=0(26)=O(1)
class Solution {
public:
    bool zerocount(vector<int> &arr)
    {
        // return arr==vector<int>(26,0);
        // or 
         for(auto it:arr)
        {
            if(it!=0)
            {
                return false;
            }
           
        }
         return true;

    }
    bool isAnagram(string s, string t) 
    {
        // using frquency array
        // since string only consist of lower case english letters
        vector<int> count(26,0);

        for(auto it:s)
        {
            char ch=it-'a';
            count[ch]++;
        }

        for(auto it:t)
        {
            char ch=it-'a';
            count[ch]--;
        }

        if(zerocount(count))
        {
            return true;
        }
        return false;
    }

};