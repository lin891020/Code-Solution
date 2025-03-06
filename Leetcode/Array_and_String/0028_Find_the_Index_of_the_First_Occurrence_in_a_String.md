# [28. Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem is about finding the first occurrence of the string `needle` in the string `haystack`. This is a classic string matching problem, where the goal is to check each possible starting position in `haystack` and compare the substring with `needle`. If a match is found, we return the starting index; otherwise, we return -1. If `needle` is an empty string, the result should always be 0.

---

## Approach

1. **Check edge case**: If `needle` is empty, return 0.
2. **Sliding window search**: Use a loop to go through each possible starting index in `haystack` where `needle` can fit. For each index, check if the substring from that position matches `needle`.
3. **Return index**: If a match is found, return the starting index. If no match is found by the end of the loop, return -1.

---

## Complexity

- **Time Complexity**: $$O(n * m)$$ where `n` is the length of `haystack` and `m` is the length of `needle`.
  - In the worst case, we compare each character of `needle` for each position in `haystack`.
- **Space Complexity**: $$O(1)$$
  - No additional space is used beyond the input strings.

---

## Code (C++)

```cpp
/*************************************************
* Name:        strStr
* 
* Description: Finds the first occurrence of `needle` in 
*              `haystack`. Returns the index if found, 
*              otherwise returns -1. If `needle` is empty, 
*              returns 0.
* 
* Arguments:   - string haystack: The main string.
*              - string needle: The substring to search for.
* 
* Returns:     - int: The starting index or -1 if not found.
**************************************************/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        int haystacklen = haystack.length();
        int needlelen = needle.length();

        for (int i = 0; i <= haystacklen - needlelen; i++) {
            if (haystack.substr(i, needlelen) == needle) {
                return i;
            }
        }

        return -1;
    }
};
```
