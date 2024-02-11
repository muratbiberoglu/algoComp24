# Connect the City

Sıla is the new major of the city and she wants to start with solving transportation problem of the city. In this city there are one way roads between neighbourhoods. Neighborhoods that can reach each other form a district. Since these roads are somehow designed badly, the number of districts is unnecessarily large. Sıla wants to solve this transportation problem by reducing the number of districts. To do that she calls her friend Sude, who is very intelligent person, and ask her help. Because Sude loves her friend Sıla, she accepts the challange and finds a solution quickly. Sude proposes that changing the direction of some of the roads and calculates the possible minimum number of districts. Sıla loves this solution because number of districts can be reduced faster and cheaper than building new roads!

Can you find the possible minimum number of districts as fast as Sude?

# Input Format

First line contains two space separated integers $n$, $m$. Where $n$ is the number of neighbourhoods and $m$ is the number of roads.

Next $m$ lines contain two space separated integers $u$, $v$. There is a road from neighbourhood $u$ to neighbourhood $v$.

# Output Format

Print one integer which is the possible minimum number of districts.

# Constraints

- $1 \leq n \leq 10^5$
- $1 \leq m \leq 2 \times 10^5$
- $1 \leq u, v \leq n$

# Sample Input 1

```
6 7
1 2
2 3
1 3
4 5
5 6
6 4
1 4
```

# Sample Output 1

```
2
```

# Sample Explanation 1

Initially there are $4$ distrincts which are $\\{1\\}, \\{2\\}, \\{3\\}, \\{4, 5, 6\\}$. Sude can change the direction of the road $1 \rightarrow 3$ and can reduce the number of districts to $2$.
