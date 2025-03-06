# [55. Jump Game](https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The task is to determine if you can jump to the last index of the array starting from the first index. By maintaining the farthest position that can be reached at any point, we can determine if the last index is reachable.

---

## Approach

1. **Initialize `farthest`**: Set `farthest` to 0, representing the farthest position reachable at the start.
2. **Traverse the array**: For each index, check if it is reachable. If not, return `false`.
3. **Update `farthest`**: Update `farthest` to be the maximum of its current value and the sum of the current index and the value at that index.
4. **Check if last index is reachable**: If at any point `farthest` reaches or exceeds the last index, return `true`.
5. **Final check**: After the loop, if `farthest` has not reached the last index, return `false`.

---

## Complexity

- **Time Complexity**: $$O(n)$$
  - The algorithm only requires a single pass through the array, where $$n$$ is the length of the array.
- **Space Complexity**: $$O(1)$$
  - The algorithm uses a constant amount of additional space.

---

## Code (C++)

```cpp
/*************************************************
* Name:         canJump
* 
* Description:  Determines if the last index can be reached from 
*               the first index
* 
* Arguments:    - vector<int>& nums: The input array of 
*                 non-negative integers
* 
* Returns:      - bool: True if the last index can be reached, 
*                 otherwise false
**************************************************/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        if (nums.size() == 1) {
            return true;
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            
            if (i > farthest) {
                return false;
            }
            
            
            farthest = max(farthest, i + nums[i]);

            
            if (farthest >= nums.size() - 1){
                return true;
            } 
        }
        return false;
    }
};
```
