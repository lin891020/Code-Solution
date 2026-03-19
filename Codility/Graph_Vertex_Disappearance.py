def solution(N, A, B):
    degree = [0] * N
    neighbors = [[] for _ in range(N)]
    
    for k in range(len(A)):
        degree[A[k]] += 1
        degree[B[k]] += 1
        neighbors[A[k]].append(B[k])
        neighbors[B[k]].append(A[k])
    
    seconds = 0
    while True:
        # Step 1: find who disappears this second
        to_remove = []
        for v in range(N):
            if degree[v] <= 1 and degree[v] != -1:
                to_remove.append(v)
        
        # Step 2: if nobody disappears, stop!
        if len(to_remove) == 0:
            break
        
        # Step 3: update neighbors and mark as gone
        for v in to_remove:
            for neighbor in neighbors[v]:
                degree[neighbor] -= 1
            degree[v] = -1
        
        # Step 4: count the second
        seconds += 1
    
    return seconds

print(solution(7, [0,1,2,1,4,4], [1,2,0,4,5,6])) 