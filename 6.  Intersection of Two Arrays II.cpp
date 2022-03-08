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
Time complexity: O(N), space complexity: O(N).
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

/*
Java Solution
Approach 1
*/
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        ArrayList<Integer> list = new ArrayList<>();
        for ( int i=0; i<nums1.length; i++ ) {
            for ( int j=0; j<nums2.length; j++ ) {
                if ( nums1[i]==nums2[j] ) {
                    list.add(nums1[i]);
                    nums2[j] = -1;
                    break;
                }
            }
        }
        int[] res = new int[list.size()];
        int k = 0;
        for ( int i: list ) {
            res[k++] = i;
        }
        return res;
    }
}

/*
Java Solution
Approach 2
*/
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map1 = new HashMap<>();
        HashMap<Integer, Integer> map2 = new HashMap<>();
        ArrayList<Integer> commonElements = new ArrayList<>();
        for ( int i: nums1 ) {
            map1.put(i, map1.getOrDefault(i, 0)+1);
        }
        for ( int i: nums2 ) {
            map2.put(i, map2.getOrDefault(i, 0)+1);
        }
        for ( int key: map1.keySet() ) {
            int count = Math.min(map1.get(key), map2.getOrDefault(key, 0));
            for ( int i=0; i<count; i++ ) {
                commonElements.add(key);
            }
        }
        int[] res = new int[commonElements.size()];
        int k = 0;
        for ( int i: commonElements ) {
            res[k++] = i;
        }
        return res;
    }
}

/*
Java Solution
Approach 3
Algorithm:
1. Sort both the arrays.
2. Keep two pointers currently pointing at the start of both arrays and add this number to arraylist.
3. If values at both pointers are equal then increment both pointers, else increment that pointer which has lower value.
4. Store the arraylist into an array and return it.

Time Complexity: O(nlogn) and Space Complexity: O(1);
*/
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int ptr1 = 0;
        int ptr2 = 0;
        ArrayList<Integer> as = new ArrayList<>();
        while(ptr1<nums1.length && ptr2<nums2.length){
            if(nums1[ptr1]==nums2[ptr2]){
                as.add(nums1[ptr1]);
                ptr1++;
                ptr2++;
            }
            else if(nums1[ptr1]>nums2[ptr2])
                ptr2++;
            else
                ptr1++;
        }
        int a[] = new int[as.size()];
        for(int i=0;i<a.length;i++)
            a[i] = as.get(i);
        return a;
    }
}