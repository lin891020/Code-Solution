# [122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The key to maximizing profit in the stock trading problem, where multiple transactions are allowed, is to capture every increase in price. Essentially, we should buy on a day and sell on the next day whenever the price increases. This ensures we capture all upward trends in the stock prices.

---

## Approach

1. Initialize a variable to store the total profit.
2. Iterate through the price list from the first day to the second last day.
3. For each day, check if the price of the next day is higher than the current day.
4. If it is, add the difference to the total profit (i.e., simulate buying on the current day and selling on the next day).
5. Return the total profit after iterating through the price list.

---

## Complexity

- **Time Complexity**: $$O(n)$$
  - We iterate through the list of prices once, where n is the length of the list.
- **Space Complexity**: $$O(1)$$
  - We use a constant amount of space to store the profit.

---

## Code (C++)

```cpp
/*************************************************
 * Name:        maxProfit
 * 
 * Description: Given an array of prices where prices[i] is the price
 *              of a given stock on the i-th day, design an algorithm
 *              to maximize profit by completing as many transactions
 *              as possible (buying and selling one share of the    
 *              stock multiple times).
 *
 * Arguments:   - vector<int>& prices: A reference to a vector of
 *              integers representing the stock prices.
 *
 * Returns:     - int: The maximum profit that can be achieved.
 **************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                profit += prices[i + 1] - prices[i];
            }
        }
        return profit;
    }
};
```
