# [6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem requires us to transform a given string into a Z-shaped pattern, then read it row by row to form the final result. The key observation is that the Z-shaped pattern alternates between moving downwards through the rows and then upwards. This pattern can be simulated by keeping track of the current row and switching directions whenever we hit the top or bottom row.

---

## Approach

1. **Edge Case Handling**: If the number of rows is 1 or the string length is less than or equal to `numRows`, the string doesn't need any transformation. Return the original string.

2. **Simulating the Z-Shape**:
   - Initialize a list (or vector in C++) with `numRows` empty strings to represent each row.
   - Use a pointer `row` to keep track of which row the current character belongs to and a `direction` variable to switch between moving down and moving up.
   - Traverse the string, adding each character to the correct row.
   - When you reach the top or bottom row, reverse the direction of movement.

3. **Concatenate Rows**: After all characters have been placed in their respective rows, concatenate all rows to form the final string.

---

## Complexity

- **Time Complexity**: $$O(n)$$, where $$n$$ is the length of the input string `s`. We iterate through the string exactly once, placing each character in the appropriate row.
- **Space Complexity**: $$O(n)$$, where $$n$$ is the length of the input string `s`. We use additional space to store each row of characters.

---

## Code (C++)

```cpp
/*************************************************
* Name:        Zigzag Conversion
* 
* Description: Converts a string into a zigzag pattern
*              based on the given number of rows.
* 
* Arguments:   - string s: The input string.
*              - int numRows: Number of rows for the zigzag.
* 
* Returns:     - string: The zigzag-converted string.
**************************************************/
class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1 || numRows >= s.length()) return s; 

        vector<string> rows(min(numRows, int(s.length())));

        int row = 0;
        int direction = 1;

        for (char c : s) {
            rows[row] += c;

            if (row == 0) {
                direction = 1;
            } else if (row == numRows - 1) {
                direction = -1;
            }

            row += direction;
        }

        string result;
        for (const string& rowStr :rows) {
            result += rowStr;
        } 

        return result;
    }
};
```
