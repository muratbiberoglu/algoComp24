# Statement

algoComp isn't just about coding. Us coders should also be provided with dope songs so that we get motivated listening to them.

Realizing this important situation, our team decided to prepare a special Spotify playlist: ***algoComp Wrapped***! Here are our four pioneers who are going to prepare the playlist:

- **Hacer** will prepare the initial playlist containing a huge amount of random songs. Precisely, there will be $n$ songs. As she is a Malatian, the songs will already be awesome. Trust her; if you don't, you'll have to face consequences...
- **Ceren** will assign unique points between $1$ and $n$ to each song. These points indicate how much she enjoys them: the higher the point, the more she enjoys. Of course, this assignment is going to be strongly opinionated because it's only based on Ceren's liking. However, trust her choices also. You know what happens if you don't, right? Consequences... remember.
- **Bilge** will pick the songs that will appear in ***algoComp Wrapped*** based on the points Ceren assigned. Hey, we disallow doubt. Her picking will be neat.
- **Fatih** will check the final playlist of songs that Bilge prepared against a *pretty strict* rule. ***algoComp Wrapped*** will be published only if it satisfies Fatih's rule. Umm, yeah... so, this is where Fatih shouldn't actually trust Bilge. It's you who must trust, not them!

What's that strict rule, then? By the way, since our beloved teammate Fatih specified the rules, thank him ~~for being annoying~~!

1. Let the orders of the songs Bilge picked be $s_1, s_2, \dots, s_k$. These are their orders in the initial playlist that Hacer prepared. So, there are $k$ songs picked for ***algoComp Wrapped***.
2. Respectively, let their points that Ceren assigned be $p_{s_1}, p_{s_2}, \dots, p_{s_k}$. Note that **they will always be unique**.
3. Fatih will sort these songs in decreasing order of points. Let the original orders of the sorted songs be $s'_{1}, s'_{2}, \dots, s'_{n}$, e.g., the most liked song's order in the initial playlist is $s'_{1}$ (whose point is $p_{s'_{1}}$), and the least liked song's order is $s'_{n}$. Afterward, all that's left is the rule itself:
    - The second song must be above the first song in the initial playlist Hacer prepared, that is, $s'_{2} < s'_{1}$.
    - The third song must be below the first song, i.e., $s'_{3} > s'_{1}$.
    - The fourth song must be above the second song, i.e., $s'_{4} < s'_{2}$.
    - The fifth song must be above the third song, i.e., $s'_{5} > s'_{3}$.
    - Similarly, these must hold:
        $$
        \begin{align*}
            s'_{6} &< s'_{4} \\
            s'_{7} &> s'_{5} \\
            s'_{8} &< s'_{6} \\
            & \vdots \\
        \end{align*}
        $$
    In other words, every song must be below or above all previous songs depending on its parity of sorted order. Also, the rule is satisfied when $k = 1$.

By the way, doesn't this random-looking rule remind you of anything?

Once Hacer and Ceren finishes their jobs, the **algoComp Wrapped** team wonders how many different choices Bilge can make that satisfy Fatih's strict rule (note that there are $2^n - 1$ possible choices in total). That is, how many different **algoComp Wrapped**s can be prepared, they wonder.

Since they have a LOT of time, they can try every possible choice. Well, that's definitely not the case for you!

Find the number of different **algoComp Wrapped**s. There might be so many that you have to calculate it modulo $10^9 + 7$.

# Input Format

The first line contains a single integer $t$ — the number of test cases.

The descriptions of the test cases follow:
- The first line of each test case contains a single integer $n$ — the number of songs in the initial playlist that Hacer prepared.
- The second line of each test case contains $n$ integers $p_1, p_2, \dots, p_n$ — the points that Ceren assigned.

# Output Format

For each test case, print the answer (modulo $10^9 + 7$) on a single line — the number of **algoComp Wrapped**s for that test case.

# Constraints

- $1 \le t \le 5000$
- $1 \le n \le 5000$
- $1 \le p_i \le n$
- It is guaranteed that all $p_i$ are unique per each test case.
- It is guaranteed that the sum of $n$ over all test cases does not exceed $5000$.