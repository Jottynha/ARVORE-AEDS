
    
<div align="center">

# ÁRVORE BINÁRIA E SUAS IMPLICAÇÕES 🌳

![Static Badge](https://img.shields.io/badge/C%2B%2B-blue?style=flat&logo=C%2B%2B)
![Static Badge](https://img.shields.io/badge/Ubuntu-orange?style=flat&logo=ubuntu)

</div>

<p align="justify">
Esse é o repositório de um trabalho individual, proposto em sala de aula, da disciplina de Algoritmos e Estruturas de Dados II, ministrada no Campus Divinópolis do CEFET-MG pelo professor Michel Pires Da Silva. Aqui, desenvolvi arquivos que manipulam diferentes modelos da estrutura de dados de árvores para discutir as questões propostas pelo professor.
</p>

## Introdução 📝
<div align="center">
   
![TREE](https://joaoarthurbm.github.io/eda/posts/bst/bst1.png)

<p>Este documento aborda uma série de desafios práticos e teóricos relacionados à manipulação e análise de árvores binárias. Cada problema foi projetado para explorar conceitos fundamentais, como inserção, remoção, pesquisa e caminhamento em árvores binárias de busca, além de oferecer uma compreensão profunda sobre a estrutura e o funcionamento dessas árvores. Os problemas incluem a construção de árvores a partir de conjuntos de dados, análise do impacto das remoções na estrutura da árvore, e a implementação de funções para calcular a profundidade máxima e sugerir otimizações. Além disso, o desenvolvimento de um dicionário eletrônico baseado em árvores binárias de busca será discutido, com foco em desempenho e eficiência. Através desses exercícios, os usuários poderão aprimorar suas habilidades em estruturas de dados e algoritmos, além de compreender melhor as aplicações práticas das árvores binárias em programação.</p>

<h3>Problema 1: Construção e Análise de Árvores Binárias</h3>
<p>Os participantes devem construir árvores binárias de busca a partir de conjuntos de dados específicos, desenhando a estrutura da árvore após cada inserção. Além disso, será realizada a remoção de elementos, permitindo a discussão sobre o impacto estrutural na árvore e os diferentes casos de remoção, como folhas e nós com um ou dois filhos. Os participantes também deverão utilizar diferentes métodos de caminhamento para localizar elementos, analisando a eficiência de cada abordagem.</p>

<h3>Problema 2: Cálculo do Nível Máximo de Árvores Binárias</h3>
<p>Este exercício requer a implementação de uma função que calcule o nível máximo de uma árvore binária, proporcionando visualização interativa a cada nova inserção ou remoção. Os participantes deverão analisar o crescimento da árvore em termos de desbalanceamento e como isso afeta o comprimento do caminho da raiz até a folha mais distante. Além disso, o desafio inclui a proposta de rotações para otimizar a profundidade da árvore.</p>

<h3>Problema 3: Desenvolvimento de um Dicionário Eletrônico</h3>
<p>Os participantes devem projetar uma estrutura de dados eficiente para um dicionário eletrônico, que permita buscas rápidas e autocompletar sugestões conforme o usuário digita. Será necessário discutir as limitações das árvores binárias de busca em termos de desbalanceamento e propor otimizações, como o uso de árvores balanceadas, para garantir eficiência mesmo com grandes volumes de dados. Testes deverão ser elaborados para simular o uso do dicionário, avaliando o tempo de resposta para diferentes volumes de dados.</p>

</div>

## Problema 2: Impacto do Desbalanceamento no Comprimento do Caminho 🛠️

O desbalanceamento de uma árvore binária afeta diretamente o comprimento do caminho mais longo da raiz até uma folha. Esse caminho é o nível máximo da árvore (ou sua altura).

1. **Árvores Desbalanceadas**:
   - Em uma árvore desbalanceada, o comprimento do caminho mais longo pode crescer de forma desproporcional à quantidade de nós inseridos. Isso ocorre porque os nós são adicionados de forma sequencial em uma única direção, como no caso de uma árvore "torta" onde cada nó tem apenas um filho.
   - O resultado é uma árvore que se assemelha a uma lista encadeada, onde o nível máximo cresce linearmente com o número de nós. Para (n) nós, a altura máxima pode ser (n-1), o que implica um caminho longo e ineficiente, com complexidade de tempo O(n) para operações como busca.
   - Esse comportamento pode ser observado em uma árvore onde os nós são inseridos em ordem crescente ou decrescente, criando uma estrutura desbalanceada.

2. **Árvores Equilibradas (Idealmente Balanceadas)**:
   - Em uma árvore balanceada, a altura máxima é minimizada, e o comprimento do caminho mais longo cresce de forma mais controlada, geralmente O(log n), onde n é o número de nós.
   - Uma árvore binária idealmente balanceada distribui os nós de maneira uniforme entre seus subárvores, fazendo com que o nível máximo seja o menor possível para o número de nós existentes.
   - Em termos práticos, a altura de uma árvore balanceada com n nós é aproximadamente log_2(n), o que garante que as operações de busca, inserção e remoção sejam feitas de maneira muito mais eficiente, em tempo O(log n).

### Comparação dos Caminhos

- **Árvore Desbalanceada**: Como a árvore é tendenciosa para um lado, o caminho mais longo da raiz até a folha pode ser igual ao número de nós menos um. Para 5 nós, o caminho mais longo seria 4: (1 -> 2 -> 3 -> 4 -> 5).
- **Árvore Balanceada**: Com os mesmos 5 nós, a altura da árvore será log_2(5) = 2.3, arredondando para 3 níveis. Um caminho possível seria algo como 3 -> 1 -> 2 ou 3 -> 5 -> 4, mantendo o equilíbrio entre as subárvores.

### Efeitos no Desempenho

- **Tempo de Busca, Inserção e Remoção**:
   - Em uma árvore desbalanceada, essas operações tendem a ser mais custosas, já que precisam percorrer um caminho mais longo. O pior caso é O(n), o que é equivalente à eficiência de uma lista encadeada.
   - Em uma árvore balanceada, essas operações são muito mais eficientes, já que o caminho mais longo é significativamente menor, com complexidade O(log n).

- **Custo de 39% de Depreciação**:
   - O desbalanceamento da árvore resulta em uma "depreciação" da eficiência conforme mais nós são adicionados. À medida que a altura da árvore cresce linearmente (em uma árvore desbalanceada), as operações tornam-se significativamente mais lentas. Esse aumento na altura pode gerar uma degradação de aproximadamente 39% no desempenho em comparação com uma árvore mais organizada e equilibrada.
   - A árvore balanceada, por sua vez, não sofre desse efeito com a mesma intensidade, já que sua altura cresce logaritmicamente, mantendo um desempenho aceitável conforme novos nós são inseridos.
   - 
---

## Problema 3: Otimização de Árvores Binárias de Busca 🛠️

As árvores binárias de busca (BSTs) são estruturas de dados eficientes para armazenamento e pesquisa de elementos. No entanto, à medida que novas palavras são inseridas, a árvore pode se tornar desbalanceada, resultando em operações com complexidade linear O(n) no pior caso. Para mitigar esse problema, diversas técnicas de otimização podem ser implementadas. Abaixo estão algumas dessas técnicas, incluindo o uso de árvores balanceadas, além de métodos de compactação e armazenamento que minimizam o uso de memória.

<body>
    <h2>1. Estrutura de Dados e Funcionamento do Autocompletar</h2>
    <p>A árvore binária de busca organiza as palavras de forma que cada nó possui um valor (neste caso, uma palavra), com o nó à esquerda sendo menor e o nó à direita sendo maior. O autocompletar funciona da seguinte maneira:</p>
    <ul>
        <li>Quando um prefixo é fornecido, a árvore é percorrida a partir da raiz até encontrar a posição onde o prefixo poderia ser inserido.</li>
        <li>A busca é feita para encontrar o primeiro nó que comece com o prefixo desejado.</li>
        <li>Após encontrar o nó correspondente, a árvore é percorrida em ordem para coletar todas as palavras que começam com o prefixo.</li>
    </ul>
    <h2>2. Análise de Complexidade</h2>
    <p>A eficiência do autocompletar em uma BST é influenciada pela altura da árvore, que pode variar dependendo da forma como os dados são inseridos. Vamos analisar as seguintes situações:</p>
    <h3>a. Melhor Caso</h3>
    <p><strong>Árvore Balanceada:</strong> Quando a árvore está balanceada (ex: AVL ou Red-Black), a altura da árvore é <code>O(log n)</code>, onde <code>n</code> é o número de palavras.</p>
    <p><strong>Tempo de Busca:</strong> O tempo de busca para encontrar o nó inicial com o prefixo é <code>O(log n)</code> e a coleta de palavras que começam com o prefixo é <code>O(k)</code>, onde <code>k</code> é o número de palavras que atendem ao critério.</p>
    <h3>b. Pior Caso</h3>
    <p><strong>Árvore Desbalanceada:</strong> Se a árvore se tornar desbalanceada (ex: inserindo palavras em ordem crescente), a altura pode chegar a <code>O(n)</code>.</p>
    <p><strong>Tempo de Busca:</strong> Nesse caso, o tempo de busca para encontrar o nó inicial com o prefixo se torna <code>O(n)</code> e a coleta de palavras que começam com o prefixo continua em <code>O(k)</code>.</p>
    <h2>3. Análise Comparativa</h2>
    <h3>a. Tamanho do Dicionário e Tempo de Busca</h3>
    <table>
        <thead>
            <tr>
                <th>Tamanho do Dicionário (<code>n</code>)</th>
                <th>Melhor Caso (<code>O(log n)</code>)</th>
                <th>Pior Caso (<code>O(n)</code>)</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>100</td>
                <td>~7</td>
                <td>~100</td>
            </tr>
            <tr>
                <td>1.000</td>
                <td>~10</td>
                <td>~1.000</td>
            </tr>
            <tr>
                <td>10.000</td>
                <td>~14</td>
                <td>~10.000</td>
            </tr>
            <tr>
                <td>100.000</td>
                <td>~17</td>
                <td>~100.000</td>
            </tr>
            <tr>
                <td>1.000.000</td>
                <td>~20</td>
                <td>~1.000.000</td>
            </tr>
        </tbody>
    </table>
    <ul>
        <li><strong>Desempenho em Grande Escala:</strong> Para grandes volumes de dados, a eficiência da árvore binária de busca pode ser comprometida se a árvore não for balanceada. Estruturas de dados mais sofisticadas, como árvores AVL ou Red-Black, podem ser preferíveis para garantir um desempenho consistente.</li>
        <li><strong>Impacto do Balanceamento:</strong> A implementação de técnicas de balanceamento é crucial em aplicações onde o desempenho do autocompletar é essencial, pois a experiência do usuário pode ser severamente impactada por tempos de resposta lentos.</li>
        <li><strong>Alternativas:</strong> Outras estruturas de dados, como tries (árvores prefixadas), podem oferecer desempenho superior para operações de autocompletar, especialmente em casos onde o volume de dados é muito grande e onde o prefixo é frequentemente buscado.</li>
    </ul>


### Árvores AVL

As **árvores AVL** são um tipo de árvore binária de busca que mantém um equilíbrio estrito. A diferença de altura entre as subárvores esquerda e direita de qualquer nó é, no máximo, 1. Essa propriedade garante que as operações de busca, inserção e remoção sejam realizadas em tempo O(log n).

- **Rotação**: Quando uma inserção ou remoção causa um desbalanceamento, a árvore AVL aplica rotações (simples ou duplas) para restaurar o equilíbrio.
- **Uso**: Ideal para aplicações onde as operações de busca são frequentes e as inserções/remoções são menos comuns, pois o custo de manter o balanceamento pode ser alto em cenários de alta inserção.

### Árvores Rubro-Negra

As **árvores rubro-negras** são outra forma de árvore balanceada que mantém propriedades específicas:

- Cada nó é colorido de vermelho ou preto, e a árvore respeita regras de coloração que garantem um caminho mais curto da raiz até as folhas.
- Assim como as AVL, as operações de busca, inserção e remoção também são realizadas em tempo O(log n).
- **Flexibilidade**: Elas são geralmente mais eficientes que as AVL em cenários onde há muitas inserções e remoções, pois permitem um maior fator de desbalanceamento.

### Métodos de Compactação e Armazenamento

Além de manter o balanceamento, é importante considerar o uso eficiente da memória. Aqui estão algumas técnicas que podem ser aplicadas:

- **Representação Compacta**: Utilize estruturas de dados como tabelas de hash ou tries, que podem oferecer uma compactação intrínseca de palavras, especialmente para conjuntos de dados que compartilham prefixos comuns.
- **Codificação**: Empregue técnicas de codificação como Huffman ou LZW para armazenar palavras de forma compacta, reduzindo o uso de memória ao evitar a duplicação de informações.
- **Árvores Persistentes**: Permitem manter versões anteriores da árvore após cada operação de modificação. Essa abordagem é útil em cenários onde o histórico das mudanças é necessário e pode ajudar a economizar espaço, permitindo acesso eficiente a diferentes versões de dados.
- **Armazenamento em Disco**: Para conjuntos de dados muito grandes, considere o uso de estruturas como árvores B ou B+ que são otimizadas para acesso em disco. Elas minimizam o número de acessos a disco ao armazenar múltiplos valores em cada nó.
- **Alocação de Memória Dinâmica**: Utilize estruturas de alocação de memória como pools para reduzir a sobrecarga de alocação e liberação de memória, garantindo que o gerenciamento de memória seja eficiente e rápido.

A utilização de árvores balanceadas, como AVL e rubro-negras, é uma abordagem eficaz para garantir a eficiência de operações em árvores binárias de busca, mesmo quando grandes volumes de dados são inseridos. Além disso, técnicas de compactação e armazenamento, como representações compactas e estruturas de dados externas, podem ajudar a minimizar o uso de memória sem comprometer o desempenho. Implementar essas estratégias pode resultar em um sistema de armazenamento de dados mais robusto e eficiente, adequado para aplicações em grande escala.

---
 
## Compilação e Execução

 Especificações da máquina em que o código foi rodado:
  * Processador Intel Celeron N4020;
  * Sistema Operacional Ubuntu 22.04.01;
  * 4 GB de RAM.
* | Comando                |  Função                                                                                           |                     
  | -----------------------| ------------------------------------------------------------------------------------------------- |
  |  `make clean`          | Apaga a última compilação realizada contida na pasta build.                                       |
  |  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build.          |
  |  `make run`            | Executa o programa da pasta build após a realização da compilação.                                |

---

## Integrantes:

**João Pedro Rodrigues Silva**  
[![Static Badge](https://img.shields.io/badge/%7C%20Jottynha-black?style=flat-square&logo=github)](https://github.com/Jottynha)
[![Static Badge](https://img.shields.io/badge/%7C%20jprs1308%40gmail.com%20-black?style=flat-square&logo=gmail)](mailto:jprs1308@gmail.com)

___

<!---
✉️ jprs1308@gmail.com (**João Pedro Rodrigues Silva**)
--->
