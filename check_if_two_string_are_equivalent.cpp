
// 1/12/2023
// Leetcode Link => https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description


// 1st Approach => Simple Concatenation
// T.C => 0(m*k+n*k)   m=length of first array , n=length of second Array
// S.C => 0(m*n+n*k)   m*k=total length of string after cocatenation
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        // brute force approach

        string s1="";
        string s2="";

        for(auto it:word1)
        {
            s1+=it;
        }

        for(auto it:word2)
        {
            s2+=it;
        }

        return s1==s2;
    }
};

// Approach 2 =>  (Using comparison character by character using index)
// T.C =>  0(m*k+n*k)
// S.C => 0(1)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        // By checking word by word in both array

        int n=word1.size();
        int m=word2.size();
        // w1i and w2i to keep track of array length
         int w1i=0;
         int w2i=0;
         // i and j to keep track of each string length
         int i=0; // to keep track of word in word1
         int j=0; // to keep track of word in word2
        while(w1i<n && w2i<m)
        {
            if(word1[w1i][i]!=word2[w2i][j])
            {
                return false;
            }
            // if same character move forward to check next character
            i++;
            j++;

            // if we reach the end of first element in array word1
            if(i==word1[w1i].size())
            {
                // now intialize i to zero to consider next word in array
                i=0;
                // move to next word
                w1i++;
            }

            if(j==word2[w2i].size())
            {
                j=0;
                w2i++;
            }
        }
        // if after checking all character if we reach at end for both arrays
        // that means after concatenation same string is formed 
        if(w1i == word1.size() && w2i == word2.size())
            return true;

        return false;
    }
};
