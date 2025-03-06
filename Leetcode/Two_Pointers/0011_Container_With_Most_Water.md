# [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem requires finding the maximum area of water that can be trapped between two vertical lines. The key observation is:

- The area of water is determined by the height of the shorter line and the width between the two lines.
- Moving the taller line inward won't increase the area since the shorter line determines the height of the container. Thus, we should always move the pointer pointing to the shorter line to potentially find a taller line and maximize the area.

This insight forms the basis of the **Two Pointer Method**, which eliminates unnecessary comparisons and reduces the time complexity to **O(n)**.

---

## Approach

1. **Initialization**:
   - Place two pointers: `left` at the start and `right` at the end of the `height` array.
   - Initialize a variable `max_area` to store the maximum area encountered.

2. **Iterate Until the Pointers Meet**:
   - Calculate the current area using:

    ```cpp
        area = (right - left) * min(height[left], height[right])
    ```

   - Update `max_area` if `area` is greater than the current `max_area`.

3. **Move the Pointer of the Shorter Line**:
   - If `height[left] < height[right]`, increment `left` to potentially find a taller line on the left.
   - Otherwise, decrement `right` to potentially find a taller line on the right.

4. **Terminate When the Pointers Meet**:
   - When `left` equals `right`, stop the iteration and return the `max_area`.

---

## Complexity

- **Time Complexity**: $$O(n)$$
Each pointer moves at most `n` steps, where `n` is the length of the `height` array. Each step performs a constant amount of work.

- **Space Complexity**: $$O(1)$$
The algorithm uses only a constant amount of extra space for variables.

---

## Code (C++)

```cpp []
/*************************************************
* Name:        maxArea
* 
* Description: Finds the maximum area of water a container 
*              can hold given an array of heights.
* 
* Arguments:   - vector<int>& height: Array of line heights.
* 
* Returns:     - int: The maximum water area.
**************************************************/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            int width = right - left;
            int current_area = width * min(height[left], height[right]);
            max_area = max(max_area, current_area);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
```
