//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/727/
// 1) Remove Duplicates from Sorted Array

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
