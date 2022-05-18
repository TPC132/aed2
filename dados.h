#ifndef dados_h
#define dados_h
 
struct movimento
{
    char produto[50];
    int **data;
    bool entrada;
    int quantidade;
};

struct NodeMovimentos
{
    struct movimento data;
    struct NodeMovimentos *next;
};

typedef struct NodeMovimentos *nodeM; // Define node as pointer of data type struct LinkedList
typedef struct movimento movimento;

struct produto
{
    int codigo;
    char designacao[50];
    char fornecedor[50];
    float precoUnitario;
    int quantidadeMinima;
    int quantidadeStock;
};

struct NodeProdutos
{
    struct produto data;
    struct NodeProdutos *next;
};

typedef struct NodeProdutos *node; // Define node as pointer of data type struct LinkedList
typedef struct produto produto;
 
#endif