

// Leetcode Link => https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/

//Using mathematical observation - Breaking into smaller sub-problems
//T.C : O(1) -> Constant for loop
//S.C : O(32) ~ O(1)
class Solution {
public:
    int minimumOneBitOperations(int n) 
    {
        if(n==0)
        {
            return 0;
        }
      // 1st operation can only change 0th bit
      // To change any other bit we need 2nd operation

      // we will solve problem from left to right bit

      // Hint : => What if there was only one set bit in n
       
      
      // If the number n which have only one bit set
      // E.g n=8 => 1000
      // TO change it we need to perform only 2nd operation 
      // first we need to convert 1000 => 1100 to apply 2nd operation
       // If for converting 000 => 100 x steps are required
      // 1000 => 1100  => apply 2nd operation => 0100 
      // for performing 2nd operation 1 step is required
      // Now we need to convert 0100 => 0000
      // then converting 100 => 000 same x steps are required
      // therefore no of steps = 2*x+1
      // now again this x is no of steps to change (i-1)th bit
      // F(i)=2*F(i-1)+1 // derived formula
      // i => set bit of a n
      // F(i) => no of steps required to make integer having only ith bit set to  convert  it to zero(0) 


// Now if multiple bit are set
// E..g if n=12 => 1100
// Now we know steps required for converting 1000 => 0000
// so first take intermediate step 1000 => 1100 =>0000
// F(1100 => 0000) = F(1000=>0000) - F(1000=>1100) // F(000=>100) or 
// F(100=>000)
// F(1100 => 0000) = F(1000=>0000) - F(100=>000)
//                 = F(3) - F(2)
      // take all the set bit and perform subtraction and addition alternately
      //                 F(11010)=F(10000)-F(1000)+F(10)
      // by deiriavation F(11010)=F(4)-F(3)+F(1)

      // We will store F(0...31) value in array
      // F(0)=1 because if only oth bit is set we can apply first operation and make it zero in 1 step

     
      vector<long long> Fun(32,0);
      Fun[0]=1;
      for(int i=1;i<=31;i++)
      {
          Fun[i]=(2*Fun[i-1])+1;
      }
       int result=0;
       int sign=1;
      for(int i=30;i>=0;i--)
      {
          // get ith bit 
          int ith_bit=((1<<i)&n);
          if(ith_bit==0)
          {
              continue;
          }

          if(sign>0)
          {
              result+=Fun[i];
          }
          else
          {
              result-=Fun[i];
          }
          sign=sign*(-1);
      }

      return result;

      


    }
};