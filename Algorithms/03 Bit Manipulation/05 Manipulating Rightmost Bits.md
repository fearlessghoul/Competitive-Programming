## Manipulation I

1. **Turn off the rightmost 1-bit in a word, producing 0 if none** (e.g., 01011000 → 01010000):

   $
   x \& (x - 1)
   $

   - Application:
     Determine if an unsigned integer is a power of 2 or is 0.

2. **Turn on the rightmost 0-bit in a word, producing all 1's if none** (e.g., 10100111 → 10101111):

   $
   x | (x + 1)
   $

3. **Turn off the trailing 1's in a word, producing $ x $ if none** (e.g., 10100111 → 10100000):

   $
   x \& (x + 1)
   $

   - Application:
     Determine if an unsigned integer is of the form $ 2^n - 1 $, 0, or all 1's.

4. **Turn on the trailing 0's in a word, producing $ x $ if none** (e.g., 10101000 → 10101111):

   $
   x | (x - 1)
   $

5. **Create a word with a single 1-bit at the position of the rightmost 0-bit in $ x $, producing 0 if none** (e.g., 10100111 → 00001000):

   $
   \neg x \& (x + 1)
   $

6. **Create a word with a single 0-bit at the position of the rightmost 1-bit in $ x $, producing all 1's if none** (e.g., 10101000 → 11110111):

   $
   \neg x | (x - 1)
   $

7. **Create a word with 1's at the positions of the trailing 0's in $ x $, and 0's elsewhere, producing 0 if none** (e.g., 01011000 → 00000111):

   $
   \neg x \& (x - 1)
   $

8. **Create a word with 0's at the positions of the trailing 1's in $ x $, and 0's elsewhere, producing all 1's if none** (e.g., 10100111 → 11111000):

   $
   \neg x | (x + 1)
   $

9. **Isolate the rightmost 1-bit, producing 0 if none** (e.g., 01011000 → 00001000):

   $
   x \& (-x)
   $

10. **Create a word with 1's at the positions of the rightmost 1-bit and the trailing 0's in $ x $, producing all 1's if no 1-bit, and the integer 1 if no trailing 0's** (e.g., 01011000 → 00001111):

    $
    x \oplus (x - 1)
    $

11. **Create a word with 1's at the positions of the rightmost 0-bit and the trailing 1's in $ x $, producing all 1's if no 0-bit, and the integer 1 if no trailing 1's** (e.g., 01010111 → 00001111):

    $
    x \oplus (x + 1)
    $

12. **Turn off the rightmost contiguous string of 1's** (e.g., 01011100 → 01000000):

    $
    (((x | (x - 1)) + 1) \& x)
    $

    or

    $
    ((x \& -x) + x) \& x
    $

    - Application:
      Determine if a nonnegative integer is of the form $ 2^j - 2^k $ for some $ j \geq k \geq 0 $.

### Logical Equivalence ($ \equiv $)

Logical equivalence between two statements $A$ and $B$ means that both statements are either true or false at the same time. In terms of bitwise operations, equivalence can be expressed using XOR ($\oplus$) as follows:

$ A \equiv B \iff \neg(A \oplus B) $

### Extended De Morgan's Laws

#### Basic Forms

$
\neg (x \land y) = \neg x \lor \neg y
$

$
\neg (x \lor y) = \neg x \land \neg y
$

#### Unary Operation

$
\neg (x + 1) = -x - 1
$

$
\neg (x - 1) = -x + 1
$

$
\neg (-x) = x - 1
$

#### XOR Operation

$
\neg (x \oplus y) = \neg x \oplus y = x \equiv y
$

#### Equivalence

$
\neg (x \equiv y) = \neg x \equiv y = x \oplus y
$

#### Addition and Subtraction

$
\neg (x + y) = -x - y
$

$
\neg (x - y) = -x + y
$

### Right-to-Left Computability Test

There is a simple test to determine whether or not a given function can be implemented with a sequence of add, subtract, and, or, and not instructions. This test is detailed in the following theorem.

#### Theorem

A function mapping words to words can be implemented with word-parallel add, subtract, and, or, and not instructions if and only if each bit of the result depends only on bits at and to the right of each input operand.

#### Explanation

To understand this theorem, consider the following approach:

1. **Rightmost Bit Calculation**:
   - Imagine computing the rightmost bit of the result by looking only at the rightmost bit of each input operand.
2. **Next Bit Calculation**:

   - Compute the next bit to the left by looking only at the rightmost two bits of each input operand.

3. **Continue This Process**:
   - Continue this process, moving from right to left, for each bit of the result.

If you can successfully compute the result in this right-to-left manner, then the function can be implemented with a sequence of add, and, or, and not instructions. If the function cannot be computed in this right-to-left manner, then it cannot be implemented with such a sequence of instructions.

#### Illustration with an Example

