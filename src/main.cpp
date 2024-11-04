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
        cout << "\n[ MENU PROBLEMA 2: ]\n";
        cout << "1 - Inserir nó na árvore desbalanceada\n";
        cout << "2 - Remover nó da árvore desbalanceada\n";
        cout << "3 - Inserir nó na árvore equilibrada\n";
        cout << "4 - Remover nó da árvore equilibrada\n";
        cout << "5 - Comparar as duas árvores\n";
        cout << "6 - Sugerir rotações para a árvore desbalanceada\n";
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
            case '6':
                cout << "Sugestões de rotações para reduzir a profundidade da árvore desbalanceada:\n";
                sugerirRotacoes(unbalancedTree);
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
    srand(static_cast<unsigned int>(time(0))); // Para gerar números aleatórios
    vector<int> testVolumes = {100, 1000, 5000, 10000};
    ifstream file("dataset/words.txt");
    string word;

    int choice;
    do {
        
        cout << "\n[ MENU PROBLEMA 3: ]\n";
        cout << "1 - Buscar uma palavra\n";
        cout << "2 - Autocompletar\n";
        cout << "3 - Teste com Palavras Aleatórias\n";
        cout << "4 - Exibir Dicionário\n";
        cout << "5 - Voltar ao menu principal\n";
        cout << "Escolha uma opção: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string word;
                cout << "Digite a palavra para buscar: ";
                cin >> word;
                auto start = high_resolution_clock::now();
                if (tree.search(word)) {
                    cout << word << " foi encontrada no dicionário." << endl;
                } else {
                    cout << word << " não foi encontrada no dicionário." << endl;
                }
                auto end = high_resolution_clock::now();
                auto insertionDuration = duration_cast<milliseconds>(end - start);
                cout << "Tempo de busca para a palavra [" << word << "]:" << insertionDuration.count() << " ms" << endl;
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
                for (int volume : testVolumes) {
                    cout << "\nTestando volume de dados: " << volume << endl;
                    testBSTPerformance(volume);
                }
                break;
            case 4:
                if (!file.is_open()) {
                    cerr << "Erro ao abrir o arquivo do Dicionário " << endl;
                    return;
                }
                cout << "[ CONTEÚDO DO DICIONÁRIO ]: " << endl;
                while (file >> word) {
                    cout << word << endl; 
                }
                break;
            case 5:
                cout << "Voltando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida, tente novamente." << endl;
        }
    } while (choice != 5);
    file.close();
}

int main() {
    int escolha;

    while (true) {
        cout << "\n[ MENU PRINCIPAL: ]\n";
        cout << "1 - SAIR\n";
        cout << "2 - [PROBLEMA 2 (árvore com inteiro)]\n";
        cout << "3 - [PROBLEMA 3 (árvore com palavras)]\n";
        cout << "Digite sua escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                cout << "Saindo do programa...\n";
                return 0;
            case 2:
                executarProblema2();
                break;
            case 3:
                executarProblema3();
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    }

    return 0;
}
