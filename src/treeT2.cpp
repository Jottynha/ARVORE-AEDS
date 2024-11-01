#include "treeT2.hpp"

BST::BST() { // Constructor
    root = nullptr;
}

BST::~BST() { // Destructor
    deleteTree(root);
}

void BST::insert(const string& word) { // Inserção
    root = insert(root, word);
}

No* BST::insert(No* node, const string& word) {
    if (node == nullptr) {
        return new No(word);
    }
    if (word < node->word) {
        node->left = insert(node->left, word);
    } else if (word > node->word) {
        node->right = insert(node->right, word);
    }
    return node;
}

bool BST::search(const string& word) { // Busca
    return search(root, word);
}

bool BST::search(No* node, const string& word) {
    if (node == nullptr) {
        return false;
    }

    if (word == node->word) {
        return true;
    } else if (word < node->word) {
        return search(node->left, word);
    } else {
        return search(node->right, word);
    }
}

vector<string> BST::autocomplete(const string& prefix) { // Autocompletar
    vector<string> suggestions;
    autocomplete(root, prefix, suggestions);
    return suggestions;
}

void BST::autocomplete(No* node, const string& prefix, vector<string>& suggestions) {
    if (node == nullptr) {
        return;
    }

    if (node->word.substr(0, prefix.size()) == prefix) {
        suggestions.push_back(node->word);
    }

    if (prefix < node->word) {
        autocomplete(node->left, prefix, suggestions);
    }
    autocomplete(node->right, prefix, suggestions);
}

void BST::deleteTree(No* node) { // Deleta Árvore
    if (node == nullptr) {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void loadWordsFromFile(BST& tree, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        return;
    }
    string word;
    while (file >> word) {
        tree.insert(word);
    }
    file.close();
}
