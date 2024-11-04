#ifndef TREET1_HPP
#define TREET1_HPP

#include <iostream>
#include <vector>
#include <algorithm>  // Para max
#include <cstdlib>  // Para atoi

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val);
};

Node* insert(Node* root, int data); // INSERIR NÓ
Node* remove(Node* root, int data); // REMOVER NÓ
int calculateMaxLevel(Node* root);// CALCULAR NIVEL
//ENCONTRAR CAMINHO MAIS LONGO DA RAIZ A FOLHA MAIS LONGE
void findLongestPath(Node* root, vector<int>& path, vector<int>& longestPath);
void displayMaxLevelAndPath(Node* root);
void compareTrees(Node* unbalancedTree, Node* balancedTree); // COMPARAR ÁRVORES
void sugerirRotacoes(Node* node);

#endif
