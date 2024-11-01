class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        if self.root is None:
            self.root = Node(value)
        else:
            self._insert(self.root, value)

    def _insert(self, current_node, value):
        if value < current_node.value:
            if current_node.left is None:
                current_node.left = Node(value)
            else:
                self._insert(current_node.left, value)
        elif value > current_node.value:
            if current_node.right is None:
                current_node.right = Node(value)
            else:
                self._insert(current_node.right, value)

    # Pre-order search with recursive call counting, including null
    def pre_order_search(self, value):
        interactions, path = self._pre_order_search(self.root, value, [], 0)
        return interactions, path

    def _pre_order_search(self, node, value, path, interactions):
        interactions += 1  # Contando a interação, mesmo quando cai em null
        if node is None:
            return interactions, path
        
        path.append(node.value)
        if node.value == value:
            return interactions, path
        
        # Chamadas recursivas para esquerda e direita
        interactions, path = self._pre_order_search(node.left, value, path, interactions)
        if node.value != value:
            interactions, path = self._pre_order_search(node.right, value, path, interactions)
        
        return interactions, path

    # In-order search with recursive call counting, including null
    def in_order_search(self, value):
        interactions, path = self._in_order_search(self.root, value, [], 0)
        return interactions, path

    def _in_order_search(self, node, value, path, interactions):
        interactions += 1  # Contando a interação, mesmo quando cai em null
        if node is None:
            return interactions, path
        
        # Chamadas recursivas para esquerda
        interactions, path = self._in_order_search(node.left, value, path, interactions)
        path.append(node.value)
        
        if node.value == value:
            return interactions, path
        
        # Chamadas recursivas para direita
        interactions, path = self._in_order_search(node.right, value, path, interactions)
        
        return interactions, path

    # Post-order search with recursive call counting, including null
    def post_order_search(self, value):
        interactions, path = self._post_order_search(self.root, value, [], 0)
        return interactions, path

    def _post_order_search(self, node, value, path, interactions):
        interactions += 1  # Contando a interação, mesmo quando cai em null
        if node is None:
            return interactions, path

        # Chamadas recursivas para esquerda e direita
        interactions, path = self._post_order_search(node.left, value, path, interactions)
        interactions, path = self._post_order_search(node.right, value, path, interactions)
        path.append(node.value)
        
        if node.value == value:
            return interactions, path
        
        return interactions, path

    # Level-order search (Breadth-first) with interaction counting
    def level_order_search(self, value):
        if self.root is None:
            return 0, []
        
        queue = [self.root]
        path = []
        interactions = 0
        
        while queue:
            node = queue.pop(0)
            interactions += 1  # Contando a interação ao visitar o nó
            path.append(node.value)
            
            if node.value == value:
                return interactions, path
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        return interactions, path

# Função para ler os inteiros de um arquivo txt
def read_integers_from_file(filename):
    with open(filename, 'r') as file:
        return [int(line.strip()) for line in file.readlines()]

# Função principal
def main():
    # Carregar os inteiros do arquivo
    filename = 'numeros.txt'  # Substitua pelo nome do arquivo correto
    numbers = read_integers_from_file(filename)

    # Criar a árvore binária e inserir os valores
    bst = BinarySearchTree()
    for number in numbers:
        bst.insert(number)

    # Solicitar valor a ser buscado
    search_value = int(input("Digite um número para buscar: "))

    # Pre-Order Search
    pre_order_interactions, pre_order_path = bst.pre_order_search(search_value)
    print("\nPré-ordem:")
    print(f"Caminho percorrido: {pre_order_path}")
    print(f"Número de interações: {pre_order_interactions}")

    # In-Order Search
    in_order_interactions, in_order_path = bst.in_order_search(search_value)
    print("\nEm ordem:")
    print(f"Caminho percorrido: {in_order_path}")
    print(f"Número de interações: {in_order_interactions}")

    # Post-Order Search
    post_order_interactions, post_order_path = bst.post_order_search(search_value)
    print("\nPós-ordem:")
    print(f"Caminho percorrido: {post_order_path}")
    print(f"Número de interações: {post_order_interactions}")

    # Level-Order Search
    level_order_interactions, level_order_path = bst.level_order_search(search_value)
    print("\nEm largura:")
    print(f"Caminho percorrido: {level_order_path}")
    print(f"Número de interações: {level_order_interactions}")

    # Análise de eficiência
    print("\nAnálise de Eficiência:")
    print(f"Pré-ordem: {pre_order_interactions} interações")
    print(f"Em ordem: {in_order_interactions} interações")
    print(f"Pós-ordem: {post_order_interactions} interações")
    print(f"Em largura: {level_order_interactions} interações")

if __name__ == '__main__':
    main()
