#include "bits/stdc++.h"
using namespace std;
 
struct TrieNode {
    TrieNode* children[2];
    bool isEndOfWord;
    int count[2];
};
 
struct TrieNode* root;
 
struct TrieNode* getNewTrieNode() {
    struct TrieNode* newNode = new TrieNode;
    newNode->isEndOfWord = false;
    for(int i = 0; i < 2; i++) {
        newNode->children[i] = NULL;
        newNode->count[i] = 0;
    }
    return newNode;
}
 
void insertWord(string word) {
    struct TrieNode* current = root;
    char ch;
    int index = 0;
    for (int i = 0; i < word.length(); i++) {
        ch = word[i];
        if(ch == 'L')
            index = 0;
        else
            index = 1;
        if (current->children[index] == NULL) {
            struct TrieNode* newNode = getNewTrieNode();
            (current->children)[index] = newNode;
            (current->count)[index] = 1;
        }
        else {
            current->count[index] = (current->count)[index] + 1;
        }
        current = (current->children)[index];
    }
    current->isEndOfWord = true;
}
 
void countWords(vector<string>& words, vector<string>& prefixes) {
    root = getNewTrieNode();
    int n = words.size();
 
    for (int i = 0; i < n; i++) {
        insertWord(words[i]);
    }
 
    char ch;
    int wordCount = 0;
    string prefix;
    int index = 0;
    for(int j = 0; j < prefixes.size(); j++) {
        prefix = prefixes[j];
        wordCount = 0;
        struct TrieNode* current = root;
        for (int i = 0; prefix[i]; i++) {
            ch = prefix[i];
            if(ch == 'L')
                index = 0;
            else
                index = 1;
            if (current->children[index] == NULL) {
                wordCount = 0;
                break;
            }
            wordCount = (current->count)[index];
            current = (current->children)[index];
        }
        cout << wordCount << endl;
    }
}
 
int main() {
    int n, q;
    cin >> n >> q;
    vector<string> words(n), queries(q);
    string str;
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    countWords(words, queries);
    return 0;
}