Suppose we have a function of two variables, $x$ and $y$, that satisfies the right-to-left computability property. Assume that bit 2 of the result $r$ is given by:

$ r_2 = f(x, y) $

Here, bits are numbered from right to left, 0 to 31. Because bit 2 of the result is a function of bits at and to the right of bit 2 of the input operands, bit 2 of the result is “right-to-left computable.”

1. **Arrange the Words**:

   - Arrange the computer words $x$, $x$ shifted left two, and $y$ shifted left one, as shown below:

     $
     \begin{array}{l}
     x \\
     x \ll 2 \\
     y \ll 1 \\
     \text{mask}
     \end{array}
     $

2. **Form Word-Parallel Operations**:

   - Perform word-parallel and of lines 2 and 3, or the result with row 1, and and the result with the mask (as shown above). The result is a word of all 0’s except for the desired result bit in position 2.

3. **Compute Other Bits**:
   - Perform similar computations for the other bits of the result, or the 32 resulting words together, and the result is the desired function.

This construction shows that the function can be implemented with instructions in the basic list, even if it may not yield an efficient program.

#### Application of the Theorem

Using this theorem, we can see that certain operations cannot be implemented with a sequence of add, subtract, and, or, and not instructions:

1. **Turning Off the Leftmost 1-bit**:

   - This operation cannot be done because it requires looking to the left to see if a certain 1-bit is the leftmost one.

2. **Right Shift, Rotate Shift, and Left Shift by a Variable Amount**:

   - These operations cannot be done in this manner.

3. **Counting the Number of Trailing 0’s**:
   - To count trailing 0’s, the rightmost bit of the result will be 1 if there are an odd number of trailing 0’s, and we must look to the left of the rightmost position to determine that. Therefore, this operation cannot be implemented with the given instructions.

### A Novel Application

An interesting application of bit manipulation is finding the next higher number after a given number that has the same number of 1-bits. This is useful in situations where bit strings represent subsets. The possible members of a set are listed in a linear array, and a subset is represented by a word or sequence of words in which bit $i$ is on if member $i$ is in the subset. Set unions are computed by the logical OR of the bit strings, intersections by ANDs, and so on.

One might want to iterate through all the subsets of a given size. This is easily done if you have a function that maps a given subset to the next higher number (interpreting the subset string as an integer) with the same number of 1-bits.

A concise algorithm for this operation was devised by R. W. Gosper. Given a word $x$ that represents a subset, the idea is to find the rightmost contiguous group of 1’s in $x$ and the following 0’s, and “increment” that quantity to the next value that has the same number of 1’s. For example, the string $xxx0 \ 1111 \ 0000$, where $xxx$ represents arbitrary bits, becomes $xxx1 \ 0000 \ 0111$.

### The Algorithm

1. **Identify the "Smallest" 1-bit**:

   - Compute $ s = x \& -x $. This gives the rightmost 1-bit in $ x $.

     $
     s = x \& -x \implies 0000 \ 0001 \ 0000
     $

2. **Increment the Rightmost 1-bit Group**:

   - Add $ s $ to $ x $, giving $ r $.

     $
     r = x + s \implies xxx1 \ 0000 \ 0000
     $

   - The 1-bit here is one bit of the result.

3. **Produce a Right-Adjusted String of $ n - 1 $ 1’s**:

   - Compute the exclusive OR of $ r $ and $ x $.

     $
     \text{ones} = r \oplus x \implies 0001 \ 1111 \ 0000
     $

   - Right-adjust the 1’s by dividing by $ s $ (since $ s $ is a power of 2) and shifting right to discard unwanted bits.

     $
     \text{ones} = (\text{ones} \gg 2) / s \implies 0000 \ 0000 \ 0111
     $

4. **Combine Results**:

   - The final result is the OR of this adjusted string and $ r $.

     $
     y = r | \text{ones} \implies xxx1 \ 0000 \ 0111
     $

### C Implementation

Here is a complete C procedure that executes this algorithm in seven basic RISC instructions, one of which is division (do not use this procedure with $ x = 0 $; that causes division by 0):

```c
unsigned snoob(unsigned x) {
   unsigned smallest, ripple, ones;
                                   //  x = xxx0  1111  0000
   smallest = x & -x;              //      0000  0001  0000
   ripple = x + smallest;          //      xxx1  0000  0000
   ones = x ^ ripple;              //      0001  1111  0000
   ones = (ones >> 2) / smallest;  //      0000  0000  0111
   return ripple | ones;           //      xxx1  0000  0111
}
```

_Next higher number with the same number of 1-bits._

### Alternative Methods

If division is slow but you have a fast way to compute the number of trailing zeros function $ \text{ntz}(x) $, the number of leading zeros function $ \text{nlz}(x) $, or population count (pop(x) is the number of 1-bits in $ x $), then the last line of the equation can be replaced with one of the following formulas. (The first two methods can fail on a machine that has modulo 32 shifts.)
