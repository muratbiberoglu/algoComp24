# Character Creation

One day, Berke have decided to design a new game, AlgoComp Scrolls. In this game, every character has two attributes, attack and defense points. A character can slay another character if its attack point is greater or equal to other character's defense point and defense point is greater or equal to other character's attack point.

**For example:**
Let's say a player has 10 attack points and 5 defense points.

- He can slay an enemy with 5 attack and 10 defense points.
- He can't slay an enemy with 5 attack and 11 defense points.
- He can't slay an enemy with 6 attack and 10 defense points.

Berke has created a character with $A$ attack points and $D$ defense points. Then he completed some quests in the game and he is able to invest $P$ attribute points on his attack and defense points.

For example, if his character has 10 attack and 2 defense points and has 11 attribute points, he can create a character with 12 attack and 11 defense points, or a character with 21 attack and 2 defense points, depending on his preference.

Berke has banked his $P$ attribute points and he will enter the PVP arena, and he wants to slay as much enemies as he can. He can see the enemies details beforehand, and he can calculate the best combination of attack and defense attributes before starting PVP combat. When he spends his $P$ points, the changes are permanent, he can't roll back his points.

Therefore, Berke must be very wise about investing his $P$ points. Since he can pick any enemy he wants to fight with, he can calculate the best possible combination of attack and defense points beforehand and start combat. But he needs to decide fast! Can you help him to implement such an algorithm to make him do his best in the PVP arena, by slaying the most enemies possible?

## Input Format:

- First line contains $N$, number of enemies, $A$, Berke's initial attack attribute, $D$, his initial defense attribute and $P$, his banked points he can invest in his attributes.
- Next $N$ lines are $a_i$ and $b_i$, attack and defense attributes of enemies.

## Output Format:

- $S$, Maximum number of enemies that Berke can slay. 

## Constraints

- $1 \leq N \leq 10^6$
- $1 \leq A \leq 10^6$
- $1 \leq D \leq 10^6$
- $1 \leq P \leq 10^6$
- $1 \leq a_i \leq 10^6$
- $1 \leq b_i \leq 10^6$
