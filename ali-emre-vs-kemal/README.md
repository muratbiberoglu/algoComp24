# Ali Emre vs Kemal

One day Ali Emre and Kemal got bored and they designed a new game with chess board. The game has several rules:
- Size of the chess board is $n \times n$.
- There are pawns that can not move and only serve as walls.
- There are one or more rooks and bishops on the board. There is also one knight.
- The knight's aim is to reach the target cell without being caught by any rooks or bishops.
- There can be more than one piece in any cell that does not include a pawn at any time in the game.

Ali Emre controls knight and Kemal controls rooks & bishops. They made their moves simultaneously. In each turn Ali Emre can move only his knight and Kemal can move only one of his rooks & bishops. Since Ali Emre and Kemal are very close friends and Kemal is a very good chess player, he knows all the moves of the Ali Emre beforehand and act accordingly.

Is there any way that Ali Emre's knight can reach the target cell without being caught by bishops or rooks of Kemal?

## Input Format

The first line contains one integer $t$ which is the number of test cases.

For each test case, the first line contains three integers $n$, $r_{target}$, $c_{target}$ which indicates size of the chess board, target cells row number and target cells column number, respectively.

The next n lines contain one string which has length $n$. The characters _, P, B, R and K represent an empty cell, pawn, bishop, rook and knight, respectively.

## Output Format

For each test case, print `YES` if the knight can reach the target cell without being caught otherwise print `NO`.

## Constraints

- $1 \leq t \leq 5$
- $1 \leq n \leq 500$
- $1 \leq r_{target}, c_{target} \leq n$

## Sample Input 1

```
4
6 2 2
______
__P___
_PPK__
___B__
______
_R____
6 2 2
______
__P__K
_PP___
___B__
______
_R____
6 2 2
______
__P___
_PP___
___BK_
______
_R____
6 3 4
_B____
__R___
__P___
______
__K___
______
```

## Sample Output 1

```
YES
YES
NO
NO
```
