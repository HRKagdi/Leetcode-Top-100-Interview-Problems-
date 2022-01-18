//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/
//2.  Best Time to Buy and Sell Stock II
/*
ou are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. 
You can only hold at most one share of the stock at any time.
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
*/
/*
Input: prices = [7,1,5,3,6,4]
Output: 7
Input: prices = [1,2,3,4,5]
Output: 4
Input: prices = [7,6,4,3,1]
Output: 0
*/
/*
Algorithm: Peak Valley Approach
1) Find all the peaks and valleys of the array.
2) Interate over peaks and valleys array and add the difference of adjacent peak and valley.
3) Return the answer.
Note: Take care of first and last elements.
Check if first element is valley and last element is peak.
if yes then add them to corresponding arrays.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        vector<int> peaks,valleys;
        if(prices[0]<prices[1]){
            valleys.push_back(prices[0]);
        }
        for(int i=1;i<prices.size()-1;i++){
            if(prices[i]<=prices[i-1] && prices[i]<prices[i+1]){
                valleys.push_back(prices[i]);
            }
            else if(prices[i]>prices[i-1] && prices[i]>=prices[i+1]){
                peaks.push_back(prices[i]);
            }
        }
        if(prices[prices.size()-1]>prices[prices.size()-2]){
            peaks.push_back(prices[prices.size()-1]);
        }
        int p=0; int v=0; int ans=0;
        while(p<peaks.size() && v<valleys.size()){
            //cout<<peaks[p]<<" "<<valleys[v]<<endl;
            ans+=(peaks[p++]-valleys[v++]);
        }
        return ans;
    }
};


/// Contributer: https://github.com/harshchaplot
// Solutions in Java by Harsh Chaplot
/*Approach: Whenever we see an element greater than the top of the stack we pop it and find the profit we can make 
with this trade and we keep on doing that until we have an empty stack or we see an element greater 
than the current element(in which case we won't be able to make any profit). We take the maximum of the 
profit obtained here and add it to our total profit. 
If the stack is empty or the current element is greater than the top of the stack we simply push it onto the stack.
*/

class Solution {
    public int maxProfit(int[] prices) {
        Stack<Integer> stack = new Stack<>();
        int n = prices.length;
        int totalProfit = 0;
        for ( int i=0; i<n; i++ ) {
            int currMax = 0;
            while ( !stack.isEmpty() && stack.peek()<prices[i] ) {
                currMax = Math.max(currMax, prices[i]-stack.pop());
            }
            totalProfit += currMax;
            stack.push(prices[i]);
        }
        return totalProfit;
    }
}

/*
Also, we can approach this problem with constant space and O(n). In the previous approach we were(in the worst case) visiting every element twice, essentially making it O(2*n).

Approach: Every time we see an element greater than the previous element we add the difference to our profit and return this profit at the end. 
This works because we can sell and buy a stock on the same day. Also if we have something like [1,4,5],
then usually what we do is buy on day 1 and sell on day 3 but since there are no restrictions on the number of trades we can make, 
we can buy on day 1 -> sell on day 2, again buy on day 2 -> sell on day 3 which yields us the same profit.
*/

class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        for ( int i=0; i<prices.length-1; i++ ) {
            if ( prices[i+1]>prices[i] ) {
                profit += prices[i+1] - prices[i];
            }
        }
        return profit;
    }
}
