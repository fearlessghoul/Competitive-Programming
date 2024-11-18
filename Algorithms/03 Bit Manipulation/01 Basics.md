# Comprehensive Guide to Bit Manipulation

_Updated on: 18 Apr, 2023_

Bit Manipulation is a powerful technique in programming that offers optimized solutions, especially in Competitive Programming. It revolves around using Bitwise Operators that directly operate on the binary representation of numbers, enhancing efficiency. Here's an overview of Bitwise Operators:

- **Bitwise AND (&)**
- **Bitwise OR (|)**
- **Bitwise XOR (^)**
- **Bitwise NOT (~)**

## Bit Representation

In programming, an n-bit integer is stored as a binary number consisting of n bits. For example, in C++, an `int` is a 32-bit type, meaning each `int` number consists of 32 bits.

For instance, the `int` number 43 is represented as:

```
00000000000000000000000000101011
```

### Converting Bit Representation to a Number

The bits are indexed from right to left. To convert a bit representation $b_k \cdots b_2 b_1 b_0$ into a number, use the formula:

$ b_k \cdot 2^k + \cdots + b_2 \cdot 2^2 + b_1 \cdot 2^1 + b_0 \cdot 2^0 $

Example:
$ 1 \cdot 2^5 + 1 \cdot 2^3 + 1 \cdot 2^1 + 1 \cdot 2^0 = 43 $

## Signed and Unsigned Representation

### Signed Representation

A signed n-bit variable can hold values between $-2^{n-1}$ and $2^{n-1} - 1$. In C++, `int` is a signed type, so it ranges from $-2^{31}$ to $2^{31} - 1$.

- **Sign Bit:** The first bit indicates the sign (0 for non-negative, 1 for negative). The remaining n-1 bits represent the magnitude.
- **Two's Complement:** To find the opposite of a number, invert all bits and add one.

Example:

- The bit representation of -43 is:
  ```
  11111111111111111111111111010101
  ```

### Unsigned Representation

An unsigned n-bit variable can hold values between 0 and $2^n - 1$. For instance, an `unsigned int` in C++ ranges from 0 to $2^{32} - 1$.

### Overflow Behavior

If a number exceeds the upper limit of its bit representation, it will overflow. In signed representation, the next number after $2^{n-1} - 1$ is $-2^{n-1}$. In unsigned representation, the next number after $2^n - 1$ is 0.

## Common Bitwise Operations

Here are some common bitwise operations:

| Operator | Operation | Result |
| -------- | --------- | ------ | --- |
| XOR      | X ^ 0s    | X      |
| XOR      | X ^ 1s    | ~X     |
| XOR      | X ^ X     | 0      |
| AND      | X & 0s    | 0      |
| AND      | X & 1s    | X      |
| AND      | X & X     | X      |
| OR       | X         | 0s     | X   |
| OR       | X         | 1s     | 1s  |
| OR       | X         | X      | X   |

### Get Bit

To find the bit at a specific position (i) in a number (N):

```cpp
bool getBit(int num, int i) {
    return ((num & (1 << i)) != 0);
}
```

### Set Bit

To set the bit at a specific position (i) in a number (N):

```cpp
int setBit(int num, int i) {
    return num | (1 << i);
}
```

### Clear Bit

To clear the bit at a specific position (i) in a number (N):

```cpp
int clearBit(int num, int i) {
    int mask = ~(1 << i);
    return num & mask;
}
```

### Example Program

```cpp
#include <iostream>
using namespace std;

bool getBit(int num, int i) {
    return ((num & (1 << i)) != 0);
}

int setBit(int num, int i) {
    return num | (1 << i);
}

int clearBit(int num, int i) {
    int mask = ~(1 << i);
    return num & mask;
}

int main() {
    int N = 70;

    cout << "The bit at the 3rd position from LSB is: "
         << (getBit(N, 3) ? '1' : '0') << endl;

    cout << "The value of the given number after setting the bit at LSB is: "
         << setBit(N, 0) << endl;

    cout << "The value of the given number after clearing the bit at LSB is: "
         << clearBit(N, 0) << endl;

    return 0;
}
```

**Output:**

```
The bit at the 3rd position from LSB is: 0
The value of the given number after setting the bit at LSB is: 71
The value of the given number after clearing the bit at LSB is: 70
```

### Time Complexity: O(1)

### Auxiliary Space: O(1)
