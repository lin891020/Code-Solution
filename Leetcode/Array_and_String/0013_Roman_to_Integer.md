# [13. Roman to Integer](https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

When parsing Roman numerals, handling the subtraction rule is key. Parsing from right to left allows us to naturally handle the subtraction rule without needing to check future characters multiple times within the loop.

---

## Approach

1. Define a function `romanToInt(char c)` that converts a single Roman character to its corresponding integer.
2. Use a `for` loop to traverse the entire string `s` from right to left.
3. During the traversal, if the current character's value is less than the previous value, perform a subtraction; otherwise, perform an addition.
4. The accumulated result will be the integer equivalent of the Roman numeral.

---

## Complexity

- **Time Complexity**: $$O(n)$$
    Where n is the length of the string. We need to traverse the entire string once.
- **Space Complexity**: $$O(1)$$
    Only a fixed amount of extra space is used for storing intermediate results and variables.

---

## Special Explanation

- **Why parse from right to left?**
  - In Roman numerals, smaller numbers placed before larger numbers indicate subtraction (e.g., IV represents 4). Parsing from right to left allows us to naturally handle this subtraction rule because if the current value is less than the previous value, it indicates that we need to subtract the current value. This reduces the need to check future characters when processing each character, making the logic more straightforward and intuitive.

---

## Code (C++)

```cpp
class Solution {
public:
    /*************************************************
    * Name:        romanToInt
    *  
    * Description: Converts a single Roman character to its corresponding integer value.
    * 
    * Arguments:   - c: char - the Roman character
    * 
    * Returns:     - int - the corresponding integer value
    *************************************************/
    int romanToInt(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    /*************************************************
    * Name:        romanToInt
    *  
    * Description: Calculates the total by traversing the string 
    *              from right to left and adding or subtracting 
    *              based on Roman numeral rules.
    * 
    * Arguments:   - s: string - the string containing the Roman numeral
    * 
    * Returns:     - int - the corresponding integer value
    *************************************************/
    int romanToInt(string s) {
        int total = 0;
        int preValue = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            int currentValue = romanToInt(s[i]);

            if (currentValue < preValue) {
                total -= currentValue;
            } else {
                total += currentValue;
            }

            // Update the previous value
            preValue = currentValue;
        }
        return total;
    }
};
```
