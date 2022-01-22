//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
//  Reverse String
/*
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/

/*Approach
Recursive solution.
while l<r, it swaps characters at l and r index.
When l>=r, it returns.
As our string is reversed.
*/


class Solution {
public:
    void helper(vector<char>&s,int l,int r){
        if(l>=r) return;
        char ch=s[l]; s[l]=s[r]; s[r]=ch;
        helper(s,l+1,r-1);
    }
    void reverseString(vector<char>& s) {
        helper(s,0,s.size()-1);
    }
};

/*
Java Solution
Same Approach as above
*/
class Solution {
    public void reverseString(char[] s) {
        int l = 0;
        int r = s.length - 1;
        while ( l<r ) {
            swap(s, l, r);
            l++;
            r--;
        }
    }
    public void swap( char[] s, int i, int j ) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}