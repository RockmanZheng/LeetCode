# Introduction
<!-- Describe your first thoughts on how to solve this problem. -->
Many existing posts on LeetCode only explain HOW the algorithms work without truly explaining WHY they work. In this post, I will try to explain both parts of the algorithm. And I believe understanding the proof is as important as knowing how to code when it comes to solving new problems.

A good subarray is defined as a subarray that includes `nums[k]`. Let `n` be the size of `nums`. To find the optimal good subarray with the maximum score, we just need to check all windows containing `nums[k]`, which can be traversed using a two-pointer approach. However, the challenge of this brute-force approach is that the time complexity is at least $O(n^2)$ because there are $O(n/2)$ windows of length $O(n/2)$ that contains `nums[k]`. 

# Approach
<!-- Describe your approach to solving the problem. -->
To resolve this issue, we use a greedy approach. Starting with a left pointer `l` and a right pointer `r` both at `k`, at each iteration we move either `l` to the left by one or `r` to the right by one. To determine which pointer to move, we simply pick the one that will yield more potential improvement to the score. That is, if `nums[l-1]>nums[r+1]`, then we set `l=l-1`, otherwise set `r=r+1`. Meanwhile, we maintain two quantities: `min_val` which captures the minimal value of the good subarray `nums[l:r]` and `max_score` which keeps track of the currently achievable maximum score. We continue the loop until `l==0` and `r==n-1` and return `max_score` as the result.

# Code
```c++
static const int fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();// to speed up I/O

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int l=k,r=k;
        int min_val = nums[k], max_score=nums[k];
        bool flag=true;
        while(flag){
            if(l>0 && r<n-1){
                if(nums[l-1]>nums[r+1]) l--;
                else r++;
            }
            else if(l==0 && r<n-1) r++;
            else if(l>0 && r==n-1) l--;
            else flag=false;
            min_val = min(nums[l],min(nums[r],min_val));
            max_score = max(max_score,min_val*(r-l+1));
        }
        return res;
    }
};
```

# Proof
There has been a lot of confusions in the LeetCode community about why the above greedy approach works because it clearly does not visit all possible windows that contain `nums[k]`. The key to its correctness is that the window maintained by the algorithm is always optimal among windows of the same length in a sense to be clarified below.

In the following, we shall not only prove the correctness of the above greedy algorithm, but also actually show how such algorithm is come up in the first place.

To simplify the notations, let $a[i]$ be the array `nums[i]`. To investigate all subarrays, we denote

$m(i,j)=\min\{a[i],a[i+1],\ldots,a[j]\}$

and

$S(i,j)=m(i,j)(j-i+1)$

as the minimum value of the subarray from index $i$ to index $j$ and the corresponding score. 

The key is the following. For each integer $t=1,2,\ldots,n$, define

$S_t=\max\{S(i,j):i\leq k\leq j,j-i+1\leq t\}$

as the maximum score achievable among all good subarrays with lengths no greater than $t$. The object $S_t$ corresponds to the `max_score` in the above greedy algorithm at iteration $t$. In particular, $S_n$ is the result, the maximum score achievable among all good subarrays of $a$.

Based on this definition, we have the following recursive relation:

$S_t=\max\{S_{t-1},\bar S_t\},$

where

$\bar S_t=\max\{S(i,j):i\leq k\leq j,j-i+1=t\}$

is the maximum score achievable among all good subarrays with lengths equal to $t$. And this recursion corresponds to the updating rule for `max_score` in the above greedy algorithm.

By definition, we have

$\bar S_t= m_t(t+1),$

where

$m_t=\max\{m(i,j):i\leq k\leq j,j-i+1=t\}$

is the maximum minimum achievable among all good subarrays with lengths equal to $t$. The obejct $m_t$ corresponds to the `min_val` in the above greedy algorithm at iteration $t$. 

So the problem boils down to find $m_t$ recursively. 

We shall introduce more notations to illustrate our ideas. Let $l_t$ and $r_t$ be the left and the right endpoints of the good subarray that attains $m_t$, i.e., $m(l_t,r_t)=m_t$, $l_t\leq k\leq r_t$, and $r_t-l_t+1=t$. They corresponds to the two pointers `l` and `r` at iteration $t$ in the above greedy algorithm.

We let $a[i\ldots j]$ be the subarray of $a$ from index $i$ to index $j$ (inclusive). We say that a subarray $a[i\ldots j]$ is **dominated** by another subarray $a[i'\ldots j']$ if $m(i,j)\leq m(i',j')$. 

Note that each good subarray of length $t$ is dominated by all of its good subarrays of length $t-1$. Furthermore, all good subarrays of length $t-1$ are dominated by $a[l_{t-1}\ldots r_{t-1}]$. Finally, each good subarray of length $t-1$ must satisfy one of the following conditions:

- it contains $a[l_t-1]$;
- it contains $a[r_t+1]$;
- it is $a[l_t\ldots r_t]$. 

These observations together imply that all good subarrays of length $t$ is dominated by either $a[l_{t-1}\ldots (r_{t-1}+1)]$ or by $a[(l_{t-1}-1)\ldots r_{t-1}]$. The remaining job is just to pick the one with the highest minimum value so as to guarantee the resulting good subarray of length $t$ dominates all other good subarrays of the same length. This explains the updating rule of the `min_val` and the two pointers `l` and `r` in the above greedy algorithm.


# Complexity
- Time complexity: $O(n)$
This is because the distance between the two pointers `l` and `r` is increased by 1 at each iteration, so the loop ends after `n` iterations.
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $O(1)$
This is because we only use two integer pointers in the algorithm.
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

