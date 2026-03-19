# [Contains Duplicate](https://neetcode.io/problems/duplicate-integer/question)


## Intuition

The goal is to quickly determine whether any number appears more than once in the array.
Instead of comparing every pair (which is slow), we can **track what we've already seen**.

A hash-based structure allows us to:

* Check existence in constant time
* Immediately detect duplicates during traversal

---

## Approach

1. **Use a HashSet (`unordered_set`)**
   Store elements as you iterate through the array.

2. **Traverse the array**

   * For each number:

     * If it already exists in the set → duplicate found → return `true`
     * Otherwise → insert it into the set

3. **Finish traversal**

   * If no duplicates are found → return `false`

---

## Complexity

* **Time Complexity**: $$O(n)$$

  * Each lookup and insertion in the hash set is $$O(1)$$ on average

* **Space Complexity**: $$O(n)$$

  * In the worst case, all elements are stored in the set

---

## Code(C++)

```cpp
/*************************************************
* Name:        hasDuplicate
* 
* Description: Determines if an array contains 
*              any duplicate elements using a hash set.
* 
* Arguments:   - vector<int>& nums: Input array
* 
* Returns:     - bool: true if duplicates exist, 
*                      false otherwise
**************************************************/
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int i : nums) {
            if (seen.count(i)) {
                return true;
            }
            seen.insert(i);
        }
        return false;
    }
};
```
```python
class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        seen = set()

        for x in nums:
            if x in seen:
                return True
            seen.add(x)

        return False
        
```
