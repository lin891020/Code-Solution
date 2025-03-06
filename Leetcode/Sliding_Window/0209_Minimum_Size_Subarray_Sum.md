# [209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem is to find the minimal length of a contiguous subarray whose sum is greater than or equal to the given target. This can be effectively solved using the **Sliding Window** approach, as the window dynamically adjusts to ensure the sum condition is met while minimizing the subarray length.

---

## Approach

1. Use two pointers, `left` and `right`, to represent the sliding window.
2. Expand the window by moving the `right` pointer to include elements in the current sum.
3. When the `current_sum` exceeds or equals the `target`, calculate the length of the current subarray (`right - left + 1`) and update the `min_length`.
4. Shrink the window from the left by moving the `left` pointer forward and subtracting `nums[left]` from `current_sum` until the sum is less than the `target`.
5. Repeat until the `right` pointer traverses the entire array.
6. If no valid subarray is found (`min_length == INT_MAX`), return 0.

---

## Complexity

- **Time Complexity**: $$O(n)$$  
  - Both pointers traverse the array at most once.
- **Space Complexity**: $$O(1)$$
  - No additional space is used other than variables.

---

## Code (C++)

```cpp []
/*************************************************
* Name:        minSubArrayLen
* 
* Description: Finds the minimal length of a subarray 
*              whose sum is ≥ target.
* 
* Arguments:   - int target: The target sum.
*              - vector<int>& nums: Array of integers.
* 
* Returns:     - int: Minimal subarray length, or 0 if none.
**************************************************/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int current_sum = 0;
        int min_length = INT_MAX;
        
        for (int right = 0; right < nums.size(); right++) {
            current_sum += nums[right];

            while (current_sum >= target) {
                min_length = min(min_length, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }

        return min_length == INT_MAX ? 0 : min_length;
    }
};
```
