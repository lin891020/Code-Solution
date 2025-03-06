# [135. Candy](https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem requires distributing the minimum number of candies to children based on their ratings, while satisfying two conditions:

1. Every child must receive at least one candy.
2. Children with higher ratings must receive more candies than their adjacent neighbors.

The greedy approach works here: make two passes over the array, first from left to right, then from right to left. In each pass, adjust the candy count based on the ratings.

---

## Approach

1. **Left to Right Pass**: Start by giving each child one candy. Then traverse the ratings from left to right. If the current child's rating is higher than the previous child's, increment their candy count.
2. **Right to Left Pass**: Traverse from right to left. If the current child's rating is higher than the next child's, ensure that they have more candies by taking the maximum of the current candy count and one more than the next child's candy count.
3. **Sum Up**: Sum all the candies to get the minimum number of candies needed.

---

## Complexity

- **Time Complexity**: $$O(n)$$
  - The solution requires two linear passes over the list, thus it takes linear time.
- **Space Complexity**: $$O(n)$$
  - The space complexity is linear because we use an additional array to store the candy count.

---

## Code (C++)

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        // Step 1: Initialize each child with 1 candy
        vector<int> candies(n, 1);

        // Step 2: Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Step 4: Sum all candies
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};
```
