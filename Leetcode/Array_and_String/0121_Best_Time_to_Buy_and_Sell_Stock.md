# [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem is to find the maximum profit that can be achieved by buying and selling a single stock given its prices over several days.  
The key idea is to **track the minimum price** encountered so far (`buy`) and calculate the profit if we sold the stock at the current price. We update the maximum profit (`profit`) whenever we find a better one.

---

## Approach

1. **Initialize Variables**:
   - Set `buy` to the first price to represent the minimum price so far.
   - Set `profit` to 0 to track the maximum profit.

2. **Iterate Through Prices**:
   - If the current price is lower than the minimum price (`buy`), update `buy`.
   - If the difference between the current price and `buy` is greater than the current `profit`, update `profit`.

3. **Return the Maximum Profit**:
   - At the end of the loop, `profit` contains the maximum possible profit.

---

## Complexity

- **Time Complexity**: $$O(n)$$  
  - We traverse the price array once, where $$n$$ is the number of days.
- **Space Complexity**: $$O(1)$$  
  - Only two variables (`buy` and `profit`) are used.

---

### Code (C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];  // Track the minimum price
        int profit = 0;       // Track the maximum profit
        
        for (int i = 1; i < prices.size(); i++) {
            if (buy > prices[i]) {
                buy = prices[i];  // Update minimum price
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;  // Update maximum profit
            }
        }
        return profit;
    }
};
```
