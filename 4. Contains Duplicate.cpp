//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/
//4.  Contains Duplicate

//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
/*
Input: nums = [1,2,3,1]
Output: true
Input: nums = [1,2,3,4]
Output: false
*/
/*
Algo:
1) Sort the array.
2) Check if two adjacent elements are equal. If yes, return true.
3) If you find no such pairs, return false.
Time Complexity: (N*log(N)), Space complexity: O(1) 
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==1) return false;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) return true;
        }
        return false;
    }
};
