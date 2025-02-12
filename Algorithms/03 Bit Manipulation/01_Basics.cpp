#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

#include <iostream>

namespace BitTricks {
    // Count of numbers x such that n + x = n ^ x
    int countValidX(int n) {
        int zeroBits = 0;
        while (n) {
            if ((n & 1) == 0) zeroBits++;
            n >>= 1;
        }
        return 1<<zeroBits;
    }
    
    // Check whether a number is even or odd
    bool isEven(int x) {
        return (x & 1) == 0;
    }

    // Clear the lowest set bit of x
    int clearLowestSetBit(int x) {
        return x & (x - 1);
    }

    // Extract the lowest set bit of x
    int extractLowestSetBit(int x) {
        return x & ~(x - 1);
    }

    // Clear all bits from LSB to i-th bit
    int clearLSBToI(int x, int i) {
        int mask = ~((1 << (i + 1)) - 1);
        return x & mask;
    }

    // Clear all bits from MSB to i-th bit
    int clearMSBToI(int x, int i) {
        int mask = (1 << i) - 1;
        return x & mask;
    }

    // Divide by 2
    int divideBy2(int x) {
        return x >> 1;
    }

    // Multiply by 2
    int multiplyBy2(int x) {
        return x << 1;
    }

    // Convert uppercase English alphabet to lowercase
    char toLowerCase(char ch) {
        return ch | ' ';
    }

    // Convert lowercase English alphabet to uppercase
    char toUpperCase(char ch) {
        return ch & '_';
    }

    // Count set bits in an integer
    int countSetBits(int x) {
        int count = 0;
        while (x) {
            x &= (x - 1);
            count++;
        }
        return count;
    }

    // Find log base 2 of a 32-bit integer
    int log2(int x) {
        int res = 0;
        while (x >>= 1)
            res++;
        return res;
    }

    // Check if a number is a power of 2
    bool isPowerOf2(int x) {
        return (x && !(x & (x - 1)));
    }

    // Find the last set bit
    int lastSetBit(int n) {
        return n & -n;
    }

    // Turn off k-th bit
    int turnOffKthBit(int n, int k) {
        return n & ~(1 << k);
    }

    // Turn on k-th bit
    int turnOnKthBit(int n, int k) {
        return n | (1 << k);
    }

    // Check if k-th bit is set
    bool isKthBitSet(int n, int k) {
        return ((n>>k) & 1);
    }

    // Toggle the k-th bit
    int toggleKthBit(int n, int k) {
        return n ^ (1 << k);
    }

    // Consecutive setBits
    int consecutivesetBits(int n) {
        return n & (n << 1);
    }
}

#endif // BIT_MANIPULATION_H
