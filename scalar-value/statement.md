# Scalar Value

## Problem Story

One day, Bilge, Fatih and Murat was talking about NumPy and AI while having a dinner. They wanted a feature to predict the resulting matrix dimensions after a complex matrix multiplication operation. To be exact, they wanted to learn whether given matrix multiplication will yield a scalar value. Can you help them to implement such a tool?

## About Matrix Multiplication

Matrixes are a type of reptesentation of data. They are like 2D arrays. They consist of number of rows and number of colums. For example, a matrix with dimensions (3, 5) has 3 rows and 5 columns.

Two matrixes can be multiplied if the first matrix has the same number of columns as the second matrix number of rows. For example, a matrix with dimensions (3, 5) can be multiplied with a matrix with dimensions (5, 4). The resulting matrix would be in the dimensions of (3, 4).

Since the first matrix number of rows must match second matrix number of columns, the order of multiplication is important. A matrix with (3, 5) must be on the left hand side of (5, 4) matrix while multiplying. So, (3, 5) x (5, 4) = (3, 4)

Matrix multiplication can be chained, a result of matrix multiplication can be multiplied with another result of matrix multiplication, if their dimensions can be matched as the rules above suggest.

A scalar value is obtained when the end result has the dimensions of (1, 1)

## Question

Given N matrices in each T test case, print "1" if it is possible to obtain (1, 1) matrix by multiplying all the matrices exactly once.

If it is impossible, then print "-1".

## Input Format

* The first line will contaion the number T, number of test cases.
* For each test case, there will be a line with number N, number of matrices.
* Then following in each test case, there will be N number of limrs, containing row_i and column_i, number of rows and columns of matrix i in the test case.

## Output Format

* T number of lines containing "1" if given test case yields a scalar value or "-1" if it doesn't.

## Constraints

Total number of matrices in the entire test cases doesn't pass 10^6.

## Example

### Input

```
3
3
4 1
1 3
3 4
2
2 3
3 2
3
1 3
2 4
3 1
```

### Output

```
1
-1
-1
```

### Explaination

* In the first test case, the matrices are all multipliable and the result is a (1, 1) dimension matrix, a scalar value. Multiplication order is: (1, 3) x (3, 4) x (4, 1)
* In the second test case, even though it is possible to use all the matrices for multiplication, the result would be a (2, 2) dimension matrix.
* In the third test case, it is impossible to multiply all the matrices together together, (2, 4) is incompatible with the remaining matrices.
