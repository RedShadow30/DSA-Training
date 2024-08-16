/*  Day 18:
    Problem 121 - Best Time to Buy and Sell Stock
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // two pointers
        int l = 0, r = 1;
        // keep track of max profit and current profit
        int maxP = 0, profit = 0;
        // traverse prices and check profit iff left $ < right $
        while(r < prices.size()) {
            // check if max profit needs to be updated
            if(prices[l] < prices[r]) {
                profit = prices[r]-prices[l];
                if(profit > maxP) maxP = profit;
            }
            // new minimum if right $ <
            else {
                l = r;
            }
            r++;
        }
    
        return maxP;
    }
};


/*  Time Complexity:     Space Complexity: 
    Explanation: There are two pointers, one to keep track of the left index (lowest aka buy) and another to keep track of right index (highest aka sell).
    We traverse through the list of numbers and find the profit of all the scenarios where the buy (left) is less than the sell (right). We compare it to
    the max profit and update if necessary. If the right is less than the left $ then we update the left because we have a new minimum. This does not
    change the max profit, however. We return max profit at the end.
 */