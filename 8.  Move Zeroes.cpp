//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/
//  8.Move Zeroes
/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
 Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Algorithm: 
1) Count the number of zeros.
2) Store the non zero elements in the front of the array.
3) Store the zero elements at the end of the array.

Time Complexit; O(N), Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) c++;
        }
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[x++]=nums[i];
            }
        }
        for(int i=nums.size()-c;i<nums.size();i++){
            nums[i]=0;
        }
    }
};
