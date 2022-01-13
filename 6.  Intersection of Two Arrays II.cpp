//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/674/
//  6.Intersection of Two Arrays II
/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
*/
/*
Algorithm:
 Iterate over nums1 array and check if there is an occurence of that element in nums2 array.
 If yes, then add the element to the answer. Mark that element in the nums2 as -1 and break.
 
 Worst case Time complexity: O(N*N) Space complexity: O(1)
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nums1[i]); nums2[j]=-1;
                    break;
                }
            }
        }
        return ans;
    }
};

/*
Approach2: Using unorderd Maps:
1) Store frequencies of each element in nums1 in map1.
2) Store frequencies of each element in num2 in map2.
3) Iterate over any map1, and add of the frequency of the element between both maps into final answer.
Time complexity: O(N), space complexity: (N).
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1,m2;
        for(int i=0;i<nums1.size();i++) m1[nums1[i]]++;
        for(int i=0;i<nums2.size();i++) m2[nums2[i]]++;
        unordered_map<int,int>::iterator it;
        vector<int> ans;
        for(it=m1.begin();it!=m1.end();it++){
            int temp=min(it->second,m2[it->first]);
            for(int i=1;i<=temp;i++) ans.push_back(it->first);
        }
        return ans;
    }
};
