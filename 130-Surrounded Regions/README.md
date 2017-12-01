# Problem
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
```
X X X X
X O O X
X X O X
X O X X
```
After running your function, the board should be:
```
X X X X
X X X X
X X X X
X O X X
```

## Idea
Instead of directly modifying those 'O' that are surrounded by 'X', we can first find 'O' that are not going to be modified. Why is that?
Simply because finding those not surrounded 'O's are way easier. They are connected to the boundaries of the board! On the contrary, depicting
the property that those surrounded 'O's are, to me, more complex and subtle.

Hence, the idea is the following:
* starting from the boundaries of the board, find all 'O's that are connected to the boundaries and mark them in another self-defined char,
say '*'
* go through the board, if we find 'O', we then change it to 'X'; if we find '*', we then change it back to 'O'

