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

vector<string> generateRandomWords(int numWords) {
    vector<string> words;
    const string characters = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < numWords; i++) {
        string word;
        int wordLength = rand() % 5 + 3; // Tamanho da palavra entre 3 e 7
        for (int j = 0; j < wordLength; j++) {
            word += characters[rand() % characters.size()];
        }
        words.push_back(word);
    }
    return words;
}

void testBSTPerformance(int volume) {
    BST bst;
    vector<string> words = generateRandomWords(volume);
    
    // TEMPO DE INSERÇÃO
    auto start = high_resolution_clock::now();
    for (const auto& word : words) {
        bst.insert(word);
    }
    auto end = high_resolution_clock::now();
    auto insertionDuration = duration_cast<milliseconds>(end - start);
    cout << "Tempo de inserção para " << volume << " palavras: " 
         << insertionDuration.count() << " ms" << endl;

    // TEMPO DE BUSCA
    start = high_resolution_clock::now();
    for (const auto& word : words) {
        bst.search(word);
    }
    end = high_resolution_clock::now();
    auto searchDuration = duration_cast<milliseconds>(end - start);
    cout << "Tempo de busca para " << volume << " palavras: " 
         << searchDuration.count() << " ms" << endl;

    // TEMPO DE BUSCA (PALAVRAS INEXISTENTES)
    start = high_resolution_clock::now();
    for (int i = 0; i < 100; i++) { // Buscar 100 palavras que não existem
        string nonexistentWord = "nonexistent" + to_string(i);
        bst.search(nonexistentWord);
    }
    end = high_resolution_clock::now();
    auto searchNonexistentDuration = duration_cast<milliseconds>(end - start);
    cout << "Tempo de busca de palavras inexistentes: " 
         << searchNonexistentDuration.count() << " ms" << endl;
}