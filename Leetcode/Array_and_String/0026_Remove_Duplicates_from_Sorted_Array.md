# [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

## Intuition

The problem is to remove duplicates from a sorted array **in-place** and return the length of the updated array. Since the array is sorted, all duplicates will appear consecutively. We can utilize this property to overwrite duplicate values efficiently while maintaining the original array's order.

---

## Approach

1. **Initialize a Pointer**:
   - Use `index` to track the position where the next unique element should be placed.
   - Start `index` at 1 since the first element is always unique.

2. **Traverse the Array**:
   - Iterate through the array starting from the second element.
   - Compare the current element `nums[i]` with the previous unique element `nums[index - 1]`.
   - If they are different, assign `nums[i]` to `nums[index]` and increment `index`.

3. **Return the Length**:
   - After traversing the array, `index` represents the number of unique elements.

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
    int removeDuplicates(vector<int>& nums) {
        int index = 1;  // Pointer to track position for the next unique element
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[index - 1] != nums[i]) {  // Check if current element is unique
                nums[index] = nums[i];  // Place the unique element
                index++;  // Move the pointer forward
            }
        }
        return index;  // Return the length of the updated array
    }
};
```
