#include "treeT1.hpp"


Node::Node(int val) : data(val), left(nullptr), right(nullptr) {}

Node* insert(Node* root, int data) {
    if (!root)
        return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

Node* remove(Node* root, int data) {
    if (!root) return root;

    if (data < root->data)
        root->left = remove(root->left, data);
    else if (data > root->data)
        root->right = remove(root->right, data);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp && temp->left)
            temp = temp->left;

        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }

    return root;
}

int calculateMaxLevel(Node* root) {
    if (!root)
        return 0;

    int leftLevel = calculateMaxLevel(root->left);
    int rightLevel = calculateMaxLevel(root->right);

    return 1 + max(leftLevel, rightLevel);
}

void findLongestPath(Node* root, vector<int>& path, vector<int>& longestPath) {
    if (!root)
        return;

    path.push_back(root->data);

    if (!root->left && !root->right) {
        if (path.size() > longestPath.size()) {
            longestPath = path;
        }
    }

    findLongestPath(root->left, path, longestPath);
    findLongestPath(root->right, path, longestPath);

    path.pop_back();
}

void displayMaxLevelAndPath(Node* root) {
    int maxLevel = calculateMaxLevel(root);
    cout << "Nível máximo (altura da árvore): " << maxLevel << endl;

    vector<int> path, longestPath;
    findLongestPath(root, path, longestPath);

    cout << "Caminho mais longo da raiz até a folha: ";
    for (int node : longestPath) {
        cout << node << " ";
    }
    cout << endl;
}

void compareTrees(Node* unbalancedTree, Node* balancedTree) {
    int maxLevelUnbalanced = calculateMaxLevel(unbalancedTree);
    int maxLevelBalanced = calculateMaxLevel(balancedTree);

    cout << "Comparação de níveis:\n";
    cout << "Árvore desbalanceada: Nível máximo = " << maxLevelUnbalanced << endl;
    cout << "Árvore mais equilibrada: Nível máximo = " << maxLevelBalanced << endl;

    if (maxLevelUnbalanced > maxLevelBalanced) {
        cout << "A árvore desbalanceada tem um nível maior, resultando em um custo maior de operações." << endl;
    } else {
        cout << "A árvore mais equilibrada tem um nível menor, otimizando o tempo de operação." << endl;
    }
}
