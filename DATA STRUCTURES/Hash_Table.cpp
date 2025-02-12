#include <iostream>
using namespace std;

const int TABLE_SIZE = 100;  // Define the maximum size of the hash table
int hashTable[TABLE_SIZE];   // Array for direct mapping

// Insert key-value pair
void insert(int key, int value) {
    hashTable[key] = value;  // Store value at index 'key'
}

// Search for a key and return the value
int search(int key) {
    return hashTable[key];  // Return the value stored at index 'key'
}

int main() {
    // Initialize all values to 0 (or any default value)
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;  // -1 indicates no value stored

    // Insert key-value pairs
    insert(5, 100);
    insert(10, 200);
    insert(20, 300);

    // Search for values
    cout << "Value at key 5: " << search(5) << endl;
    cout << "Value at key 10: " << search(10) << endl;
    cout << "Value at key 15: " << search(15) << " (Not Found)" << endl;

    return 0;
}
