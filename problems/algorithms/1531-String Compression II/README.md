# 1531 - String Compression II

## Analysis
My first attempt was viewing the problem as selecting $k$ characters to delete to minimize the length of the string after compression. This is equivalent to finding an element out of $\binom{n}{k}$ possibilities. 

The **brute-force** approach is equal to visiting all $\binom{n}{k}$ possibilities. It has a time complexity of $O(2^n/\sqrt{n})$ by taking $k=n/2$ and using the Stein's formula for factorial numbers $n!$. 

Because of the above connection to the binomial coefficients, it is natural to intuit more efficient approach using the computation of binomial coefficients as a source of motivation.

We know that binomial coefficients has a more efficient way than the brute-force approach based on the following recursive formula:
$$\binom{n}{k}=\binom{n-1}{k-1}+\binom{n-1}{k}$$
for $1\leq k\leq n-1$. This allows us to use **dynamic programming** plus **memoization** to reduce the time complexity to $O(n^2)$. 

This connection to the binomial coefficients and the fact that they can be efficiently computed within $O(n^2)$ complexity instead of $O(2^n/\sqrt{n})$ give us hope in solving the string compression problem efficiently. 

Similar to the underlying thinking process of calculating the binomial coefficients, we divide the string compression as follows.
1. Delete the last character, and follow the optimal deletion plan on the remaining characters
2. Or leave the last character, and put all deletion budget on the first $n-1$ characters

The first case is easy. If we use `dp[i][j]` to represent the minimal length obtained by compressing the first $i$ characters after deleting $j$ characters, then the first case yields `dp[n-1][k-1]` characters.

The most challenging part is the second case. If not deleting the last character, then the deletion plans on the first $n-1$ characters could affect the final length. This makes it difficult to reduce the second case using our `dp[i][j]` representation.

To address this issue, the key is to discover the fact that there exists **cutoff points** after which deletion within the first portion of the string does not affect the final length.

Consider the following string with $n=9$ characters.
$$aabbaabab$$
Suppose that we have a deletion budget of $k=2$. And suppose that we leave the last character $b$.

1. We can delete $k=2$ characters optimally from the first $n-1=8$ to yield `dp[n-1][k]` characters after compression. Plus the last $b$, we will have at most `dp[n-1][k]+1` characters. This provides a lower bound for all deletion plans that do not compress the last $b$.
2. We can also delete the last $a$, and compress the last 2 $b$'s into $b2$, and then delete $k-1=1$ characters optimally from the first $n-3=6$ characters optimally, yielding `dp[n-3][k-1]` characters after compression. Plus $b2$ at the end, we have at most `dp[n-3][k-1]+2` characters. This provides a lower bound for all deletion plans that do not further compress the last $b2$.

These two cases cover all the possible deletion plans.

In general, we will gradually consider compressing 1 $b$, 2 $b$'s, 3 $b$'s, until we cannot continue because of the deletion budget.