# [12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The task is to convert an integer to its corresponding Roman numeral representation. Roman numerals are formed using combinations of the following seven symbols: `I, V, X, L, C, D, M` with values 1, 5, 10, 50, 100, 500, and 1000 respectively. The idea is to use a greedy approach: always use the largest possible Roman numeral symbol until the number becomes zero.

---

## Approach

1. **Create a Mapping**: Set up a vector of pairs to map integer values to their corresponding Roman numeral strings, ordered from largest to smallest.
2. **Iterate Over the Mapping**: Loop through each pair in the mapping. For each pair, check if the current integer (`num`) is larger than or equal to the integer value of the pair.
3. **Construct the Roman Numeral**: If the current integer is larger than or equal to the integer value in the pair, append the Roman numeral string to the result and subtract the integer value from `num`.
4. **Repeat**: Continue this process until `num` is reduced to zero.

---

## Complexity

- **Time Complexity**: $$O(1)$$
  - The solution runs in constant time because the loop runs through a fixed number of Roman numeral symbols (13 in total).
- **Space Complexity**: $$O(1)$$
  - The space complexity is constant as well since we are only using a fixed amount of extra space.

---

## Code (C++)

```cpp
/*************************************************
* Name:         intToRoman
* 
* Description:  Converts an integer to a Roman numeral.
* 
* Arguments:    - int num: the integer to be converted.
* 
* Returns:      - string: the corresponding Roman numeral.
**************************************************/
class Solution {
public:
    string intToRoman(int num) {

        vector<pair<int, string>> roman_map = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result = "";

        for (const auto& pair : roman_map) {
            int value = pair.first;
            const string& symbol = pair.second;

            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        return result;

    }
};
```
