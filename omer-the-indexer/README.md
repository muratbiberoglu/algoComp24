# Ömer the Indexer

Ömer has a magnificent memory. He can remember all of the funny videos on the internet without much effort. He can achieve that with organizing the properties of the videos in his memory somehow.

You are given $n$ number of videos, $p$ number of properties for each video and $q$ queries. Given queries has two types, $1$ for update $2$ for reading. Can you answer these queries as fast as Ömer? You have a computer also :)

# Input Format

First line contains three space separated integers: $n$, $p$, $q$

Next $n$ line contains $p$ space separated integers: $p_{1}$, $p_{2}$, ..., $p_{n}$ are the properties of the related video. Please note that all properties are distinct for each property type.

Next $q$ line contains space separeted integers. First integer $q_t$ indicates type of the query, $1$ for updating, $2$ for reading.

Type $1$ query: $q_t$ $a$ $b$ $c$ $d$ indicates that add $d$ to $c^{th}$ property of the video that is $b^{th}$ smallest according to property $a$. It is guaranteed that all the values are distinct within each property after the update operation.

Type $2$ query: $q_t$ $a$ $b$ $c$ indicates that printing value of the property $c$ of the video that is $b^{th}$ smallest according to property $a$.

# Output Format

For each query type two print the value.

# Constraints

- $1 \leq n, q \leq 10^5$
- $1 \leq p \leq 5$
- $1 \leq p_i \leq 10^6$
- $1 \leq q_t \leq 2$
- $1 \leq a, c \leq p$
- $1 \leq b \leq n$
- $ -10^6 \lt d \lt 10^6$
- At any time any property of any video is in range $[1, 10^6]$

# Sample Input

```
5 2 6
1 2
3 4
5 5
4 3
2 1
2 1 3 2
2 1 3 1
1 2 1 1 4
2 1 5 2
1 1 5 2 100
2 2 2 1
```

# Sample Output

```
4
3
1
4
```

# Sample Explanation
