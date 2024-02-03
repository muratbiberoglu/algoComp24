Emre and his friends recently embarked on a holiday, during which they incurred various expenses. To keep track of their spending, they diligently collected all the receipts. While at restaurants, one person graciously covered the entire bill, with the understanding that others in the group would reimburse their respective shares upon their return from the holiday.

The group consists of ~n~ individuals, and they visited ~m~ different places.

# Input Format

The first line specifies ~n~, the number of people in their group.

The second line specifies ~m~, the number of places they visited.

The next m lines each contain two integers, ~i~ and ~k~. Here, ~i~ represents the person who paid the receipt, and ~k~ represents the amount of the respective receipt.

# Output Format

For each person in the group, output a line with three variables: ~u~, ~v~, and ~y~.

~u~ represents the person's identification number.

~v~ represents either the amount they owe (debt) or the money they will receive.

~y~ is a string indicating whether the person is a "debtor" or a "payee".

# Constraints

- ~1 \leq n \leq 10^7~
- ~1 \leq m \leq 10^7~
- ~1 \leq i \leq n~
- ~1 \leq k \leq 2147483647~
- ~1 \leq u \leq n~
- ~1 \leq v \leq 2147483647~

# Sample Input 1
```
5
6
1 100
3 300
2 250
4 350
5 400
1 100

```

# Sample Output 1
```
1 100 debtor
2 0
3 50 debtor
4 50 payee
5 100 payee

```