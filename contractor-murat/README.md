# Contractor Murat

Murat is one of the well known contractors. Now he has a new project and he needs your help. He has the map of the project area, which has dimensions $n \times n$. In this map every cell has $1\ m \times 1\ m$ dimensions and every cell contain a value $h_{r, c}$ meters which indicates the height of that part of the project area. Since he wants to build very resistant building he needs to level the ground. He is going to do that with pouring the concrete on the selected area for building until each cell has equal height with height of the initially highest cell. Can you calculate the necessary number of concrete in terms of $m^3$?

# Input Format

First line contains two space separated integers: $n$ and $q$. $q$ indicates the number of queries.

Next $n$ lines contain $n$ space separated integers. $h_{r, c}$ indicates the height of the corresponding cell.

Next $q$ lines contain $4$ space separated integers: $r_1$, $c_1$, $r_2$, $c_2$. The building area's upper left cell is $\left(r_1, c_1\right)$ and lower right cell is $\left(r_2, c_2\right)$.

# Output Format

Print the answer for the corresponding query.

# Constraints

- $1 \leq n \leq 10^2$
- $1 \leq q \leq 10^6$
- $1 \leq r_1 \leq r_2 \leq n$
- $1 \leq c_1 \leq c_2 \leq n$
- $1 \leq h_{r, c} \leq 10^6$

# Sample Input 1

```
3 3
1 2 3
4 5 6
7 8 9
1 1 2 2
1 1 3 3
2 2 2 3
```

# Sample Output 1

```
8
36
1
```

# Sample Explanation 1

- To level the ground in the $1^{st}$ query all the cells must have height as $5$. To do that we need $(5 - 1) + (5 - 2) + (5 - 4) + (5 - 5) = 8 m^3$ concrete.
- To level the ground in the $2^{nd}$ query all the cells must have height as $9$. To do that we need $(9 - 1) + (9 - 2) + (9 - 3) + (9 - 4) + (9 - 5) + (9 - 6) + (9 - 7) + (9 - 8) + (9 - 9) = 36 m^3$ concrete.
- To level the ground in the $3^{rd}$ query all the cells must have height as $6$. To do that we need $(6 - 5) + (6 - 6) = 1 m^3$ concrete.
