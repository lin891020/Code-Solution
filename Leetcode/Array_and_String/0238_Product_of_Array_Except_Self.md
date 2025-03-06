# [238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The task is to compute an array where each element at index `i` represents the product of all elements in the input array except the one at `i`. The challenge is to solve this without using division and with a time complexity of O(n).

---

## Approach

1. **Left Product Calculation**:
   - Create an array `answer` initialized with 1's. The value at each index `i` in `answer` will be the product of all elements to the left of `i`.
   - Traverse the input array `nums` from left to right, maintaining a running product. Update `answer[i]` as you go.

2. **Right Product Calculation**:
   - Use a variable `right` initialized to 1 to keep track of the running product of elements to the right.
   - Traverse the input array from right to left. For each element, multiply `answer[i]` with `right` to include the product of all elements to the right of `i`.
   - Update `right` by multiplying it with `nums[i]` for the next iteration.

---

## Complexity

- **Time Complexity**: $$O(n)$$
  - The solution requires two passes through the input array, resulting in a linear time complexity.
  
- **Space Complexity**: $$O(1)$$
  - The space complexity is O(1) if we ignore the space used to store the output array, as no additional data structures proportional to the input size are used.

---

## Code (C++)

```cpp
/*************************************************
* Name:         productExceptSelf
* 
* Description:  Computes the product of all elements 
*               except self for each element in the array.
* 
* Arguments:    - vector<int>& nums: Input array
* 
* Returns:      - vector<int>: Resulting array
**************************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Calculate left products
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        // Calculate right products and finalize the result
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= right;
            right *= nums[i];
        }
        
        return answer;
    }
};
```
