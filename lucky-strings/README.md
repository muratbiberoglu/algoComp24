# Lucky Strings

The lucky string is a non-empty string which contains only letters `l`, `u`, `c`, `k`, `y`.

You have the string $s$ of length $n$. On the $k$-th day you consider the substring $s[l_k..r_k]$. Let's denote it with $t_k$. Your task is to count how many unique lucky strings can be obtained from $t_k$ by deleting some (possibly none) of its characters. As this number can be quite large, print it modulo $10^9+7$.

# Input Format

The first line contains two integers $n$ and $m$: the length of the string $s$ and the number of days.

The second line contains the string $s$ of length $n$.

Each of the next $m$ lines contains two integers $l_k$ and $r_k$.

# Output Format

Print $m$ lines, each containing the number of unique lucky strings that can be obtained from the substring $s[l_k .. r_k]$ modulo $10^9+7$.

# Constraints

- $1 \le n, m \le 10^5$
- $1 \le l_k \le r_k \le n$
- the string $s$ contains only lowercase English letters.

# Sample Input 1

```
5 3
luuby
1 3
2 4
1 5
```

# Sample Output 1

```
5
2
11
```

# Sample Explanation 1

- $s[1 .. 3]$: `l`, `u`, `lu`, `uu`, `luu`.
- $s[2 .. 4]$: `u`, `uu`.
- $s[1 .. 5]$: `l`, `u`, `y`, `lu`, `ly`, `uu`, `uy`, `luu`, `luy`, `uuy`, `luuy`.
