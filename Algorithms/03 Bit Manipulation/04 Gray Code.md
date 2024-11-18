# Gray Code

Gray code is a binary numeral system where two successive values differ by only one bit.

For example, the sequence of Gray codes for 3-bit numbers is: 000, 001, 011, 010, 110, 111, 101, 100. So, for the 4th number in the sequence, the Gray code is 6.

This code was invented by Frank Gray in 1953.

## Finding Gray Code

Consider the bits of a number $ n $ and the bits of the corresponding Gray code $ G(n) $. Notice that the $ i $-th bit of $ G(n) $ equals 1 only when the $ i $-th bit of $ n $ is 1 and the $ (i + 1) $-th bit is 0, or vice versa (the $ i $-th bit is 0 and the $ (i + 1) $-th bit is 1). Thus, the Gray code can be computed as:
$ G(n) = n \oplus (n >> 1) $

Here is the corresponding code:

```c
int g(int n) {
    return n ^ (n >> 1);
}
```

## Finding Inverse Gray Code

Given a Gray code $ g $, you can restore the original number $ n $.

Move from the most significant bits to the least significant ones (the least significant bit has index 1, and the most significant bit has index $ k $). The relation between the bits $ n_i $ of number $ n $ and the bits $ g_i $ of number $ g $ is:

$
\begin{aligned}
n_k &= g_k, \\
n_{k-1} &= g_{k-1} \oplus n_k = g_k \oplus g_{k-1}, \\
n_{k-2} &= g_{k-2} \oplus n_{k-1} = g_k \oplus g_{k-1} \oplus g_{k-2}, \\
n_{k-3} &= g_{k-3} \oplus n_{k-2} = g_k \oplus g_{k-1} \oplus g_{k-2} \oplus g_{k-3}, \\
&\vdots
\end{aligned}
$

The simplest way to write this in code is:

```c
int rev_g(int g) {
    int n = 0;
    while (g != 0) {
        n ^= g;
        g >>= 1;
    }
    return n;
}
```

## Practical Applications

Gray codes have several practical and sometimes unexpected applications:

1. **Hypercube Hamiltonian Cycle**: The Gray code of $ n $ bits forms a Hamiltonian cycle on an $ n $-dimensional hypercube, where each bit corresponds to one dimension.
2. **Minimizing Errors in Digital-to-Analog Conversion**: Gray codes are used to minimize errors in digital-to-analog signal conversions, such as in sensors.

3. **Solving the Towers of Hanoi Problem**: Gray codes can be used to solve the Towers of Hanoi problem. Let $ n $ denote the number of disks. Start with the Gray code of length $ n $, which consists of all zeros ($ G(0) $), and move between consecutive Gray codes (from $ G(i) $ to $ G(i+1) $). The $ i $-th bit of the current Gray code represents the $ n $-th disk (the least significant bit corresponds to the smallest disk, and the most significant bit to the largest disk). Since exactly one bit changes at each step, changing the $ i $-th bit corresponds to moving the $ i $-th disk. There is always exactly one move option for each disk (except the smallest one) at each step (except the start and finish positions). There are always two move options for the smallest disk, but there is a strategy that will always lead to a solution: if $ n $ is odd, the sequence of the smallest disk moves looks like $ f \to t \to r \to f \to t \to r \to ... $ (where $ f $ is the initial rod, $ t $ is the terminal rod, and $ r $ is the remaining rod), and if $ n $ is even, $ f \to r \to t \to f \to r \to t \to ... $.

4. **Genetic Algorithms**: Gray codes are also used in genetic algorithms.
