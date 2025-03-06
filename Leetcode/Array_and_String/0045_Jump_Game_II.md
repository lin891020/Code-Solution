# [45. Jump Game II](https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem requires finding the minimum number of jumps needed to reach the last index of an array. The key idea is to use a greedy approach, where at each position, we calculate the farthest index that can be reached. By updating the farthest point and counting jumps whenever we reach the current maximum range, we ensure the solution is optimal.

---

## Approach

1. **Initialization**:
   - Start with `steps` as 0, which counts the number of jumps.
   - `current_end` tracks the end of the current jump range.
   - `farthest` keeps track of the farthest point that can be reached in the current range.

2. **Iterate through the array**:
   - For each position `i`, calculate the farthest point that can be reached by `i + nums[i]`.
   - If `i` reaches `current_end`, increment the `steps`, and update `current_end` to `farthest`.
   - If `farthest` reaches or exceeds the last index, break out of the loop.

3. **Return the result**:
   - The number of `steps` needed to reach the last index.

---

## Complexity

- **Time Complexity**: $$O(n)$$
  - We iterate through the array once, where `n` is the number of elements in the array.
- **Space Complexity**: $$O(1)$$
  - Only a few extra variables are used, regardless of the input size.

---

## Code (C++)

```cpp
/*************************************************
* Name:         jump
* 
* Description:  Finds the minimum number of jumps needed to reach
*               the last index of an array.
* 
* Arguments:    - vector<int>& nums: List of non-negative 
*                 integers where each element represents the 
*                 maximum jump length at that position.
* 
* Returns:      - int: The minimum number of jumps required to 
*                 reach the last index.
**************************************************/
class Solution {
public:
    int jump(vector<int>& nums) {

        if (nums.size() == 1) {
            return 0;
        }

        int steps = 0;
        int current_end = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            
            farthest = max(farthest, i + nums[i]);

            if (i == current_end) {
                steps++;
                current_end = farthest;

                if (current_end >= nums.size() - 1) {
                    break;
                }
            }
        }
        
        return steps;
    }
};
```
