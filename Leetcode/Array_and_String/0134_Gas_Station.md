# [134. Gas Station](https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150)

## Intuition

The task is to find a starting gas station index that allows completing a circular route of gas stations, where at each station, a certain amount of gas is provided, and a certain amount of gas is needed to reach the next station. If the total gas is less than the total cost, the journey cannot be completed. Otherwise, we can find the starting point by making a single pass through the gas stations.

---

## Approach

1. **Check total gas vs. total cost**: First, sum the gas provided and the cost required at each station. If the total gas is less than the total cost, return -1 as it is impossible to complete the journey.
2. **Single pass to find the starting station**: Traverse the gas stations and track the current gas balance (`current_gas`). If at any point, `current_gas` becomes negative, it means we cannot start the journey from any station before the current one. Thus, reset the starting station to the next station and reset `current_gas` to 0. After one complete pass, return the starting station.

---

## Complexity

- **Time Complexity**: $$O(n)$$, where $$n$$ is the number of gas stations. We only make one pass through the gas stations.
- **Space Complexity**: $$O(1)$$, as we only use a few extra variables.

## Code (C++)

```cpp
/*************************************************
* Name:        canCompleteCircuit
* 
* Description: This function finds the starting gas station index
*              from which we can travel around the circuit once.
* 
* Arguments:   - vector<int>& gas: an array representing gas 
*                available at each station.
*              - vector<int>& cost: an array representing the 
*                cost to travel to the next station.
* 
* Returns:     - int: the index of the gas station to start from,
*                or -1 if it's not possible to complete the circuit.
**************************************************/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        int start = 0;
        int current_gas = 0;

        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
        }

        if (total_gas < total_cost) {
            return -1;
        }

        for (int i = 0; i < gas.size(); i++) {
            current_gas += gas[i] - cost[i];


            if (current_gas < 0) {
                start = i + 1;
                current_gas = 0;
            }
        }

        return start;
    }
};
```
