#include "tree.hpp"

using namespace std;

int main() {
    Node* unbalancedTree = nullptr;
    Node* balancedTree = nullptr;
    // Inserções para gerar uma árvore desbalanceada (inserindo de forma crescente)
    vector<int> unbalancedInsertions = {1, 2, 3, 4, 5};
    for (int data : unbalancedInsertions) {
        unbalancedTree = insert(unbalancedTree, data);
    }
    // Inserções para gerar uma árvore mais equilibrada (inserindo valores de forma variada)
    vector<int> balancedInsertions = {3, 1, 5, 2, 4};
    for (int data : balancedInsertions) {
        balancedTree = insert(balancedTree, data);
    }
    cout << "Árvore desbalanceada:\n";
    displayMaxLevelAndPath(unbalancedTree);

    cout << "\nÁrvore mais equilibrada:\n";
    displayMaxLevelAndPath(balancedTree);

    cout << "\nComparação de árvores:\n";
    compareTrees(unbalancedTree, balancedTree);

    // Menu interativo
    char choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1 - Inserir nó na árvore desbalanceada\n";
        cout << "2 - Remover nó da árvore desbalanceada\n";
        cout << "3 - Inserir nó na árvore equilibrada\n";
        cout << "4 - Remover nó da árvore equilibrada\n";
        cout << "5 - Comparar as duas árvores\n";
        cout << "0 - Sair\n";
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
                cout << "Nó inserido na árvore desbalanceada.\n";
                displayMaxLevelAndPath(unbalancedTree);
                break;
            case '2':
                cout << "Digite o valor para remover da árvore desbalanceada: ";
                cin >> value;
                unbalancedTree = remove(unbalancedTree, value);
                cout << "Nó removido da árvore desbalanceada.\n";
                displayMaxLevelAndPath(unbalancedTree);
                break;
            case '3':
                cout << "Digite o valor para inserir na árvore equilibrada: ";
                cin >> value;
                balancedTree = insert(balancedTree, value);
                cout << "Nó inserido na árvore equilibrada.\n";
                displayMaxLevelAndPath(balancedTree);
                break;
            case '4':
                cout << "Digite o valor para remover da árvore equilibrada: ";
                cin >> value;
                balancedTree = remove(balancedTree, value);
                cout << "Nó removido da árvore equilibrada.\n";
                displayMaxLevelAndPath(balancedTree);
                break;
            case '5':
                cout << "Comparando as duas árvores...\n";
                compareTrees(unbalancedTree, balancedTree);
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }
    cout << "Programa encerrado.\n";
    return 0;
}

