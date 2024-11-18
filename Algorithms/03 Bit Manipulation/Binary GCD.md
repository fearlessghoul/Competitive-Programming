The Binary GCD (Greatest Common Divisor) algorithm, also known as Stein's algorithm, is an efficient method for finding the GCD of two non-negative integers. It uses bitwise operations and is generally faster than the Euclidean algorithm for large integers. Here's how it works:

### Steps of the Binary GCD Algorithm

1. **Base Cases**:
   - If either $ a $ or $ b $ is zero, the GCD is the other number.
2. **Divisibility by 2**:
   - If both $ a $ and $ b $ are even, then $ \text{gcd}(a, b) = 2 \cdot \text{gcd}(a/2, b/2) $.
   - If $ a $ is even and $ b $ is odd, then $ \text{gcd}(a, b) = \text{gcd}(a/2, b) $.
   - If $ a $ is odd and $ b $ is even, then $ \text{gcd}(a, b) = \text{gcd}(a, b/2) $.
3. **Reduction**:
   - If both $ a $ and $ b $ are odd, subtract the smaller number from the larger one, and divide the result by 2. Specifically, if $ a \geq b $, then $ \text{gcd}(a, b) = \text{gcd}((a - b)/2, b) $.

### Detailed Algorithm

1. **Initialize**:

   - If $ a = 0 $, return $ b $.
   - If $ b = 0 $, return $ a $.

2. **Reduce both $ a $ and $ b $ while they are even**:

   - Count the number of common factors of 2 (denote this as $ k $).
   - Reduce $ a $ and $ b $ by dividing them by 2 $ k $ times.

3. **Make $ a $ an odd number**:

   - While $ a $ is even, divide it by 2.

4. **Iterate**:

   - While $ b \neq 0 $:
     - Make $ b $ an odd number by dividing it by 2 as long as it is even.
     - If $ a > b $, swap $ a $ and $ b $.
     - Set $ b = b - a $.

5. **Final Step**:
   - Multiply the final result by $ 2^k $.

### Example

Let's compute the GCD of 48 and 18.

1. $ a = 48 $, $ b = 18 $.
2. Both are even, so $ k = 1 $. Divide both by 2: $ a = 24 $, $ b = 9 $.
3. $ a = 24 $, $ b = 9 $. $ a $ is even, divide by 2: $ a = 12 $.
4. $ a = 12 $, $ b = 9 $. $ a $ is even, divide by 2: $ a = 6 $.
5. $ a = 6 $, $ b = 9 $. $ a $ is even, divide by 2: $ a = 3 $.
6. Now both are odd. Swap if needed: $ a = 3 $, $ b = 9 $.
7. Subtract and divide: $ b = b - a = 6 $. Now $ a = 3 $, $ b = 6 $.
8. $ b $ is even, divide by 2: $ b = 3 $.
9. Now both are odd. Subtract and divide: $ b = b - a = 0 $. $ a = 3 $.

Finally, multiply by $ 2^k $: $ 3 \cdot 2^1 = 6 $.

So, the GCD of 48 and 18 is 6.

### Python Implementation

Here's how you can implement the Binary GCD algorithm in Python:

```python
def binary_gcd(a, b):
    if a == 0:
        return b
    if b == 0:
        return a

    # Finding common factors of 2
    k = 0
    while ((a | b) & 1) == 0:  # while both a and b are even
        a >>= 1
        b >>= 1
        k += 1

    # Divide a by 2 until a becomes odd
    while (a & 1) == 0:
        a >>= 1

    while b != 0:
        while (b & 1) == 0:  # Remove all factors of 2 in b
            b >>= 1

        if a > b:  # Ensure a <= b
            a, b = b, a

        b -= a  # Here b >= a

    return a << k  # Restore common factors of 2

# Example usage
print(binary_gcd(48, 18))  # Output: 6
```

This code efficiently calculates the GCD of two numbers using the Binary GCD algorithm.
