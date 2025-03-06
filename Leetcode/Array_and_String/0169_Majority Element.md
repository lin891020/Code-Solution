# [169. Majority Element](https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem is to find the majority element, which is defined as an element that appears more than `n/2` times in an array.  
The key observation is that a majority element always dominates the count compared to other elements. This property can be leveraged using **Boyer-Moore Voting Algorithm**, which efficiently identifies the majority element in linear time with constant space.

---

## Approach

1. **Initialize Variables**:
   - `k` represents the candidate for the majority element.
   - `q` is the count of the candidate.

2. **Traverse the Array**:
   - If the current number matches the candidate (`k`), increment the count `q`.
   - If the current number does not match:
     - Decrement the count `q`.
     - If the count becomes zero, update the candidate `k` to the current number and reset `q` to 1.

3. **Return the Candidate**:
   - The candidate `k` at the end of the loop will be the majority element.

---

## Complexity

- **Time Complexity**: $$O(n)$$  
  - We traverse the array once, where $$n$$ is the size of the array.
- **Space Complexity**: $$O(1)$$  
  - Only two variables (`k` and `q`) are used.

---

## Code (C++)

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int k = nums[0];  // Candidate for majority element
        int q = 0;        // Count of the candidate
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k) {
                q++;  // Increment count if current element matches candidate
            } else {
                q--;  // Decrement count if current element differs
                if (q < 0) {  // Reset candidate and count
                    k = nums[i];
                    q = 1;
                }
            }
        }
        return k;  // Return the majority element
    }
};
```
