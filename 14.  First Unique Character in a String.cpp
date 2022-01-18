//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
//  First Unique Character in a String

/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Input: s = "leetcode"
Output: 0
Input: s = "loveleetcode"
Output: 2
*/

/*Approach:
We push all the indices of the characters in a map.
Now, we iterate through the string and check if map size==1,
if yes, we return that index.
If no suitable index found, then we return -1;
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]].size()==1){
                return i;
            }
        }
        return -1;
    }
};
