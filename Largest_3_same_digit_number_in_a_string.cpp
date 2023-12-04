// Leetcode Link => https://leetcode.com/problems/largest-3-same-digit-number-in-string/
// Date :: 4/12/2023


// Approach => (Simple iteration and check)
// T.C => O(n)
// S.c => O(1)

class Solution {
public:
    string largestGoodInteger(string num) 
    {
        // we need to check largest 3 digit number having same digit
        // we will start direct 2nd index and will check previous two value if they are same we will update max among them
        int n=num.size();
        int ans=INT_MIN;
        for(int i=2;i<n;i++)
        {
         if(num[i]==num[i-1] && num[i]==num[i-2])
         {
             if((num[i]-'0')>ans)
             {
                 ans=(num[i]-'0');
             }
         }
        }

        return  ans==INT_MIN ? "":string(ans,3);
    }
};


// Approach => (Using sliding window approach)
// T.C => O(2*n)
// S.C => O(1)
class Solution {
public:
    string largestGoodInteger(string num) 
    {
        // Sliding window approach
        string ans="";
        int value=INT_MIN;
        int k=3;
        int i=0;
        int j=0;
        unordered_map<char,int> mp;


        while(j<num.size())
        {
            mp[num[j]]++;
            if((j-i+1)<k)
            {
                j++;
            }
            else if((j-i+1)==k)
            {
                 string a=num.substr(i,3);
                if(mp.size()==1)
                {
                    int v=stoi(a);
                    if(v>value)
                    {
                        ans=a;
                        value=v;
                    }
                }
                cout<<a<<endl;

                mp[num[i]]--;
                if(mp[num[i]]==0)
                {
                    mp.erase(num[i]);
                }
                j++;
                i++;
            }
        }
        return ans;
    }
};