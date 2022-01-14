//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
// 9. Two Sum
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Input: nums = [3,2,4], target = 6
Output: [1,2]

Algorithm:
1) Store the indices of the all the elemnts in an unordered Map.
2) Iterate over the array and check if (target- nums[i]) is present in map or not.
3) If yes, return their indices.
4) Finally if no such pair found return empty array.

TimeComplexity: O(N), Space complexity: O(N).
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;vector<int> ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(m[target-nums[i]]>i){
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
                break;
            }
        }
        return ans;
    }
};
