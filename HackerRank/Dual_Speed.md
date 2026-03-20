# Dual Speed

Process an array using two pointers to determine the minimum valid segment size.

Given an array `arr`, process it using pointers P1 and P2 and a segment size `segSize` as follows:

1. Start with **P1 = 0** and **P2 = 1**
2. Compare `arr[P1]` with all elements in a subarray starting at `arr[P2]` and including `segSize` elements (or until the end of arr)
3. If `arr[P1]` is **greater than or equal to** all elements in the subarray, increment **P1 by 1** and **P2 by segSize**
4. Repeat until the entire array has been processed

Determine the **minimum value of segSize** that allows the entire array to be processed successfully, or return **-1** if not possible.

---

## Constraints
- 1 ≤ n ≤ 5000
- 1 ≤ arr[i] ≤ 10⁹

---

## Example
```
arr = [11, 9, 10, 8, 10, 9]
Minimum segSize = 4
```

---

## Sample Cases
| Input | Output |
|-------|--------|
| [11, 9, 7, 7, 7, 6, 5] | 1 |
| [13, 6, 6, 1, 3, 3, 5] | 2 |

# Solution
| Solution | Time | Space |
|------|-----------|-----------|
| Brute Force | O(n²) | O(1) |
| Sparse Table | O(n log n) | O(n log n) |
| Monotonic Stack | O(n) | O(n) |
# Solution - Brute Force

## Intuition
The problem asks for the minimum `segSize` such that pointer P1 can always "guard" the next `segSize` elements. We try every possible `segSize` from 1 to n, and for each one simulate the entire process. The first `segSize` that successfully processes the entire array is our answer. If none works, return -1.

---

## Approach
1. **Brute Force**: Try every `segSize` from 1 to n
2. **Simulate**: For each `segSize`, use two pointers P1 and P2 to walk through the array
3. **Guard Check**: At each step, verify `arr[P1] >= max(arr[P2:P2+segSize])`
4. **Early Return**: Return the first `segSize` that succeeds, or -1 if none works

---

## Complexity
- **Time Complexity**: $$O(n^2)$$
  - Outer loop tries each segSize → O(n), inner simulation → O(n)
- **Space Complexity**: $$O(1)$$
  - Only uses a few pointers and variables

---

## Code (Python3)
```python
def dualSpeed(arr):
    n = len(arr)
    
    for i in range(1, n):
        p1 = 0
        p2 = 1
        success = True
        
        while p2 < n:
            if arr[p1] >= max(arr[p2:p2 + i]):
                p1 += 1
                p2 += i
            else:
                success = False
                break
        
        if success:
            return i
    
    return -1
```

---

# Solution - Sparse Table 

## Intuition
The key insight is that we need to repeatedly find the maximum value in a range efficiently. Instead of recomputing `max()` each time in O(n), we can precompute a **Sparse Table** for **Range Maximum Query (RMQ)** in O(1) per query. We still try each `segSize`, but each simulation becomes faster.

---

## Approach
1. **-1 Check**: If any element exceeds `arr[0]`, return -1 immediately
2. **Build Sparse Table**: Precompute range maximums in O(n log n)
3. **RMQ Query**: Answer any range max in O(1)
4. **Try each segSize**: For each seg, simulate the process using O(1) queries
5. **Return** the first segSize that succeeds

---

## Complexity
- **Time Complexity**: $$O(n \log n)$$
  - Building sparse table: O(n log n)
  - All simulations combined: O(n log n)
- **Space Complexity**: $$O(n \log n)$$
  - Sparse table stores log(n) layers of size n

---

## Code (Python3)
```python
def dualSpeed(arr):
    n = len(arr)
    
    # Edge case
    if n <= 1:
        return 1
    
    # -1 check
    if max(arr[1:]) > arr[0]:
        return -1
    
    # =====================
    # Build Sparse Table
    # =====================
    log = [0] * (n + 1)
    for i in range(2, n + 1):
        log[i] = log[i // 2] + 1
    
    k = log[n] + 1
    st = [arr[:]] + [[0] * n for _ in range(k - 1)]
    
    for j in range(1, k):
        for i in range(n - (1 << j) + 1):
            st[j][i] = max(st[j-1][i], st[j-1][i + (1 << (j-1))])
    
    # =====================
    # RMQ Query O(1)
    # =====================
    def query(l, r):
        j = log[r - l + 1]
        return max(st[j][l], st[j][r - (1 << j) + 1])
    
    # =====================
    # Try each segSize
    # =====================
    def can(seg):
        p1, p2 = 0, 1
        while p2 < n:
            r = min(n - 1, p2 + seg - 1)
            if query(p2, r) > arr[p1]:
                return False
            p1 += 1
            p2 += seg
        return True
    
    for seg in range(1, n + 1):
        if can(seg):
            return seg
    
    return -1
```

# Solution - Monotonic Stack

## Intuition
For each element `arr[j]`, we need to find the nearest previous element that can act as its "guard" (i.e., `>= arr[j]`). The distance between them determines the minimum `segSize` needed. The answer is simply the maximum such distance across all elements.

---

## Approach
1. **-1 Check**: If any element exceeds `arr[0]`, return -1 immediately since `arr[0]` is the ultimate guard
2. **Monotonic Stack**: Maintain a decreasing stack of `(value, index)` pairs
3. **For each element**: Pop elements smaller than current — stack top is the nearest valid guard
4. **Track max distance**: Answer is the maximum distance found

---

## Complexity
- **Time Complexity**: $$O(n)$$
  - Each element is pushed and popped at most once
- **Space Complexity**: $$O(n)$$
  - Stack stores at most n elements

---

## Code (Python3)
```python
def dualSpeed(arr):
    n = len(arr)

    if max(arr[1:]) > arr[0]:
        return -1
    
    stack = []
    max_dist = 1
    
    for j in range(n):
        while stack and stack[-1][0] < arr[j]:
            stack.pop()
        if stack:
            max_dist = max(max_dist, j - stack[-1][1])
        stack.append((arr[j], j))
    
    return max_dist
```

---



