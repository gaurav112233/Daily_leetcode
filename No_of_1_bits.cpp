// 29/11/2023
// Leetcode Link => https://leetcode.com/problems/number-of-1-bits/description/

// Some facts related to bits 
// 1.How to find ith bit of a number
// (num >> i) & 1==1




// after unset rightmost set bit => 110000
// Approach 1 =>(Using simple right shift operator)
// T.C =>  O(1) - because the max no of bits in given question are 32
// S.C => O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int count=0;

        while(n>0)
        {
            int ith_bit=(n)&1;
            if(ith_bit)
            {
                count++;
            }
            n=(n>>1);
        }
        return count;
    }
};



// 2.How to unset rightmost set bit of an integer
// => n=(n&(n-1))
// E.g 110010(n)    110001(n-1)   n&(n-1)=110000

// Approach-2 (Using simple bit magic)
//T.C : O(k) -> Where k = number of set bits (1s) in input 'n'
//S.C : O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
       int count=0;
       while(n)
       {
           n=n & (n-1); // unset the rightmost set bit  everytimes
           count++;
       }
       return count;
    }
};


//Approach-3 (Using simple bit magic)
//T.C : O(log(n)) -> In each iteration, n is divided by 2 (n /= 2)
//S.C : O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while(n) {
            count += (n%2);
            n /= 2;
        }
        
        return count;
    }
};

//Approach-4 (using GCC built-in function)
//T.C : O(k) -> Where k = number of set bits (1s) in input 'n'
//S.C : O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};



