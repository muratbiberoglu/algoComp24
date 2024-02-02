# Travel of Moody Friend

Our dear friend X does not always walk at the same speed when walking from one place to another. The speed of our friend is determined by his/her current mood. More formally if current mood of the X is $m$ and the time that takes traveling the road normally is $t$, X travels this road with $m \times t$ time.

Since you are one of the friends of X you know moods of his/her. So can you find the minimum time that takes X to travel from place $1$ to place $n$?

# Input Format

First line contains three space separated integers $n$, $m$, $k$; number of places on given map, number of roads on given map, number of moods of X.

Next line contains $k$ space separated integers which are moods of the X. $m_i$ indicates the mood of the X while traveling road $i$. Moods are cyclic, if X travels $a^{th}$ road on path the mood will be $m_b$ where $b = 1 + \left(a \mod m\right)$.

Next $m$ line contains three space separated integers: $u$, $v$, $w$. It indicates there is a road between $u$ and $v$ with time cost $w$.

# Output Format

One single number which is the minimum time that traveling cost from place 1 to place n.

# Constraints

- $1 \leq n \leq 50000$
- $1 \leq m \leq 100000$
- $1 \leq k \leq 5$
- $1 \leq m_i \leq 5$
- $1 \leq u, v \leq n$
- $1 \leq w \leq 100$

# Sample Input 1
```
4 4 2
5 1
1 2 1
1 3 2
2 4 3
3 4 1
```

# Sample Output 1
```
8
```

# Sample Explanation 1

<!-- <img src="./images/graph-1.png" style="width: 15%;"> -->

The path $1 \Rightarrow 2 \Rightarrow 4$ gives shortest time with $5 \times 1 + 1 \times 3 = 8$.

# Sample Input 2
```
5 5 5
5 1 2 5 1
2 4 1
1 4 3
3 4 9
5 4 10
2 5 4
```

# Sample Output 2
```
24
```

# Sample Explanation 2

<!-- <img src="./images/graph-2.png" style="width: 15%;"> -->

The path $1 \Rightarrow 4 \Rightarrow 2 \Rightarrow 5$ gives shortest time with $5 \times 3 + 1 \times 1 + 2 \times 4 = 24$.


# Sample Input 3
```
5 5 1
1
2 1 2
4 2 9
3 4 9
5 3 5
5 2 6
```

# Sample Output 3
```
8
```

# Sample Explanation 3

<!-- <img src="./images/graph-3.png" style="width: 15%;"> -->

The path $1 \Rightarrow 2 \Rightarrow 5$ gives shortest time with $1 \times 2 + 1 \times 6 = 8$.

# Sample Input 4

```
5 5 2
8 2
1 2 1
1 3 7
2 3 4
3 4 5
4 5 2
```

# Sample Output 4

```
60
```

# Sample Explanation 4

The path $1 \Rightarrow 2 \Rightarrow 3 \Rightarrow 4 \Rightarrow 5$ gives shortest time with $8 \times 1 + 2 \times 4 + 8 \times 5 + 2 \times 2 = 60$.

