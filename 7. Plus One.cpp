//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/
// 7. Plus One

/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
Input: digits = [1,2,3]
Output: [1,2,4]
Input: digits = [9]
Output: [1,0]
*/

/*
 Algorithm:
 1) Check for first digit which is less than 9 from right side of the array. 
 2) If the digits[i]==9, make it 0.
 3) If all the elements of the array are 9, then return and array of size digits+1. Here first element is 1 and rest is zero.
 4) Else increment first digit that is less tha 9 by 1. return the digits array.
 Time Complexity: O(N), space complexity:O(1).
*/


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        while(i>=0){
            if(digits[i]<9) break;
            digits[i--]=0;
        }
        if(i==-1){
            vector<int> v(digits.size()+1,0);
            v[0]=1;
            return v;
        }
        digits[i]++;
        return digits;
    }
};
