# Zero Split

You have a sequence of $N$ zeros. You have to replace $K$ of them with positive integers $A_1, A_2, ..., A_K$ in such way that each positive integer $A_j$ is surrounded by at least $A_j$ consecutive zeroes from the left and with at least $A_j$ consecutive zeros from the right. These zeros have to appear just before and just after the number $A_j$ itself: $..., 0, 0, ..., 0, A_j, 0, 0, ..., 0, ...$.

You have to find the number of distinct sequences you can get by replacing exactly $K$ zeros and print it modulo $1234567891$.

# Input Format

The first line contains two integers $N$ and $K$ separated by a single space.

The following line contains $N$ integers $A_1, A_2, ..., A_K$ separated by single spaces.

# Output Format

The number of sequences modulo $1234567891$.

# Constraints

- $1 \le N \le 1000$
- $1 \le K \le 100$
- $1 \le A_j \le 100$

# Sample Input 1

```
10 3
1 2 1
```

# Sample Output 1

```
12
```

# Sample Explanation 1

In the sample above, you can get the following sequences:

- `0 1 0 1 0 0 2 0 0 0`
- `0 1 0 1 0 0 0 2 0 0`
- `0 1 0 0 1 0 0 2 0 0`
- `0 0 1 0 1 0 0 2 0 0`
- `0 1 0 0 2 0 0 1 0 0`
- `0 1 0 0 2 0 0 0 1 0`
- `0 1 0 0 0 2 0 0 1 0`
- `0 0 1 0 0 2 0 0 1 0`
- `0 0 2 0 0 1 0 1 0 0`
- `0 0 2 0 0 1 0 0 1 0`
- `0 0 2 0 0 0 1 0 1 0`
- `0 0 0 2 0 0 1 0 1 0`
