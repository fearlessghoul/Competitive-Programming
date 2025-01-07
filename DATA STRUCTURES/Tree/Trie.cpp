#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26]{}; // Array for 26 lowercase English letters
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

    // Helper function to delete a word
    bool deleteHelper(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        // If the last character of the word is being processed
        if (depth == word.size()) {
            if (node->isEndOfWord) {
                node->isEndOfWord = false;

                // If the node has no children, it can be deleted
                for (int i = 0; i < 26; ++i) {
                    if (node->children[i]) return false;
                }
                return true;
            }
            return false;
        }

        int index = word[depth] - 'a'; // Calculate the index for the current character
        if (node->children[index]) {
            bool shouldDelete = deleteHelper(node->children[index], word, depth + 1);

            // If true, delete the child node
            if (shouldDelete) {
                delete node->children[index];
                node->children[index] = nullptr;

                // Return true if the current node can also be deleted
                for (int i = 0; i < 26; ++i) {
                    if (node->children[i]) return false;
                }
                return !node->isEndOfWord;
            }
        }
        return false;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            int index = ch - 'a'; // Calculate the index for the current character
            if (!currentNode->children[index]) {
                currentNode->children[index] = new TrieNode();
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            int index = ch - 'a'; // Calculate the index for the current character
            if (!currentNode->children[index]) {
                return false;
            }
            currentNode = currentNode->children[index];
        }
        return currentNode && currentNode->isEndOfWord;
    }

    // Delete a word from the Trie
    void remove(const string& word) {
        deleteHelper(root, word, 0);
    }
};

int main() {
    Trie trie;

    trie.insert("hello");
    trie.insert("world");
    trie.insert("trie");
    trie.insert("hellos");
    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'world': " << (trie.search("world") ? "Found" : "Not Found") << endl;
    cout << "Search 'trie': " << (trie.search("trie") ? "Found" : "Not Found") << endl;

    trie.remove("hellos");
    cout << "Search 'hello' after deletion: " << (trie.search("hello") ? "Found" : "Not Found") << endl;

    return 0;
}
