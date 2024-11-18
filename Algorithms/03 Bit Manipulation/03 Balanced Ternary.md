# Balanced Ternary

The Setun computer utilizes a balanced ternary system, a non-standard but positional numeral system. In this system, digits can have values of -1, 0, and 1. Although its base is still 3, representing -1 with a digit is inconvenient, so we use the letter 'Z' instead. This system might seem unusual, but it has been employed in computing, as shown in the accompanying image of one such computer.

Here are the first few numbers written in balanced ternary:

| Decimal | Balanced Ternary |
| ------- | ---------------- |
| 0       | 0                |
| 1       | 1                |
| 2       | 1Z               |
| 3       | 10               |
| 4       | 11               |
| 5       | 1ZZ              |
| 6       | 1Z0              |
| 7       | 1Z1              |
| 8       | 10Z              |
| 9       | 100              |

## Negative Numbers in Balanced Ternary

This system allows for writing negative values without a leading minus sign by simply inverting the digits of any positive number:

| Decimal | Balanced Ternary |
| ------- | ---------------- |
| -1      | Z                |
| -2      | Z1               |
| -3      | Z0               |
| -4      | ZZ               |
| -5      | Z11              |

Note that a negative number starts with 'Z' and a positive number with '1'.

## Conversion Algorithm

To convert a number to balanced ternary, you can first represent it in the standard ternary numeral system. Standard ternary digits are 0, 1, and 2. While processing from the least significant digit, you can:

- Skip digits 0 and 1.
- Convert digit 2 to 'Z' and add 1 to the next higher digit.
- Convert digit 3 (resulting from carrying over) to 0 and add 1 to the next higher digit.

### Example 1: Converting 64 to Balanced Ternary

1. Represent 64 in standard ternary:
   $ 64*{10} = 02101*{3} $

2. Process from the least significant digit:

   - Skip 1, 0, and 1.
   - Convert 2 to 'Z' and add 1 to the next digit, resulting in 1Z101.

3. Convert back to decimal:
   $ 1Z101 = 1 \cdot 81 + (-1) \cdot 27 + 1 \cdot 9 + 0 \cdot 3 + 1 \cdot 1 = 64\_{10} $

### Example 2: Converting 237 to Balanced Ternary

1. Represent 237 in standard ternary:
   $ 237*{10} = 22210*{3} $

2. Process from the least significant digit:

   - Skip 0 and 1.
   - Convert 2 to 'Z' and add 1 to the next digit, resulting in 23Z10.
   - Convert 3 to 0 and add 1 to the next digit, resulting in 30Z10.
   - Convert 3 to 0 and add 1 to the next digit, resulting in 100Z10.

3. Convert back to decimal:
   $ 100Z10 = 1 \cdot 243 + 0 \cdot 81 + 0 \cdot 27 + (-1) \cdot 9 + 1 \cdot 3 + 0 \cdot 1 = 237\_{10} $

### Conversion Algorithm for Negative Numbers

1. Convert the Absolute Value to Balanced Ternary.
2. Invert the Digits for Negative Numbers:
   - Replace "1" with "Z".
   - Replace "Z" with "1".
   - Leave "0" unchanged.

## Pseudocode

```plaintext
function base3ToBalancedTernary(base3_num):
    # Check if the number is negative
    is_negative = False
    if base3_num < 0:
        is_negative = True
        base3_num = abs(base3_num)

    # Initialize variables
    balanced_ternary = ""
    carry = 0

    # Convert base3_num to a string for easy digit manipulation
    base3_str = str(base3_num)

    # Iterate over the digits from right to left (least significant to most significant)
    for i in range(len(base3_str) - 1, -1, -1):
        # Get the current digit and add any carry
        digit = int(base3_str[i]) + carry

        # Determine the balanced ternary equivalent and update the carry
        if digit == 0:
            balanced_ternary = "0" + balanced_ternary
            carry = 0
        elif digit == 1:
            balanced_ternary = "1" + balanced_ternary
            carry = 0
        elif digit == 2:
            balanced_ternary = "Z" + balanced_ternary
            carry = 1
        elif digit == 3:
            balanced_ternary = "0" + balanced_ternary
            carry = 1

    # If there's still a carry left, add it as the most significant digit
    if carry == 1:
        balanced_ternary = "1" + balanced_ternary

    # If the number was negative, invert the balanced ternary digits
    if is_negative:
        inverted_balanced_ternary = ""
        for digit in balanced_ternary:
            if digit == "0":
                inverted_balanced_ternary += "0"
            elif digit == "1":
                inverted_balanced_ternary += "Z"
            elif digit == "Z":
                inverted_balanced_ternary += "1"
        balanced_ternary = inverted_balanced_ternary

    return balanced_ternary
```

### Explanation:

1. **Check if the Number is Negative**:
   - If `base3_num` is negative, set `is_negative` to `True` and convert `base3_num` to its absolute value.
2. **Initialization**:
   - `balanced_ternary` stores the result as a string.
   - `carry` is initialized to 0 to handle any carried values during the conversion.
3. **Convert Base 3 Number to String**:
   - `base3_num` is converted to a string to facilitate easy digit manipulation.
4. **Iterate Over Digits**:
   - Iterate from the least significant digit to the most significant digit (right to left).
   - For each digit, add any carry from the previous digit.
   - Depending on the resulting value (0, 1, 2, or 3), update the `balanced_ternary` string and set the appropriate carry.
5. **Handle Final Carry**:
   - If there's a carry left after processing all digits, add it to the beginning of the `balanced_ternary` string.
6. **Invert Digits for Negative Numbers**:
   - If the original number was negative, invert the digits of the balanced ternary result by converting '1' to 'Z', 'Z' to '1', and leaving '0' as is.
7. **Return Result**:
   - Return the `balanced_ternary` string as the final result.
