# Graph_Vertex_Disappearance

## Intuition
The problem is about simulating a **graph pruning process**. Each second, vertices with at most one edge disappear, causing a chain reaction. This is similar to **topological peeling** — like peeling layers of an onion from the outside in. The key insight is that when a vertex disappears, its neighbors' degrees decrease, potentially triggering more removals next second.

---

## Approach
1. **Build degree array**: Count edges for each vertex using arrays A and B.
2. **Build adjacency list**: Store neighbors of each vertex for efficient lookup.
3. **Simulate each second**:
   - Find all alive vertices with degree ≤ 1
   - If none found → stop
   - Remove them, reduce neighbors' degrees
   - Increment second counter
4. **Return** total seconds elapsed.

---

## Complexity
- **Time Complexity**: $$O(N + M)$$
  - Each vertex and edge is processed at most once.
- **Space Complexity**: $$O(N + M)$$
  - Storing degree array and adjacency list.

---

## Code (Python3)
```python
def solution(N, A, B):
    # Step 1: Initialize degree array and adjacency list
    degree = [0] * N
    neighbors = [[] for _ in range(N)]
    
    # Step 2: Build degree and neighbors
    for k in range(len(A)):
        degree[A[k]] += 1
        degree[B[k]] += 1
        neighbors[A[k]].append(B[k])
        neighbors[B[k]].append(A[k])
    
    # Step 3: Simulate each second
    seconds = 0
    while True:
        # Find vertices that disappear this second
        to_remove = []
        for v in range(N):
            if 0 <= degree[v] <= 1:  # alive and degree <= 1
                to_remove.append(v)
        
        # Nobody disappears → stop
        if len(to_remove) == 0:
            break
        
        # Remove vertices and update neighbors
        for v in to_remove:
            for neighbor in neighbors[v]:
                if degree[neighbor] != -1:  # only update alive neighbors
                    degree[neighbor] -= 1
            degree[v] = -1  # mark as gone
        
        seconds += 1
    
    return seconds
```