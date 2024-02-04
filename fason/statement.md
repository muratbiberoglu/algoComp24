# FASON

## Problem Story

One day, Fatih was working on implementing encrypted messaging systems for the bank hosts. While doing so, he came up with an idea. He called it FASON (Fatih String Object Notation).

FASON is like JSON, but simpler. In a FASON file, you have a tree structure containing classes, subclasses, variables under those classes, and so on. In FASON trees, leaves are the values of variables and the parent nodes are the variable or class names.

So, using the knowledge given below, can you help Fatih to implement a FASON interpreter? Some queries will be coming, asking for certain values and the FASON interpreter must return correct values or an error message.


## FASON Structure Explanation

* In a FASON file, there is only one tree.

* These messages are not random characters, of course, the messages are structured such that the tree structure can be drawn.

* FASON messages are the preorder traversal of the given tree structure(s) and each node starts and ends with a special character, similar to the logic of parentheses.

* FASON strings contain only small ASCII letters (a-z) and numbers starting from 0 to 9 for naming variables and objects, also for their values. In addition, ``\`` character is used for starting a node, and ``/`` is used for ending a node. 

* In FASON queries, ``.`` is used for reaching the sub-elements.

## Example

### FASON String

For example, we have this message as a FASON String: 

``\cl_1\scl_1\var_2\val_2///\scl_2\var_3\val_3//var_4\val_4///\var_1\val_1///``

### FASON Tree

This FASON string tree structure looks like this:

```
cl_1
..scl_1
....var_2
......val_2
..scl_2
....var_3
......val_3
....var_4
......val_4
..var_1
....val_1

```

### Fason Queries

From the example above, there are some query results:

```
cl_1 -> -1
cl_1.scl_1.var_2 -> val_2
cl_2.scl_2 -> -1
```

## Input Format

* The first line contains $N$ the number of characters in the FASON string, and $Q$ the number of queries.
* The next line contains the $N$-character-long FASON String.
* The next $Q$ lines contain the queries.

## Output Format

$Q$ lines of query answers. If the query is correct, print the value, otherwise ``-1`` must be printed.

## Constraints

* $N$, the number of characters given in the FASON string would not exceed $2 \times 10^5$.

* Number of queries would not exceed $10^3$.

* Total number of characters, with $N$-character-long FASON string and $Q$ queries would not exceed $10^6$.

* Depth of FASON tree would not exceed $10^2$.

* Note that coming values are strings, even though they might seem like numerical values.

## Question Example

### Input

```
25 2
\abc\def\asd//\ghi\zxc///
abc.def
abc.klm
```

### Output

```
asd
-1
```

## Special Hints & Notes

For escaping back-slash, you can use ``\\``.
