// struct produto
// {
//     int codigo;
//     char designacao[50];
//     char fornecedor[50];
//     float precoUnitario;
//     int quantidadeMinima;
//     int quantidadeStock;
// };

// struct NodeProdutos
// {
//     struct produto data;
//     struct NodeProdutos *next;
// };

// typedef struct NodeProdutos *node; // Define node as pointer of data type struct LinkedList
// typedef struct produto produto;

node createNode();
node addNode(node head, produto value);
void inserirProduto(node test, nodeM movimentos);
void listarProdutos(node test, nodeM movimentos);
void procurarProdutoDesignacao(node test, nodeM movimentos);
void editarProduto(node test, nodeM movimentos);
int obterCodigo(node test, nodeM movimentos);
int existeProduto(node test, char produto[]);
node remover(node test, char designacao[]);
void removerProduto(node test, nodeM movimentos);
void listarProdutosPorQtdMinStock(node test, nodeM movimentos);
node procurarNode(node test, char des[100]);