//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/727/
// 1) Remove Duplicates from Sorted Array

// Problem Statement.
/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
Return k after placing the final result in the first k slots of nums.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/
/*
Inout: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums=[0,1,2,3,4,_,_,_,_,_]
*/
/* Approach
Base case: when nums.size()==0. return 0;
Now, first we keep the first element of the array as it is and initiate output= ind =1.
Now,we iterate from index 2 till end of the array and check if nums[i]!=nums[i-1].
If it is true, them we and place the nums[i] at nums[ind] and increment the answer. That is we found a new element that is not present.
Time Complexity: O(N), Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ind=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]) nums[ind++]=nums[i];
        }
        return ind;
    }
};
