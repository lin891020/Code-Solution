# [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/?envType=study-plan-v2&envId=top-interview-150)


## **Intuition**  
The problem requires finding the **length of the longest substring without repeating characters**.  
- **Key observation**:  
  - We only need to maintain a **current substring with unique characters**.  
  - If a duplicate character is encountered, we **shrink the window** until all characters are unique again.  
  - This can be efficiently done using a **Sliding Window** approach with an **unordered_set** to track characters.  

---

## **Approach**  
1. **Use two pointers (`left`, `right`)**:  
   - `left` represents the start of the current substring.  
   - `right` expands the window by moving forward.  
2. **Use an `unordered_set<char>` to track unique characters**:  
   - If `s[right]` already exists in the set, it means we have a duplicate.  
   - Move `left` forward (shrinking the window) until `s[right]` is unique again.  
3. **Update the maximum length**:  
   - `maxLength = max(maxLength, right - left + 1)`.  

---

## **Complexity Analysis**  
- **Time Complexity**: $$O(n)$$  
  - Each character is visited **at most twice** (once by `right` and once by `left`), so the overall complexity is **O(n)**.  
- **Space Complexity**: $$O(128) = O(1)$$  
  - The `unordered_set` stores at most **128** ASCII characters, making it **constant space**.

---

## **Code (C++)**
```cpp
class Solution {
public:
/*************************************************
* Name:        lengthOfLongestSubstring
* 
* Description: Finds the length of the longest 
*              substring without repeating characters.
* 
* Arguments:   - string s: Input string.
* 
* Returns:     - int: Length of the longest unique substring.
**************************************************/
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

```