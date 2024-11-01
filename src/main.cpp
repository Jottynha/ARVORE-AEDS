#include <iostream>
#include "treeT1.hpp"  // Header do Problema 2 (estrutura Node)
#include "treeT2.hpp"  // Header do Problema 3 (estrutura No)

using namespace std;

void executarProblema2() {
    Node* unbalancedTree = nullptr;
    Node* balancedTree = nullptr;

    vector<int> unbalancedInsertions = {1, 2, 3, 4, 5};
    for (int data : unbalancedInsertions) {
        unbalancedTree = insert(unbalancedTree, data);
    }

    vector<int> balancedInsertions = {3, 1, 5, 2, 4};
    for (int data : balancedInsertions) {
        balancedTree = insert(balancedTree, data);
    }

    cout << "Árvore desbalanceada:\n";
    displayMaxLevelAndPath(unbalancedTree);

    cout << "\nÁrvore mais equilibrada:\n";
    displayMaxLevelAndPath(balancedTree);

    char choice;
    while (true) {
        cout << "\nMenu Problema 2:\n";
        cout << "1 - Inserir nó na árvore desbalanceada\n";
        cout << "2 - Remover nó da árvore desbalanceada\n";
        cout << "3 - Inserir nó na árvore equilibrada\n";
        cout << "4 - Remover nó da árvore equilibrada\n";
        cout << "5 - Comparar as duas árvores\n";
        cout << "0 - Voltar ao menu principal\n";
        cout << "Escolha uma opção: ";
        cin >> choice;

        if (choice == '0') {
            break;
        }
        
        int value;
        switch (choice) {
            case '1':
                cout << "Digite o valor para inserir na árvore desbalanceada: ";
                cin >> value;
                unbalancedTree = insert(unbalancedTree, value);
                displayMaxLevelAndPath(unbalancedTree);
                break;
            case '2':
                cout << "Digite o valor para remover da árvore desbalanceada: ";
                cin >> value;
                unbalancedTree = remove(unbalancedTree, value);
                displayMaxLevelAndPath(unbalancedTree);
                break;
            case '3':
                cout << "Digite o valor para inserir na árvore equilibrada: ";
                cin >> value;
                balancedTree = insert(balancedTree, value);
                displayMaxLevelAndPath(balancedTree);
                break;
            case '4':
                cout << "Digite o valor para remover da árvore equilibrada: ";
                cin >> value;
                balancedTree = remove(balancedTree, value);
                displayMaxLevelAndPath(balancedTree);
                break;
            case '5':
                compareTrees(unbalancedTree, balancedTree);
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }
}

void executarProblema3() {
    BST tree;
    loadWordsFromFile(tree, "dataset/words.txt");

    int choice;
    do {
        cout << "\nMenu Problema 3:\n";
        cout << "1 - Buscar uma palavra\n";
        cout << "2 - Autocompletar\n";
        cout << "3 - Voltar ao menu principal\n";
        cout << "Escolha uma opção: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string word;
                cout << "Digite a palavra para buscar: ";
                cin >> word;
                if (tree.search(word)) {
                    cout << word << " foi encontrada no dicionário." << endl;
                } else {
                    cout << word << " não foi encontrada no dicionário." << endl;
                }
                break;
            }
            case 2: {
                string prefix;
                cout << "Digite o prefixo para autocompletar: ";
                cin >> prefix;
                vector<string> suggestions = tree.autocomplete(prefix);
                if (suggestions.empty()) {
                    cout << "Nenhuma sugestão encontrada." << endl;
                } else {
                    cout << "Sugestões para o prefixo \"" << prefix << "\":" << endl;
                    for (const auto& suggestion : suggestions) {
                        cout << suggestion << endl;
                    }
                }
                break;
            }
            case 3:
                cout << "Voltando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida, tente novamente." << endl;
        }
    } while (choice != 3);
}

int main() {
    int escolha;

    while (true) {
        cout << "\nMenu Principal:\n";
        cout << "1 - Problema 2 (árvore com Node)\n";
        cout << "2 - Problema 3 (árvore com No)\n";
        cout << "0 - Sair\n";
        cout << "Digite sua escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                executarProblema2();
                break;
            case 2:
                executarProblema3();
                break;
            case 0:
                cout << "Saindo do programa...\n";
                return 0;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    }

    return 0;
}
