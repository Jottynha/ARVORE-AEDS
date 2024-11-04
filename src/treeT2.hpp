#ifndef TREET2_HPP
#define TREET2_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono> 

using namespace std::chrono;
using namespace std;

struct No {  // Renomeado de Node para No
    string word;
    No* left;
    No* right;

    No(string w) : word(w), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST();
    ~BST();
    
    void insert(const string& word);
    bool search(const string& word);
    vector<string> autocomplete(const string& prefix);

private:
    No* root;

    No* insert(No* node, const string& word);
    bool search(No* node, const string& word);
    void autocomplete(No* node, const string& prefix, vector<string>& suggestions);
    void deleteTree(No* node);
};

void loadWordsFromFile(BST& tree, const string& filename);
vector<string> generateRandomWords(int numWords);
void testBSTPerformance(int volume) ;

#endif
