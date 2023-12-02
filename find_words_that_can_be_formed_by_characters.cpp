
// Leetcode Link => https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

// Date => 2/12/2023

// Approach 1 => brute force apprioach using unorderd map
// T.C => O(m*k) m=size of words array k=largest size of word in words
// S.C => O(2*n)  n= length of chars

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        // brute force approach by checking each word in vector=>words
        int result=0; // To store final length

        // two maps we used becase
        // mp => while checking each word map will change
        // so after each word we capy mp1 to mp
        unordered_map<char,int> mp;
        unordered_map<char,int> mp1;

        for(auto it:chars)
        {
            mp[it]++;
            mp1[it]++;
        }

        for(auto it:words)
        {
            int flag=1;
          for(auto character:it)
          {
            if(mp.find(character)==mp.end() || mp[character]==0)
            {
                flag=0;
               break;
            }
            mp[character]--;
          }
          if(flag)
          {
              result+=it.size();
          }
          mp=mp1;
        }

        return result;
    }
};

// Approach 2 => using frequency array
// T.C => 0(words.length)
// S.C => 0(26)
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
       // using array size of 26 
       // wheneever lower_case english letters use [26] sized array

       vector<int> charcount(26,0);
       for(auto it:chars)
       {
           charcount[it-'a']++;
       }
       int result=0;
       for(auto word:words)
       {
           vector<int> wordcount(26,0);
            int flag=1;
           for(auto it:word)
           {
               wordcount[it-'a']++;
           }

           for(int i=0;i<26;i++)
           {
               // if some letter count in word_count is greater  then
               if(wordcount[i]>charcount[i])
               {
                   flag=0;
                   break;
               }
           }
            if(flag)
            {
                   result+=word.length();
            }
       }
       return result;
    }
};