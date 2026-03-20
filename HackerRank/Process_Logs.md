# Process Logs

You are given application log entries in the format: `"user_id timestamp action"`

**Where:**
- `user_id` and `timestamp` are numeric strings
- `action` is either `"sign-in"` or `"sign-out"`

You are also given an integer `maxSpan`. Your task is to find all users who:
- Have both a sign-in and a sign-out
- Signed out within `maxSpan` seconds of signing in

**Return:**
- A list of user IDs (as strings) that meet the condition
- Sorted in ascending numerical order

**Notes:**
- Log entries are unordered
- Each user signs in at most once
- Users who do not sign out are ignored

**Example:**
```
logs = ["30 99 sign-in", "30 105 sign-out", "12 100 sign-in", 
        "20 80 sign-in", "12 120 sign-out", "20 101 sign-out", "21 110 sign-in"]
maxSpan = 20
Output: ["12", "30"]
```

**Constraints:**
- 1 ≤ n ≤ 10⁵
- 1 ≤ maxSpan ≤ 10⁹
- 0 < timestamp ≤ 10⁹
- Each user signs in for only 1 session

---

# Solution

## Intuition
The problem requires pairing up sign-in and sign-out log entries for each user, then checking if the time delta is within `maxSpan`. Since logs are unordered, we need a hash map to store timestamps as we encounter them.

---

## Approach
1. **Hash Map**: Use a dictionary to store each user's sign-in and sign-out timestamps as we iterate through the logs.
2. **Check Both Keys**: Only calculate the delta when both `"sign-in"` and `"sign-out"` exist for a user, handling the unordered nature of logs.
3. **Filter & Sort**: Append qualifying users and sort numerically before returning.

---

## Complexity
- **Time Complexity**: $$O(n \log n)$$
  - Iterating through logs is $$O(n)$$, sorting is $$O(n \log n)$$
- **Space Complexity**: $$O(n)$$
  - Dictionary stores at most `n` users

---

## Code (Python3)
```python
def processLogs(logs, maxSpan):
    d = {}
    result = []
    
    for entry in logs:
        user_id, timestamp, action = entry.split()
        
        if user_id not in d:
            d[user_id] = {}
        d[user_id][action] = int(timestamp)
        
        if "sign-in" in d[user_id] and "sign-out" in d[user_id]:
            delta = d[user_id]["sign-out"] - d[user_id]["sign-in"]
            if delta <= maxSpan:
                result.append(user_id)
    
    result.sort(key=lambda x: int(x))
    return result
```

Great job working through this step by step! 💪 Ready for the next problem? 🚀