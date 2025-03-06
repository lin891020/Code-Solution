# [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem is to merge two sorted arrays `nums1` and `nums2` into a single sorted array in-place. `nums1` has enough space at the end to accommodate all elements from `nums2`. The key is to carefully merge the elements and ensure the resulting array remains sorted.

---

## Approach

1. **Append Elements from `nums2` to `nums1`**:
   - Start from the position `m` in `nums1` (end of initial elements).
   - Copy all elements from `nums2` into `nums1`.

2. **Sort the Resulting Array**:
   - Use `sort()` to sort the updated `nums1` after all elements are combined.

---

## Complexity

- **Time Complexity**: $$O((m + n) \log (m + n))$$  
  - Copying elements takes $$O(n)$$, and sorting the combined array takes $$O((m + n) \log (m + n))$$.
- **Space Complexity**: $$O(1)$$  
  - No additional space is used as the merging is done in-place.

---

## Code (C++)

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j = 0, i = m; j < n; j++) {  // Copy elements from nums2 to nums1
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(), nums1.end());  // Sort the resulting array
    }
};
```
