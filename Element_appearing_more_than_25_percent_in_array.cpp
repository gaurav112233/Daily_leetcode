
// Leetcode Link => https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array
// Date => 11/12/2023


// Approach 1 => (Using map )
// T.C => O(n)
// S.C => O(n)
class Solution 
{
public:
    int findSpecialInteger(vector<int>& arr) 
    {
       //extra space
       unordered_map<int,int> mp;
       for(auto it:arr)
       {
           mp[it]++;

       }

      
       
       int target=arr.size()/4; // 25% of array size
       for(auto it:mp)
       {
          if(target<it.second)
          {
              return it.first;
            }
       }

      return -1;
    }
};


//Approach-2 (Using sorted property) - Equal elements will occur together
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
       // best approach
       // we can take advantage of sorted array

    //    Because the array is sorted, all equal elements are adjacent to each other and form a "block" in the array. The size of the ans block must be greater than n / 4 by definition
       // Let's say the first index of the ans block is i. As a consequence of the above observation, the final index of the ans block must be greater than or equal to i + (n / 4)

      int size = arr.size() / 4;
        for (int i = 0; i < arr.size() - size; i++) {
            if (arr[i] == arr[i + size]) {
                return arr[i];
            }
        }
        
        return -1; 
    }
};



// Approach 3 => using binary search
// T.C => O(nlogn)
// S.C => O(1)
class Solution {
public:
    int binary_last(vector<int>& arr,int ele)
    {
        int l=0;
        int h=arr.size()-1;
        int ans=-1;

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(arr[mid]==ele)
            {
               ans=mid;
               // look in right side
               l=mid+1;
            }
            else if(arr[mid]<ele)
            {
               l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
    int findSpecialInteger(vector<int>& arr) 
    {
        // using binary search approach => since array is sorted

        // we will take (i index)each element and find its rightmost position(jth index) in array
        // if  (j-i+1)>(n/4) // return that element

       // so first we wiil loop through whole array
       int size=arr.size()/4;
       for(int i=0;i<arr.size();i++)
       {
           int element=arr[i];

           int last=binary_last(arr,element);
           if((last-i+1)>size)
           {
               return  element;
           }
       }
       return -1;


    }
};



//Approach-3 (Using Binary Search) - Array is sorted
//T.C : O(3*logn) ~ O(log(n)
//S.C : O(1)
class Solution {
public:
    int binary_first(vector<int>& arr,int ele)
    {
        int l=0;
        int h=arr.size()-1;
        int ans=-1;

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(arr[mid]==ele)
            {
               ans=mid;
               // look in left side
               h=mid-1;
            }
           else if(arr[mid]<ele)
            {
                l=mid+1;
            }
            else
            {
               h=mid-1;
            }
        }
        return ans;
    }
    int binary_last(vector<int>& arr,int ele)
    {
        int l=0;
        int h=arr.size()-1;
        int ans=-1;

        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(arr[mid]==ele)
            {
               ans=mid;
               // look in right side
               l=mid+1;
            }
            else if(arr[mid]<ele)
            {
               l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
    int findSpecialInteger(vector<int>& arr) 
    {
     
        // using binary search approach => since array is sorted
        // lets consider all possible candidates
       // The answer block has a length greater than n / 4, and thus it must overlap at least one of the following positions in the array:

// 1.A quarter of the way through at index n/4.
// 2.Halfway through at index [2n/4] i.e n / 2.
// 3.Three-quarters of the way through at index 3n/4.

        // we will take all the possible candidates and calculate its first and last occurence in arr
        // if  (last-first+1)>(n/4) // return that element

       // so first we wiil loop through possible candidates
       int n=arr.size();
       vector<int> candidates{arr[n/4],arr[n/2],arr[(3*n)/4]};
       int size=n/4;

       for(auto it:candidates)
       {
           int first=binary_first(arr,it);
           int last=binary_last(arr,it);
           if((last-first+1)>size)
           {
               return it;
           }
       }
       return -1;


    }
};