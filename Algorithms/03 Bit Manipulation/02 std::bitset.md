# `std::bitset` in C++

## Basic Definition
`std::bitset` is a C++ Standard Template Library (STL) class template that represents a fixed-size sequence of bits. It allows for bit manipulation and provides various methods to perform operations on these bits.

## Syntax
```cpp
#include <bitset>
std::bitset<N> bitsetName;
```
- `N` is the number of bits in the bitset.
- `bitsetName` is the name of the bitset.

## Key Features
- **Fixed Size**: The size of `std::bitset` is determined at compile-time and cannot be changed at runtime.
- **Bit Manipulation**: Provides various functions to manipulate individual bits or perform operations on the entire set.

## Example
```cpp
#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> bset1;       // Default constructor initializes to 00000000
    std::bitset<8> bset2(177);  // Binary representation of 177 (10110001)
    std::bitset<8> bset3("1100"); // Binary string (00001100)

    std::cout << "bset1: " << bset1 << std::endl;
    std::cout << "bset2: " << bset2 << std::endl;
    std::cout << "bset3: " << bset3 << std::endl;

    // Accessing individual bits
    std::cout << "bset2[0]: " << bset2[0] << std::endl; // Least significant bit
    std::cout << "bset2[7]: " << bset2[7] << std::endl; // Most significant bit

    // Setting and resetting bits
    bset1.set(1); // Set the bit at position 1
    bset1.reset(1); // Reset the bit at position 1
    bset1.flip(1); // Toggle the bit at position 1

    std::cout << "Modified bset1: " << bset1 << std::endl;

    // Count the number of set bits
    std::cout << "Number of set bits in bset2: " << bset2.count() << std::endl;

    // Check if any bit is set
    std::cout << "Any bit set in bset3? " << (bset3.any() ? "Yes" : "No") << std::endl;

    return 0;
}
```

## Commonly Used Methods

1. **Element Access**
   - `operator[]`: Accesses the bit at the specified position.
   ```cpp
   bitsetName[pos];
   ```

2. **Modifiers**
   - `set()`: Sets all bits to 1.
   - `set(pos, val)`: Sets the bit at the specified position to `val`.
   - `reset()`: Resets all bits to 0.
   - `reset(pos)`: Resets the bit at the specified position to 0.
   - `flip()`: Toggles all bits.
   - `flip(pos)`: Toggles the bit at the specified position.

3. **Operations**
   - `count()`: Returns the number of bits set to 1.
   - `size()`: Returns the number of bits in the bitset.
   - `any()`: Checks if any bit is set.
   - `none()`: Checks if no bit is set.
   - `all()`: Checks if all bits are set.
   - `to_string()`: Returns a string representation of the bitset.
   - `to_ulong()`: Converts the bitset to an unsigned long.

## Notes
- `std::bitset` is useful for efficient storage and manipulation of bits when the number of bits is known at compile-time.
- For dynamic bit manipulation, consider using `std::vector<bool>` or other bit manipulation libraries.

This provides a basic overview of `std::bitset` in C++. You can explore more advanced features and methods as you delve deeper into C++ programming.