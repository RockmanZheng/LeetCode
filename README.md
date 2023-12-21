# LeetCode Cheat Sheet

## Tools

### Prefix Sum

- Use case: Compute $x[i+1]+\cdots+x[j]$ for different $i,j$.
- Useful in computing sum with repeated elements. 
- Usage: Precompute and store the summation $S[i]=x[0]+\cdots+x[i]$ for each $i$. Use $S[j]-S[i]$ to compute the target sum $x[i+1]+\cdots+x[j]$.
- Pro: it can reduce computational complexity by an order, e.g., from $O(N^2)$ to $O(N)$.

Examples: 
- [2281](https://leetcode.com/problems/sum-of-total-strength-of-wizards/)

### Dynamic Programming

- Use case: Problems that can be decomposed into subproblems
- Usage: 
  - Determine the value function $V_t$. 
  - Determine the initial states that has known values.
  - Determine the Bellman equation of $V_t$.
  - Calculate the terminal value $V_T$ according to the Bellman equation and return the answer.
- Pro: it can reduce computational complexity by an exponential order, e.g., from $O(2^N)$ TO $O(N)$.
- Con: It often introduces additional space complexity to store the intermediate values.

Examples:
- [935](https://leetcode.com/problems/knight-dialer/description/)

### Hashmap

### Heap

### Stack

### Monotonic Stack

### Queue

### Two Pointers

### Breadth First Search

### Depth First Search

### Topological Sort




