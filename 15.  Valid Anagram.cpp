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

/*
Java Solution
Same approach as above
*/
class Solution {
    public boolean isAnagram(String s, String t) {
        char[] s1 = s.toCharArray();
        char[] s2 = t.toCharArray();
        Arrays.sort(s1);
        Arrays.sort(s2);
        return String.valueOf(s1).equals(String.valueOf(s2));
    }
}

/*
Java Solution
Approach:
We create an array of length 26 to store the frequencies of each character. When we iterate over the first string we increment the frequency of that character and while going over the second string we decrement the count. At the end we check if the whole array contains 0 then they are anagrams otherwise they are not.
Time Complexity: O(n), Space: O(26) = O(1).
*/
class Solution {
    public boolean isAnagram(String s, String t) {
        int[] count = new int[26];
        int n = s.length();
        if ( n!=t.length() ) {
            return false;
        }
        for ( int i=0; i<n; i++ ) {
            count[s.charAt(i)-'a']++;
        }
        for ( int i=0; i<n; i++ ) {
            count[t.charAt(i)-'a']--;
        }
        for ( int i=0; i<26; i++ ) {
            if ( count[i]!=0 ) {
                return false;
            }
        }
        return true;
    }
}