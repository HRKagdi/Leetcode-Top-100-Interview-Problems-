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

/*
Java Solution
Same approach as above
*/
class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, ArrayList<Integer>> map = new HashMap<>();
        int n = s.length();
        for ( int i=0; i<n; i++ ) {
            char c = s.charAt(i);
            ArrayList<Integer> list = map.getOrDefault(c, new ArrayList<Integer>());
            list.add(i);
            map.put(c, list);
        }
        for ( int i=0; i<n; i++ ) {
            char c = s.charAt(i);
            if ( map.get(c).size()==1 ) {
                return i;
            }
        }
        return -1;
    }
}

/*
Java Solution
Same approach as above, just a minor change. Instead of storing the arraylist of indexes, we just store the frequencies of a character. After that we iterate and return index of the first element with frequency of 1.
*/
class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        int n = s.length();
        int min = (int)1e5 + 1;
        for ( int i=0; i<n; i++ ) {
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c, 0)+1);
        }
        for ( int i=0; i<n; i++ ) {
            char c = s.charAt(i);
            if ( map.get(c)==1 ) {
                return i;
            }
        }
        return -1;
    }
}

/*
Java Solution
Approach:
We create a firstIndex array that keeps track of a couple of things:
1. Have we seen this character? If not, then it will be null
2. What is the first index of this character?
3. If we see this character again in the string, then it will store -1(representing that this is not the answer).

After one pass we return the minimum index of in the firstIndex array.
Time Complexity: O(n), single pass. Space Complexity: O(26) = O(1).(One array of length 26)
*/
class Solution {
    public int firstUniqChar(String s) {
        int n = s.length();
        Integer[] firstIndex = new Integer[26];
        int min = (int)1e5 + 1;
        for ( int i=0; i<n; i++ ) {
            int idx = s.charAt(i)-'a';
            if ( firstIndex[idx]==null ) {
                firstIndex[idx] = i;
            } else {
                firstIndex[idx] = -1;
            }
        }
        for ( int i=0; i<26; i++ ) {
            if ( firstIndex[i]!=null && firstIndex[i]!=-1 ) {
                min = Math.min(min, firstIndex[i]);
            }
        }
        return min==(int)1e5+1 ? -1 : min;
    }
}