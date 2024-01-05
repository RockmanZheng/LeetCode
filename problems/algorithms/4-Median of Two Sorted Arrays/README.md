# 4 - Median of Two Sorted Array

## Analysis

Let $N$ be the total number of elements. Considering the edge cases with repeated elements and both cases with odd and even $N$, the equivalent definitions of median are
1. An element $x$ is the median if the number of elements that are less than or equal to (on the left of) $x$ equals to the number of elements that are larger than or equal to (on the right of) $x$
2. An element $x$ is the median if at least $\lfloor (N+1)/2\rfloor$ elements are on the left of $x$ and at least $\lfloor (N+1)/2\rfloor$ elements are on the right of $x$


For example, when the total number of element is odd
$$1,2,3,3,3,4,5$$
Or when then total number of element is even
$$1,2,3,3,4,5$$
In both cases, $3$ is the median and it satisfies the definitions. In the odd case, there are $6$ elements on the left and on the right of $3$; while in the even case, there are $4$ elements on the left and on the right of $3$.



The key to this problem is to define
- $l_i$: the biggest element in array $a_i$ that is on the left of the median; if such element does not exist, we set $l_i=-\infty$
- $r_i$: the smallest number in array $a_i$ that is on the right of the median; if such element does not exist, we set $r_i=+\infty$ 

The importance of these quantities is reflected by the following facts.
1. Gvien the median, $l_i,r_i$ can be found in $a_i$ in $O(\log(N))$ time using the binary search algorithm
2. Given $l_i,r_i$ for all $i$, the median can be calculated:
   1. If $N$ is an odd number, then $\max_il_i$ is the median
   2. If $N$ is an even number, then the median is equal to the average of $\max_il_i$ and $\min_ir_i$

Note that both facts hold in the edge cases with repeated elements.

Based on these observation, we can come up with the following iterative procedure.
1. Start with $l_i=-\infty$ and $r_i=+\infty$
2. Select an element $x\in [l_i,r_i]$ from $a_i$ as a guess for the median
3. Use binary search to determine how many elements are on the left of $x$
4. If the number of elements on the left of $x$ is less than the number of elements on its right, then the median must be on the right of $x$, and hence $r_i$ is also on the right of $x$. Thus, we can update $r_i= x$
5. If the number of elements on the left of $x$ is larger than the number of elements on its right, then the median must be on the left of $x$, and hence $l_i$ is also on the left of $x$. Thus, we can update $l_i=x$
6. Based on the updated values of $l_i,r_i$, the median must lie in the intervals $[l_i,r_i]$. Bisect $[l_i,r_i]$ to update the guess of median and go to step 3.
7. Iterate the algorithm until convergence.

