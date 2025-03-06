# [274. H-Index](https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem is to calculate the H-Index of a researcher based on their citation counts. The key observation is that the H-Index is the maximum number `H` such that the researcher has at least `H` papers with at least `H` citations each. This reduces the problem to counting how many papers have at least a certain number of citations.

---

## Approach

1. **Counting Citations**: Use a counting array to store the number of papers that have each possible citation count. For citation counts greater than or equal to the total number of papers, aggregate them into the last bucket (`counts[n]`).
2. **Determine H-Index**: Iterate from the maximum possible H-Index (which is the number of papers, `n`) down to 0. Maintain a running total of papers with at least `i` citations. The first index `i` where the total count of papers is at least `i` is the H-Index.

---

## Complexity

- **Time Complexity**: $O(n)$
  - The time complexity is $O(n)$ because we iterate over the citations once to populate the counting array and then iterate over the array to determine the H-Index.
- **Space Complexity**: $O(n)$
  - The algorithm uses an additional array of size $n + 1$ to store the citation counts.

---

## Code (C++)

```cpp
/*************************************************
* Name:        hIndex
* 
* Description: Calculates the H-Index of a researcher based on citation counts.
*              The approach is based on counting citations and determining the maximum H-Index.
* 
* Arguments:   - vector<int>& citations: A vector containing the citation counts for each paper.
* 
* Returns:     - int: The H-Index of the researcher.
**************************************************/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> counts(n + 1, 0);
        
        for (int num : citations)  {
            if (num >= n) {
                counts[n]++;
            } else {
                counts[num]++;
            } 
        }

        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += counts[i];
            if (count >= i) {
                return i;
            }
        }
        return 0;
    }
};
```
