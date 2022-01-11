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
