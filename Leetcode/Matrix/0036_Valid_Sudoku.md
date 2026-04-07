# [36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The goal is to verify whether a partially filled Sudoku board is valid.
For each filled cell, we must ensure the digit has not already appeared in:

* the same row
* the same column
* the same `3 x 3` sub-box

A convenient way to track this is to use hash sets.

---

## Approach

1. Create 3 collections of sets:

   * `rows[i]` stores digits seen in row `i`
   * `cols[j]` stores digits seen in column `j`
   * `boxes[k]` stores digits seen in sub-box `k`

2. Traverse every cell in the board:

   * Skip `'.'`
   * Compute the sub-box index with:

     ```cpp
     (r / 3) * 3 + (c / 3)
     ```

3. Before inserting a digit:

   * If it already exists in the corresponding row, column, or box set, return `false`

4. If the full board is processed without conflicts, return `true`

---

## Complexity

* **Time Complexity**: $$O(n^2)$$

  * We scan every cell exactly once.
* **Space Complexity**: $$O(1)$$

  * Since the board size is fixed at `9 x 9`, the extra memory is constant.

---

## Code(Python3)
```python
class Solution:
    /*************************************************
    * Name:        isValidSudoku
    *
    * Description: Checks whether a partially filled
    *              Sudoku board is valid.
    *
    * Arguments:   - List[List[str]>& board:
    *                a 9x9 Sudoku board
    *
    * Returns:     - bool:
    *                true if the board is valid,
    *                otherwise false
    **************************************************/
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        for r in range(9):
            for c in range(9):
                x = board[r][c]

                if x == '.':
                    continue

                box_id =  (r // 3)*3 + (c // 3) 

                if x in rows[r] or x in cols[c] or x in boxes[box_id]:
                    return False

                rows[r].add(x)
                cols[c].add(x)
                boxes[box_id].add(x)

        return True
```

## Code(C++)
```cpp

class Solution {
public:
    /*************************************************
    * Name:        isValidSudoku
    *
    * Description: Checks whether a partially filled
    *              Sudoku board is valid.
    *
    * Arguments:   - vector<vector<char>>& board:
    *                a 9x9 Sudoku board
    *
    * Returns:     - bool:
    *                true if the board is valid,
    *                otherwise false
    **************************************************/
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char x = board[r][c];

                if (x == '.') continue;

                int box_id = (r / 3) * 3 + (c / 3);

                if (rows[r].count(x) || cols[c].count(x) || boxes[box_id].count(x)) {
                    return false;
                }

                rows[r].insert(x);
                cols[c].insert(x);
                boxes[box_id].insert(x);
            }
        }

        return true;

    }
};
```