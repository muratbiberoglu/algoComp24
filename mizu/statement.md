# Statement

Mizu could not forget <a href="https://www.magicalquote.com/seriesquotes/what-is-a-sword/" target="_blank">one of the most memorable conversations</a> with her master and father, Eiji:

<p align="center">
<img src="https://static.wikia.nocookie.net/blue-eye-samurai/images/4/42/Learning_from_Swordfather_Eiji.jpg/revision/latest/scale-to-width-down/1000?cb=20231110201314" width="40%" style="border-radius: 30px"><br>
<i>Master Eiji and Mizu forging a sword</i>
</p>

_<p align="right" style="color: #d1501f">What really is a sword, Mizu?</p>_

_<p style="color: #44627a">The soul of the samurai who carries it. Isn't it, master?</p>_

_<p align="right" style="color: #d1501f">It is a line. On one side of the line is life. The other, death.<br>The edge we forge cuts the line between life and death.</p>_

_<p style="color: #44627a">It really is, master. As wise as usual...</p>_

As the master's words affected her opinions about swords, she decided to extract the true meaning lying under _"the edge"_.

To accomplish her pursuit, she needs to cut a _special_ tree in perfect halves with her sword, the bluest of all.

And so, the blue-eyed samurai's journey begins...

<p align="center">
<img src="https://th-i.thgim.com/public/entertainment/movies/mtcic5/article67521286.ece/alternates/FREE_1200/b1.jpeg" width="70%" style="border-radius: 50px"><br>
<i>Mizu on her way to find the tree</i>
</p>

<hr>

Impressed a lot by Mizu's story, Berke prepared his hands to extract a problem out of it. At first, he models the tree as $n$ rectangles with varying widths stacked on top of each other. Each rectangle has a height of $1$ unit, and the $i^{th}$ rectangle has a width of $w_i$ units. The bottommost rectangle is the $1^{st}$ rectangle, and the topmost is the $n^{th}$.

What Berke believes Mizu should accomplish is:

1. She must start cutting the tree from the bottom left corner of the first rectangle.
2. She must split the tree with a straight cut in two halves with equal areas.

So, he got curious about the cutting angle, that is, the angle between the cut and the ground. This is where he needed another anime-lover teammate Serhat's help.

After Berke reached Serhat, he realized Serhat hadn't watched the anime yet. However, Serhat didn't consider it an excuse, and the duo started thinking about how to find the cutting angle.

<p align="center">
<img src="https://i.ytimg.com/vi/LjTHGeUkHew/maxresdefault.jpg" width="30%" style="border-radius: 30px">
</p>

Well... they couldn't. _(What a surprise!)_ Thankfully, Ömer saw the duo's struggle, and prepared to help.

<p align="center">
<img src="https://i.ytimg.com/vi/Z1wT1-3b1hQ/maxresdefault.jpg" width="30%" style="border-radius: 30px">
</p>

After a quick analysis, Ömer found out the observations required to find that angle, and shared his ideas with Berke and Serhat, leaving their mouths open.

The trio then used Ömer's wonderful observations to find the cutting angle Mizu needs.

What's the angle, then? _(They refused to reveal the answer!)_

# Input Format

The first line contains a single integer $t$ — the number of test cases.

The descriptions of the test cases follow:

- The first line of each test case contains a single integer $n$ — the number of rectangles that form the tree.
- The second line of each test case contains $n$ integers $w_1, w_2, \dots, w_n$ — the widths of the rectangles.

# Output Format

Print $t$ lines where the $i^{th}$ line contains the answer (a real number) for the $i^{th}$ test case.

# Constraints

- $1 \le t \le 10^5$
- $1 \le n \le 10^6$
- $1 \le w_i \le 10^{12}$
- It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.