# Statement

<div align="justify" style="width: 50%; margin-left: auto; font-style: italic">
"When a person has extreme social anxiety they struggle to communicate with others. Bear in mind, that they only struggle to form connections. It doesn’t mean that they don’t want to."

<p align="right">—Tomohito Oda</p>
</div>

Komi has struggled to communicate with the people around her ever since she was born. It's because she gets a lot more excited, scared and shy if she even attempts to open her mouth:

- *How could I even talk?*
- *What if I say something wrong?*
- *What if they get me wrong?*
- *What if they dislike my voice?*

*<p align="center">Will I ever make friends?</p>*

Thankfully, Tadano saw the real potential lying within her, and decided to befriend Komi and help her reach a huge number of friends that she can't even imagine.

As a clever one, Tadano has invented this fun technique for Komi: ***friendship chocolates***! *(Komi got surprised because this is something she had thought about before...)*

The thing about *friendship chocolates* is that she will share chocolates with whom she wants to befriend:
- The first friend (candidate) gets $c$ chocolates,
- The second friend gets $c + 1$ chocolates,
- The third friend gets $c + 2$ chocolates,
- ...and eventually, the $n^{th}$ and the final friend gets $c + n - 1$ chocolates.

Since Komi wants her future friends to have **all** the chocolate she has, she isn't willing to have even a single chocolate left unshared. Also, since she is going to share some chocolates with Tadano, she wants at least one more friend besides Tadano; that is, $n > 1$.

Here, Tadano takes place as Komi's dearest friend who's going to find $n$, or determine whether Komi can't share her chocolates as she desires.

Komi has $k$ chocolates. Tadano is so smart that he doesn't need the thinking to find $n$. To make things a bit fun for him requires multiple scenarios!

To entertain her dearest friend, Komi notices she can at least create imaginary scenarios:

- She imagines a new scenario by multiplying the number of her chocolates in the previous scenario by an arbitrary integer $m$. Afterward, she asks Tadano to find $n$ again for this scenario (or determine that it's impossible).
- For the first imaginary scenario, the previous scenario is the real life where Komi has $k$ chocolates. So, for the first scenario, there will be $k \cdot m$ chocolates.

As Tadano would want a lot of scenarios, Komi will imagine $s$ of them.

Your duty as the reader is to predict Tadano's findings!

# Input Format

The first line contains two integers $k$ and $s$ — the number of Komi's chocolates, and the number of scenarios she will imagine, respectively.

Each of the next $s$ lines contains an integer $m$ — the integer to multiply the number of Komi's chocolates by.

# Output Format

For each scenario including the real life, print $n$ if Komi can share her chocolates; otherwise, print `No one but Tadano`. Note that you have to print $s + 1$ lines.

# Constraints

- $1 \le s \le 10^6$
- $1 \le k, m \le 10^7$