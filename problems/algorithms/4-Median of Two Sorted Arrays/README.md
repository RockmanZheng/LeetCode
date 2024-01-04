# 4 - Median of Two Sorted Array

## Analysis

Let $N$ be the total number of elements.

The key to this problem is to define
- $l_i$: the biggest element in array $a_i$ that is on the left of the median; if such element does not exist, $l_i=-\infty$
- $r_i$: the smallest number in array $a_i$ that is on the right of the median

The importance of these quantities is reflected by the following facts.
1. Gvien the median, $l_i,r_i$ can be found in $a_i$ in $O(\log(N))$ time using the binary search algorithm
2. Given $l_i,r_i$ for all $i$, the median can be calculated:
   1. If $N$ is an odd number, then we must have $l_i=r_i$ for some $i$, then $l_i=r_i$ is the median
   2. If $N$ is an even number, then the median is equal to the average of $\max_il_i$ and $\min_ir_i$

Based on these observation, we can come up with the following iterative procedure.
1. Start with $l_i=-\infty$ and $r_i=+\infty$
2. Select an element $x\in [l_i,r_i]$ as a guess for the median
3. Use binary search to determine how many elements are on the left of $x$
4. If there are more than $N/2$ elements on the left of $x$, then the median must be on the left of $x$, and hence $l_i$ is also on the left of $x$. Thus, we can update $l_i= x$
5. If there are less than $N/2$ elements on the left of $x$, then the median must be on the right of $x$, and hence $r_i$ is also on the right of $x$. Thus, we can update $r_i=x$
6. Based on the updated values of $l_i,r_i$, the median must on the right of $l_i$ while at the same time on the left of $r_i$. Bisect $[l_i,r_i]$ to update the guess of median and go to step 3.
7. Iterate the algorithm until convergence.

## Edge Case Analysis
The important edge cases are when the elements next to the median are equal to the median itself. For example, when the total number of element is odd
$$1,2,3,3,3,4,5$$
Or when then total number of element is even
$$1,2,3,3,4,5$$
In these cases, the previous iterative algorithm may fail to converge.