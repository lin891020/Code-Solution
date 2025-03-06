# [151. Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The goal of this problem is to reverse the words in a given string while ensuring that extra spaces between the words are handled properly, and leading or trailing spaces are removed.

---

## Approach

1. **Split the String**: We can use an `istringstream` to break the input string into words. This allows us to ignore extra spaces, as it automatically skips over multiple spaces between words.
2. **Reverse the Words**: After splitting the string into words, store the words in a vector. We can then reverse the order of the words in the vector using `std::reverse`.
3. **Join the Words**: Once the words are reversed, iterate through the vector and join them into a single string, adding a space between words but avoiding leading or trailing spaces.

---

## Complexity

- **Time Complexity**: $$O(n)$$
$$n$$ is the length of the input string. This is because we go through the string once to split it into words and then reverse the vector.
- **Space Complexity**: $$O(n)$$
Store the words in a vector which requires additional space proportional to the number of characters in the string.

---

## Code (C++)

```cpp
/*************************************************
* Name:        reverseWords
* 
* Description: Reverses the order of words in a given string
*              while removing extra spaces between words.
* 
* Arguments:   - std::string s: Input string with words separated
*                                by spaces.
* 
* Returns:     - std::string: A string with words in reversed order,
*                             and each word separated by a single space.
**************************************************/
class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);

        vector<string> words;
        string word, result;

        while (iss >> word) words.push_back(word);
        
        reverse(words.begin(), words.end());

        for (int i = 0; i < words.size(); i++) {
            if (i > 0) result += " ";
            result += words[i];
        }

        return result;
    }
};
```
