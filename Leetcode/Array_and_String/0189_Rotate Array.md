# [189. Rotate Array](https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem requires rotating an array to the right by `k` steps. A straightforward way to achieve this is to use an additional array to store the rotated version and then copy the result back to the original array. The modulo operation ensures that the indices wrap around when they exceed the array's length.

---

## Approach

1. **Create a new vector**: This vector will hold the rotated elements.
2. **Calculate new positions**: For each element in the original vector, calculate its new position using the formula `(k + i) % n`.
3. **Copy elements**: Place each element in its new position in the new vector.
4. **Update the original vector**: Copy the contents of the new vector back to the original vector.

---

## Complexity

- **Time Complexity**: $$O(n)$$
    `n` is the size of the array. Each element is accessed and placed in the new vector exactly once.
- **Space Complexity**: $$O(n)$$
    Additional space is used for the new vector of the same size as the original.

---

## Code (C++)

```cpp
/*************************************************
* Name:        Rotate Array
*
* Description: Rotate an array to the right by k steps.
*
* Arguments:    - vector<int>& nums: Reference to the array to rotate.
*               - int k: Number of steps to rotate the array.
*
* Returns:      void
**************************************************/
#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> rotated(n);

        for (int i = 0; i < n; i++) {
            rotated[(k + i) % n] = nums[i];
        }
        
        nums = rotated;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    solution.rotate(nums, k);

    // Output the rotated result
    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}
```
