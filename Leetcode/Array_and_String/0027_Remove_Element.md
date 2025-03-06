# [27. Remove Element](https://leetcode.com/problems/remove-element/)

## Intuition

The problem requires us to remove all occurrences of a specific value `val` from an array **in-place** and return the length of the modified array.  
To efficiently solve this, we can use a pointer `index` to overwrite elements that are not equal to `val`.

---

## Approach

1. **Initialize a Pointer**:
   - Use `index` to track the position where the next valid element (not equal to `val`) should be placed.
   - Start `index` at 0.

2. **Traverse the Array**:
   - Iterate through the array.
   - For each element, if it is not equal to `val`, copy it to the position `index` and increment `index`.

3. **Return the Length**:
   - After traversal, `index` represents the length of the updated array with `val` removed.

---

## Complexity

- **Time Complexity**: $$O(n)$$  
  - We iterate through the array once, where $$n$$ is the size of the array.
- **Space Complexity**: $$O(1)$$  
  - No extra space is used; the operation is performed in-place.

---

## Code (C++)

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;  // Pointer to track the position for valid elements
        
        for (int i = 0; i < nums.size(); i++) {
            if (val != nums[i]) {  // Check if the current element is not equal to val
                nums[index] = nums[i];  // Overwrite the element
                index++;  // Move the pointer forward
            }
        }
        return index;  // Return the length of the updated array
    }
};
```
