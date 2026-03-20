# Closest Numbers

You are given an array of **distinct integers**.

**Your task is to:**
1. Find the **smallest absolute difference** between any two elements in the array.
2. Print **all pairs** of numbers that have this smallest difference.
   - In each pair, the **smaller number comes first**
   - Print the pairs in **ascending order**

---

**Example 1**
- Input: `n = 4`, `numbers = [6, 2, 4, 10]`
- Output:
```
2 4
4 6
```
- Explanation: The minimum absolute difference is 2, and the pairs with that difference are (2, 4) and (4, 6).

---

**Example 2**
- Input: `n = 4`, `numbers = [4, -2, -1, 3]`
- Output:
```
-2 -1
3 4
```
- Explanation: The minimum absolute difference is 1, and the pairs with that difference are (-2, -1) and (3, 4).

---

**Constraints:**
- `2 ≤ n ≤ 10⁵`
- `-10⁹ ≤ numbers[i] ≤ 10⁹`


# Solution

## Intuition
The key insight is that the pair with the smallest absolute difference will always be **adjacent after sorting**. This eliminates the need for an O(n²) brute force comparison.

---

## Approach
1. **Sort the array**: Brings closest values next to each other
2. **Find minimum difference**: Single pass through adjacent pairs
3. **Collect and print pairs**: Another pass to find all pairs matching the minimum difference

---

## Complexity
- **Time Complexity**: $$O(n \log n)$$
  - Dominated by the sorting step
- **Space Complexity**: $$O(1)$$
  - Only a few variables used, sorting is in-place

---

## Code (Python3)
```python
def closestNumbers(numbers):
    # Step 1: Sort the array
    numbers.sort()
    
    # Step 2: Find minimum difference between adjacent elements
    min_diff = min(numbers[i+1] - numbers[i] for i in range(len(numbers)-1))
    
    # Step 3: Print all pairs with that minimum difference
    for i in range(len(numbers)-1):
        if numbers[i+1] - numbers[i] == min_diff:
            print(numbers[i], numbers[i+1])
```