# [80. Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

To remove extra duplicates in a sorted array without using extra space, we can use the two-pointer technique. By comparing the current element with the element two positions behind, we can ensure each element appears at most twice.

---

## Approach

1. **Initialization**: Initialize the write pointer `j` to 1, as the first element will always be kept.
2. **Traversal**: Start traversing the array from the second element.
3. **Comparison**: Compare the current element `nums[i]` with the element at position `j-2`.
4. **Update**: If they are different, it means the current element can be included in the result, so we write it at the position of the write pointer and increment `j`.
5. **Return Length**: After the loop, `j` will represent the length of the array with duplicates removed.

---

## Complexity

- **Time Complexity**: $$O(n)$$
    n is the length of the array, as we traverse the array once.
- **Space Complexity**: $$O(1)$$
    Since we modify the array in place without using extra space.

---

## Code (C++)

```cpp
/*************************************************
 * Name:        removeDuplicates
 * 
 * Description: Removes duplicates from a sorted array such that 
 *              each element appears at most twice.
 * 
 * Arguments:   - vector<int>& nums: reference to the sorted array 
 *              of integers.
 * 
 * Returns:     - int: the length of the modified array with 
 *              duplicates removed.
 **************************************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int j = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (j == 1 || nums[i] != nums[j - 2]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
```
