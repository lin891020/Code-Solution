# [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem is to find the longest common prefix from a list of strings. The idea is to start with the first string as the initial prefix and progressively compare it with each of the following strings. If the current string doesn't match the prefix, we shorten the prefix character by character until it either matches or becomes empty.

---

## Approach

1. **Initialize the prefix**: Set the first string as the initial prefix.
2. **Iterate through the remaining strings**: Compare each string with the current prefix.
3. **Shorten the prefix**: For each string that doesn't start with the prefix, progressively shorten the prefix until it matches or the prefix becomes an empty string.
4. **Return the result**: After iterating through all the strings, return the resulting prefix.

---

## Complexity

- **Time Complexity**: $$O(S)$$
  - The time complexity is $$O(S)$$, where $$S$$ is the total number of characters in all strings combined. Each character is compared once during the process.
  
- **Space Complexity**: $$O(1)$$
  - The space complexity is $$O(1)$$, as we only use a small amount of extra space for the prefix variable.

---

## Code (C++)

```cpp
/*************************************************
* Name:        longestCommonPrefix
* 
* Description: Finds the longest common prefix among strings 
*              by comparing and progressively shortening the prefix.
* 
* Arguments:   - vector<string>& strs: Input list of strings.
* 
* Returns:     - string: Longest common prefix.
**************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";  
        }

        
        string prefix = strs[0];

        
        for (int i = 1; i < strs.size(); i++) {
            
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);

                if (prefix.empty()) {
                    return "";
                }
            }
        }
        
        return prefix;
    }
};
```
