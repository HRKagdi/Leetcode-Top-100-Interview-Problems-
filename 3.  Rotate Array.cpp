//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/
//3.  Rotate Array.cpp

//Given an array, rotate the array to the right by k steps, where k is non-negative.
/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
*/
/*Approach 1:
Extra memory:
1) Store first last k elements in a array.
2) For i =k to i=0
  do nums[i+k]=nums[i]
 3) For i=0 to i<k
  do nums[i]=v[i]
  
  Time Complexity: O(N), Space Complexity: O(N)
  */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        vector<int> v(k); int j=0;
        for(int i=nums.size()-k;i<nums.size();i++){
            v[j++]=nums[i];
        }
        for(int i=nums.size()-k-1;i>=0;i--){
            nums[i+k]=nums[i];
        }
        for(int i=0;i<k;i++){
            nums[i]=v[i];
        }
    }
};



/*Approach 2:
  Algo:
  1) Reverse the entire array.
  2) Reverse subarray nums[0:k-1]
  3) Reverse subarray nums[k:nums.size()-1]
  Example:
  [1,2,3,4,5,6,7], k=2
  Step1: [7,6,5,4,3,2,1]
  Step2: [5,6,7,4,3,2,1]
  Step3: [5,6,7,1,2,3,4]
  
    Time Complexity: O(N), Space Complexity: O(1)

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
