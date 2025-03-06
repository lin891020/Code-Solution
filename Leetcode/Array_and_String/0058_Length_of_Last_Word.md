# [58. Length of Last Word](https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The task is to determine the length of the last word in a given string. A "word" is defined as a maximal substring consisting of non-space characters.
To solve this problem, the key observations are:

1. The last word will always end at the last non-space character in the string.
2. Any trailing spaces in the string can be ignored.
3. After identifying the last word, its length can be calculated directly by scanning backward from the end of the string.

---

## Approach

1. **Trim Spaces**:
   - Remove any trailing and leading spaces from the string using string manipulation functions.
2. **Find the Last Word**:
   - Locate the last space in the trimmed string.
   - If no spaces exist, the entire string is the last word.
   - Otherwise, calculate the length of the substring following the last space.
3. **Return the Length**:
   - Compute the length of the identified last word and return it.

### Steps in Code

- Use `erase` and `find_last_not_of` to trim trailing spaces.
- Use `find_last_of` to locate the last space in the string.
- Use substring length calculations to determine the last word's length.

---

## Complexity

- **Time Complexity**: $O(n)$
  - Trimming the string and locating the last space both involve a single pass over the string.
- **Space Complexity**: $O(1)$
  - No additional data structures are used; operations are performed in-place.

---

## Code (C++)

```cpp []
/*************************************************
* Name:        
* 
* Description: Calculates the length of the last word
*              in a given string.
* 
* Arguments:   - string s: The input string.
* 
* Returns:     - int: Length of the last word.
**************************************************/

class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(" ") + 1);
        s.erase(0, s.find_first_not_of(" "));
        
        size_t last_space = s.find_last_of(" ");
        
        if (last_space == string::npos) {
            return s.length();
        } else {
            return s.length() - last_space - 1;
        }
    }
};
```
