# 1531 - String Compression II

## Analysis
My first attempt was viewing the problem as selecting $k$ characters to delete to minimize the length of the string after compression. This is equivalent to finding an element out of $\binom{n}{k}$ possibilities. 

The **brute-force** approach is equal to visiting all $\binom{n}{k}$ possibilities. It has a time complexity of $O(2^n/\sqrt{n})$ by taking $k=n/2$ and using the Stein's formula for factorial numbers $n!$. 

Because of the above connection to the binomial coefficients, it is natural to intuit more efficient approach using the computation of binomial coefficients as a source of motivation.

We know that binomial coefficients has a more efficient way than the brute-force approach based on the following recursive formula:
$$\binom{n}{k}=\binom{n-1}{k-1}+\binom{n-1}{k}$$
for $1\leq k\leq n-1$. This allows us to use **dynamic programming** plus **memoization** to reduce the time complexity to $O(n^2)$. 

This connection to the binomial coefficients and the fact that they can be efficiently computed within $O(n^2)$ complexity instead of $O(2^n/\sqrt{n})$ give us hope in solving the string compression problem efficiently. 



