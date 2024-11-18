## Addition Combined with Logical Operations

We assume the reader is familiar with the elementary identities of ordinary algebra and Boolean algebra. Below is a selection of similar identities involving addition and subtraction combined with logical operations.

a. $-x = \neg x + 1 = \neg (x-1)$

b. $\neg -x = x - 1$

c. $-\neg x = -x - 1$

d. $\neg -\neg x = x + 1$

e. $\neg -\neg x = x - 1$

f. $x + y = x \neg -y - 1 = (x \oplus y) + 2(x \& y)$

g. $(x \oplus y) + 2(x \& y) = (x \vert y) + (x \& y)$

h. $(x \vert y) + (x \& y) = 2(x \vert y) - (x \oplus y)$

i. $x - y = x + \neg y + 1 = (x \oplus y) - 2(\neg x \& y)$

j. $(x \oplus y) - 2(\neg x \& y) = (x \& \neg y) - (\neg x \& y)$

k. $(x \& \neg y) - (\neg x \& y) = 2(x \& \neg y) - (x \oplus y)$

l. $x \oplus y = (x \vert y) - (x \& y)$

m. $x \& \neg y = (x \vert y) - y$

n. $x - (x \& y) = x - (x \& y)$

o. $\neg (x - y) = y - x - 1 = \neg x + y$

p. $x \equiv y = (x \& y) - (x \vert y) - 1 = (x \& y) + \neg (x \vert y)$

q. $x \vert y = (x \& \neg y) + y$

r. $x \& y = (\neg x \vert y) - \neg x$

### Additional Information

- Equation (d) can be applied to itself repeatedly, giving $-\neg -\neg x = x + 2$, and so on. Similarly, from (e) we have $\neg -\neg -\neg x = x - 2$. So we can add or subtract any constant using only the two forms of complementation.

- Equation (f) is the dual of (j), where (j) is the well-known relation that shows how to build a subtracter from an adder.
- Equations (g) and (h) are from HAKMEM memo [HAK, item 23]. Equation (g) forms a sum by first computing the sum with carries ignored ($x \oplus y$), and then adding in the carries. Equation (h) modifies the addition operands so that the combination $0 + 1$ never occurs at any bit position; it is replaced with $1 + 0$.
- It can be shown that in the ordinary addition of binary numbers with each bit independently equally likely to be 0 or 1, a carry occurs at each position with a probability of about 0.5. However, for an adder built by preconditioning the inputs using (g), the probability is about 0.25. This observation is probably not valuable in building an adder, because the important characteristic for that purpose is the maximum number of logic circuits the carry must pass through, and using (g) reduces the number of stages the carry propagates through by only one.
- Equations (k) and (l) are duals of (g) and (h), for subtraction. Equation (k) has the interpretation of first forming the difference ignoring the borrows ($x - y$), and then subtracting the borrows. Similarly, Equation (l) modifies the subtraction operands so that the combination $1 - 1$ never occurs at any bit position; it is replaced with $0 - 0$.
- Equation (n) shows how to implement exclusive or in only three instructions on a basic RISC. Using only and-or-not logic requires four instructions $((x \vert y) \& \neg (x \& y))$. Similarly, (u) and (v) show how to implement and and or in three other elementary instructions, whereas using De Morgan’s laws requires four.
