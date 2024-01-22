# Scalar Value

## Problem Story

One day, Bilge, Fatih and Murat was talking about NumPy and AI while having a dinner. They wanted a feature to predict the resulting matrix dimensions after a complex matrix multiplication operation. To be exact, they wanted to learn whether given matrix multiplication will yield a scalar value. Can you help them to implement such a tool?

## About Matrix Multiplication

Matrixes are a type of reptesentation of data. They are like 2D arrays. They consist of number of rows and number of colums. For example, a matrix with dimensions 3 x 5 has 3 rows and 5 columns.

Two matrixes can be multiplied if the first matrix has the same number of columns as the second matrix number of rows. For example, a matrix with dimension 3 x 5 can be multiplied with a matrix with dimensions 5 x 4. The resulting matrix would be in the dimensions of 3 x 4.

Since the first matrix number of rows must match second matrix number of columns, the order of multiplication is important. A matrix with 3 x 5 must be on the left hand side of 5 x 4 matrix while multiplying. So, (3,5) x (5,4) = (3,4)

