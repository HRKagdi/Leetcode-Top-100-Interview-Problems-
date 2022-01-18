//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/
//  Valid Anagram

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/

/*
Input: s = "anagram", t = "nagaram"
Output: true
*/

/*
An anagram is a reordering of charcters of an array.
If we order thir characters somehow, then should be equal.
Thus we sort them, If they are equal, then return true. else return false;
Timecomplexity: O(n*log(n)), Space: O(1).

There is also an O(n) time complexity solution by map. It takes O(n) space also.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s==t);
    }
};
