# ÁRVORE BINÁRIA


---

## Impacto do Desbalanceamento no Comprimento do Caminho

O desbalanceamento de uma árvore binária afeta diretamente o comprimento do caminho mais longo da raiz até uma folha. Esse caminho é o nível máximo da árvore (ou sua altura).

1. **Árvores Desbalanceadas**:
   - Em uma árvore desbalanceada, o comprimento do caminho mais longo pode crescer de forma desproporcional à quantidade de nós inseridos. Isso ocorre porque os nós são adicionados de forma sequencial em uma única direção, como no caso de uma árvore "torta" onde cada nó tem apenas um filho.
   - O resultado é uma árvore que se assemelha a uma lista encadeada, onde o nível máximo cresce linearmente com o número de nós. Para \(n\) nós, a altura máxima pode ser \(n-1\), o que implica um caminho longo e ineficiente, com complexidade de tempo \(O(n)\) para operações como busca.
   - Esse comportamento pode ser observado em uma árvore onde os nós são inseridos em ordem crescente ou decrescente (e.g., inserções 1, 2, 3, 4, 5...), criando uma estrutura desbalanceada.

2. **Árvores Equilibradas (Idealmente Balanceadas)**:
   - Em uma árvore balanceada, a altura máxima é minimizada, e o comprimento do caminho mais longo cresce de forma mais controlada, geralmente \(O(\log n)\), onde \(n\) é o número de nós.
   - Uma árvore binária idealmente balanceada distribui os nós de maneira uniforme entre seus subárvores, fazendo com que o nível máximo seja o menor possível para o número de nós existentes.
   - Em termos práticos, a altura de uma árvore balanceada com \(n\) nós é aproximadamente \(\log_2(n)\), o que garante que as operações de busca, inserção e remoção sejam feitas de maneira muito mais eficiente, em tempo \(O(\log n)\).

### Comparação dos Caminhos

- **Árvore Desbalanceada**: Como a árvore é tendenciosa para um lado, o caminho mais longo da raiz até a folha pode ser igual ao número de nós menos um. Para 5 nós, o caminho mais longo seria 4 (e.g., 1 -> 2 -> 3 -> 4 -> 5).
- **Árvore Balanceada**: Com os mesmos 5 nós, a altura da árvore será \( \log_2(5) \approx 2.3 \), arredondando para 3 níveis. Um caminho possível seria algo como 3 -> 1 -> 2 ou 3 -> 5 -> 4, mantendo o equilíbrio entre as subárvores.

### Efeitos no Desempenho

- **Tempo de Busca, Inserção e Remoção**:
   - Em uma árvore desbalanceada, essas operações tendem a ser mais custosas, já que precisam percorrer um caminho mais longo. O pior caso é \(O(n)\), o que é equivalente à eficiência de uma lista encadeada.
   - Em uma árvore balanceada, essas operações são muito mais eficientes, já que o caminho mais longo é significativamente menor, com complexidade \(O(\log n)\).

- **Custo de 39% de Depreciação**:
   - O desbalanceamento da árvore resulta em uma "depreciação" da eficiência conforme mais nós são adicionados. À medida que a altura da árvore cresce linearmente (em uma árvore desbalanceada), as operações tornam-se significativamente mais lentas. Esse aumento na altura pode gerar uma degradação de aproximadamente 39% no desempenho em comparação com uma árvore mais organizada e equilibrada.
   - A árvore balanceada, por sua vez, não sofre desse efeito com a mesma intensidade, já que sua altura cresce logaritmicamente, mantendo um desempenho aceitável conforme novos nós são inseridos.

 
