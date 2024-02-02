# Sıralama Platformu 1

Berke is involved in organizing a major sports event, and his task is to prepare platforms for the winners. When arranging the platforms, he must pay attention to the order and heights as follows:
- The $1st$ contestant is in the middle
- The $2nd$ contestant is to the left of the $1st$.
- After $2nd$, each contestant is placed adjacent to the contestant two positions before them, on the side opposite to the contestant immediately preceding them.
- Every contestant must have a shorter column height than all the contestants preceding them. For example height of the platform for 3nd contestant must be smaller than the height of the 1st and 2nd contestant's platforms

Berke has $n$ columns with different heights, ranging from $1$ to $n$ meters. How many different platforms can be obtained by selecting columns from among these columns?

The selected columns must be consecutive.

# Input Format

First line contains $n$, the number of columns.

The next line contains $n$ space separated integers: $c_{1}$, $c_{2}$, ..., $c_{n}$ are the heights of the columns.


# Output Format

Print the number of different platforms that satisfy the given conditions.

# Constraints

- $1 \leq n \leq 10^6$
- $1 \leq c_i \leq 10^6$

# Sample Input
```
4
1 4 5 2
```

# Sample Output
```
8
```

# Sample Explanation
```
The possible platforms:
1, 4, 5, 2, 1-4, 4-5, 4-5-2, 1-4-5-2
```