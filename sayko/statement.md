# Sayko

Sena enjoys hosting social gatherings for ITU ACM members to bond and have fun. For their latest gathering, she organized a game called Sayko. Here's how it works:

1. Sena arranged $N$ members in a circle and asked Ceren to leave the room temporarily, ensuring she couldn't overhear their discussion.
2. The members collectively decided on a random order for the English alphabet.
3. They agreed that the game would revolve around the initials of each person's name. Each member learned the position of their initial in the new alphabet.
4. When Ceren returned, she would ask someone their name, and the initial of the responder's name would dictate the speaking order.
5. The first responder would count clockwise from themselves according to the assigned positions in the alphabet. The person at the counted position would then speak, stating their name, thus continuing the cycle.
6. The round would end when someone with the same initial as the initial responder was encountered, indicating completion of the cycle.
7. The game would conclude when Ceren correctly guessed the established rule.

Sena wants to ensure that rounds don't drag on for too long. Given the seating arrangement and the pre-determined alphabet order, she needs to calculate how many names will be spoken in a round starting from a particular person. Could you help her with this calculation?

# Input Format

The first line contains a string, $s$, representing the sitting order based on initials. It's important to note that the players sit in a circle, and the $i+1^{th}$ index in $s$ represents the person sitting to the left of the $i^{th}$ person.

The second line contains a permutation of the English alphabet, consisting only of lowercase letters.

The third line contains an integer, $q$, indicating the number of queries.

Subsequent $q$ lines each contain an integer $i$, representing the index of a person in $s$. This person starts the round by saying their name.

# Output Format

For each query, print the number of names that will be spoken in a round starting from the given person on a new line. If the round does not end, print $-1$.

# Constraints

$ 1 \leq N \leq 2 * 10^5  $

$ 1 \leq q \leq 2 * 10^5  $

$ 0 \leq i \leq N $