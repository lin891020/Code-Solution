# [380. Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The problem is to design a data structure that supports `insert`, `remove`, and `getRandom` operations in constant time. The key observation is to use a combination of a dynamic array and a hash table, which reduces the problem to efficient index-based operations and direct access to elements.

---

## Approach

1. **Insert Operation**: Use an unordered map to check if the element already exists in constant time. If not, add it to the vector and store its index in the map.
2. **Remove Operation**: To delete an element in constant time, swap it with the last element in the vector and update the map. Then remove the last element from the vector.
3. **GetRandom Operation**: Generate a random index within the bounds of the vector's size and return the element at that index.

---

## Complexity

- **Time Complexity**: $O(1)$
  - The time complexity for `insert`, `remove`, and `getRandom` operations is $O(1)$ because each operation is either a direct access or an update in a hash table or a vector.
- **Space Complexity**: $O(n)$
  - The algorithm uses additional space for the hash table, which stores indices for up to $n$ elements, resulting in $O(n)$ space complexity.

---

## Code (C++)

```cpp
/*************************************************
* Name:        RandomizedSet
* 
* Description: Implements a data structure that supports 
*              insert, delete, and getRandom operations 
*              in average O(1) time.
* 
* Arguments:   None for constructor, int for insert and remove
* 
* Returns:     - bool for insert and remove: true if the operation
*                was successful, false otherwise
*              - int for getRandom: a randomly selected element
**************************************************/
class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> numIndex;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (numIndex.find(val) != numIndex.end()) {
            return false;
        }
        nums.push_back(val);
        numIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (numIndex.find(val) == numIndex.end()) {
            return false;
        }
        
        int lastElement = nums.back();
        int idx = numIndex[val];

        nums[idx] = lastElement;
        numIndex[lastElement] = idx;

        nums.pop_back();
        numIndex.erase(val);

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};
```
