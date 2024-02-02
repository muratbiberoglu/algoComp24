# Statement

<div style="text-align: right; font-style: italic">
Endlessly gazing in nocturnal prime<br>
She spoke of her vices and broke the rhyme<br>
But baffled herself with the final line:<br>
“My promise is made but my heart is thine”<br>
— <a href="https://www.youtube.com/watch?v=bpjOvdlqJZA&list=OLAK5uy_lzS6aMbbwuN1hIhrwf9npFIzLrprkiV_4" target="_blank">Face of Melinda</a>
</div>

<div style="text-align: center">
<img src="https://m.media-amazon.com/images/I/91Sj8Jafo5S._UF1000,1000_QL80_.jpg" width="50%" style="box-shadow: 0 0 10px red; border-radius: 50%; transition-duration: 750ms" onmouseover="this.style.boxShadow='0 0 50px red'; this.style.borderRadius='50px'" onmouseout="this.style.boxShadow='0 0 10px red'; this.style.borderRadius='50%'">

_Still Life Album Cover (Opeth)_
</div>

<hr>

Listening to *Face of Melinda*, one must shout the last line just like Mikael:

<p style="text-align: center; font-style: italic; font-weight: bold; color:red">
<span style="filter: contrast(0.3)">MY</span> <span style="filter: contrast(0.4)">PROMISE</span> <span style="filter: contrast(0.5)">IS</span> <span style="filter: contrast(0.6)">MADE</span> <span style="filter: contrast(0.7)">BUT</span> <span style="filter: contrast(0.8)">MY</span> <span style="filter: contrast(0.9)">HEEEEAAAAAAAAAARRTTT</span> <span style="filter: contrast(1)">IIIIIIIISSSS</span> <span style="filter: contrast(1.1)">THIIIIIINNEEEEEEEEEE</span>
</p>

This is required because you can't just stay silent as Mikael sings the masterpiece — gotta catch the vibe.

Being obsessed with the song and listening to it everyday, Berke constructed a long string $melinda$ using the words mentioned in *Face of Melinda*. As a result, $melinda$ consists of $n$ lowercase letters of the English alphabet.

Afterward, Berke asked for Murat's help to extract a dope problem for algoComp — Berke strictly required the story to be based on *Face of Melinda*; this way, he could honor his favourite song. Although Murat first thought this was nonsense, the duo then thought a bit to come up with the following problem:

- In $melinda$, they wonder for each of the $n$ letters, how many subsequences of $melinda$ that are equal to `myheartisthine` include that letter.

However, unfortunately, they couldn't come up with an efficient solution. _(Can you actually believe that?! Such losers...)_

Fortunately, there is always more than one solution to any problem. For the current one, Berke and Murat quickly realized that another of their rock-lover teammates Ceren might be that other solution. As a **PRO**blem solver who doesn't need more than half an hour to solve problems, Ceren has came up with a blazingly fast solution after a few minutes, leaving the duo's mouths open.

Using this amazing solution, Berke, Murat and Ceren saved these $n$ answers modulo $10^9 + 7$ as an unforgettable mouth-opening memory.

So, what are the answers? _(Did you actually think that we, the trio, would reveal them?!)_

# Input Format

The first line contains an integer $t$ — the number of test cases.

Each of the following $t$ lines contains a single string — $melinda$.

# Output Format

For each test case, print $n$ space-separated integers on a new line. Here, $n$ is the size of $melinda$ for the corresponding test case, and the $i^{th}$ integer corresponds to the answer to the $i^{th}$ letter in $melinda$.

As they might be huge, print the answers modulo $10^9 + 7$.

# Constraints

- $1 \le t \le 10^5$
- $1 \le n \le 10^6$
- It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.