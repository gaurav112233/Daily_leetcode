// Leetcode Link => https://leetcode.com/problems/decode-ways/
// Date => 25/12/2023


// Approach 1 => (approach like fibonacii series)
// here we will use data provide by previous two variables to decide the answer
// T.C => O(N)
// S.C => O(1)
class Solution {
public:
    int numDecodings(string s) 
    {


        // count1 is solution till previous to prev digit
// count2 is solution till previous digit

// if  by including current and previous number if new_num>=10 && new_num<=26 we can add count1 to our answer 
// if the current digit is not zero then we will add count2 to our answer

// return count2 as final answer

// if first digit is zero there can't be valid combination so return 0
        if(s.size()==0 || s[0]=='0')
        {
            return 0;
        }
        if(s.size()==1)
        {
            return 1;
        }

        int count1=1,count2=1;

        for(int i=1;i<s.size();i++)
        {
            int d=s[i]-'0'; // current digit
            int dd=s[i-1]-'0'; // previous digit
            // combine previous and current didgit
            int temp=(dd*10)+d;
            int count=0;
            // if curr_digit is not equal to zero
            // add count2 to our answer
            if(d!=0)
            {
                count+=count2;
            }
            // if combin ation is between 10 and 26 add count1 to our answer
            if(temp>=10 && temp<=26)
            {
                count+=count1;
            }
            count1=count2;// prev to prev count
            count2=count; // count gives the answer after including the current digit

        }
        return count2;
    }
};



// Approach 2 => (Using recursion => TLE)
class Solution {
public:
    int Solve(int ind,string &s,int &n)
    {
        if(ind==n)
        {
            return 1; // one valid split found
        }
        if(s[ind]=='0')
        {
            return 0; // not possible to split E.G "06","006"
        }

        // taking only ith character
        int only_ith_char=Solve(ind+1,s,n);
        int ith_and_i_plus_1_char=0;
        
        // check if we can take combination of ith and ith+1 character
        if((ind+1)<n)
        {
        if(s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6') )
        {
            // check after including the current character
            // further character can include or not
            ith_and_i_plus_1_char=Solve(ind+2,s,n);
        }
        }
        cout<<only_ith_char<<" "<<ith_and_i_plus_1_char<<endl;
        return (only_ith_char+ith_and_i_plus_1_char);
        
    }
    int numDecodings(string s) 
    {
     // using dynamic programming approach
     // we have option to pick either one number otherwise combination of two numbers
     // Repeating subproblems

     int n=s.size();

     return Solve(0,s,n);


    }
};



//Approach-1 (Using Recursion + Memoization)
//T.C : O(n) after memoization (without memoization - O(2^n)
//S.C : O(101) ~= O(1)
class Solution {
public:
    int t[101];
    int Solve(int ind,string &s,int &n)
    {
        if(t[ind]!=-1)
        {
            return t[ind];
        }
        if(ind==n)
        {
            return t[ind]=1; // one valid split found
        }
        if(s[ind]=='0')
        {
            return t[ind]=0; // not possible to split E.G "06","006"
        }

        // taking only ith character
        int only_ith_char=Solve(ind+1,s,n);
        int ith_and_i_plus_1_char=0;
        
        // check if we can take combination of ith and ith+1 character
        if((ind+1)<n)
        {
        if(s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6') )
        {
            // check after including the current character and next to current character
            // further character can include or not
            ith_and_i_plus_1_char=Solve(ind+2,s,n);
        }
        }
        // cout<<only_ith_char<<" "<<ith_and_i_plus_1_char<<endl;
        return t[ind]=(only_ith_char+ith_and_i_plus_1_char);
        
    }
    int numDecodings(string s) 
    {
     // using dynamic programming approach
     // we have option to pick either one number otherwise combination of two numbers
     // Repeating subproblems

     int n=s.size();
     memset(t,-1,sizeof(t));

     return Solve(0,s,n);


    }
};