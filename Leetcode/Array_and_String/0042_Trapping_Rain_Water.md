# [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem requires calculating the total amount of water that can be trapped between columns of different heights. The amount of water trapped above each column depends on the height of the tallest columns to its left and right. The minimum of these two heights defines how much water can be trapped at that position.

## Approach

1. **Left and Right Maximum Arrays**:
   - We can use two arrays to store the maximum height to the left of each column (`left_max[]`) and the maximum height to the right (`right_max[]`).
2. **Water Calculation**:
   - For each column, the trapped water is calculated by the formula:  
     `water_at_i = min(left_max[i], right_max[i]) - height[i]`.
   - Accumulate this value for all columns to get the total trapped water.

## Complexity

- **Time Complexity**: $O(n)$
  - We iterate through the height array three times, once for filling the `left_max[]`, once for the `right_max[]`, and once for calculating the trapped water.
- **Space Complexity**: $O(n)$
  - Two additional arrays `left_max[]` and `right_max[]` are used to store the left and right maximum heights.

---

## Code (C++)

```cpp []
/*************************************************
* Name:        trap
* 
* Description: Calculates the trapped water between columns using 
*              left and right maximum heights.
* 
* Arguments:   - vector<int>& height: Heights of the columns.
* 
* Returns:     - int: Total trapped water.
**************************************************/
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        int water = 0;

        vector<int> left_max(n), right_max(n);

        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++) {
            water += min(left_max[i], right_max[i]) - height[i];
        }

        return water;
    }
};
```
