#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{
    int codigo;
    char designacao[50];
    char fornecedor[50];
    float precoUnitario;
    int quantidadeMinima;
    int quantidadeStock;
};

// Creating a node
struct Node
{
    struct produto data;
    struct Node *next;
};

typedef struct Node *node; // Define node as pointer of data type struct LinkedList
typedef struct produto produto;

void menuPrincipal(node test);
void menuProduto(node test);
void inserirProduto(node test);
void listarProdutos(node test);
void procurarProduto(node test);
int obterCodigo(node test);

node createNode()
{
    node temp;                                // declare a node
    temp = (node)malloc(sizeof(struct Node)); // allocate memory using malloc()
    temp->next = NULL;                        // make next point to NULL
    return temp;                              // return the new node
}

node addNode(node head, produto value)
{
    node temp, p;        // declare two nodes temp and p
    temp = createNode(); // createNode will return a new node with data = value and next pointing to NULL.
    temp->data = value;  // add element's value to data part of node
    if (head == NULL)
    {
        head = temp; // when linked list is empty
    }
    else
    {
        p = head; // assign head to p
        while (p->next != NULL)
        {
            p = p->next; // traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = temp; // Point the previous last node to the new node created.
    }
    return head;
}

void main()
{
    menuPrincipal(createNode());
}

void menuPrincipal(node test)
{

    int choice;

    printf("*========================*\n");
    printf("| 1 - Gerir Produtos     |\n");
    printf("| 2 - Registar Movimento |\n");
    printf("| 3 - Consultar          |\n");
    printf("*========================*\n");
    fflush(stdin);

    //printf("1: Gerir Produtos\n2: Registar Movimento\n3: Consultar\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        menuProduto(test);
        break;
    case 2:

        break;
    case 3:

        break;
    default:
        printf("Insira uma escolha válida");
        menuPrincipal(test);
        break;
    }
}

void menuProduto(node test)
{
    int choice;

    printf("1: Inserir Produto\n2: Listar produtos\n3: Consultar Produto\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        inserirProduto(test);
        break;
    case 2:
        listarProdutos(test);
        break;
    case 3:

        break;
    default:
        printf("Insira uma escolha válida");
        menuPrincipal(test);
        break;
    }
}

void listarProdutos(node test)
{
    while (test != NULL)
    {
        printf("\n-------\n-> %s\n->%s\n-------\n", test->data.codigo, test->data.designacao);
        test = test->next;
    }
}

void inserirProduto(node test)
{
    int codigo;
    char designacao[50];
    char fornecedor[50];
    float precoUnitario;
    int quantidadeMinima;
    int quantidadeStock;

    produto Product;

    fflush(stdout);
    printf("Insira o nome do produto:\n");
    fflush(stdout);
    scanf("%s", designacao);

    printf("Insira o nome do fornecedor:\n");
    fflush(stdout);
    scanf("%s", fornecedor);

    printf("Insira o preco por unidade:\n");
    fflush(stdout);
    scanf("%f", &precoUnitario);

    printf("Insira a quantidade minima:\n");
    fflush(stdout);
    scanf("%d", &quantidadeMinima);

    printf("Insira a quantidade em stock:\n");
    fflush(stdout);
    scanf("%d", &quantidadeStock);

    produto Produto;

    strcpy(Produto.designacao, designacao);
    strcpy(Produto.fornecedor, fornecedor);
    Produto.precoUnitario = precoUnitario;
    Produto.quantidadeMinima = quantidadeMinima;
    Produto.quantidadeStock = quantidadeStock;
    // Produto.codigo = obterCodigo(test);

    menuPrincipal(addNode(test, Produto));
}

int obterCodigo(node test)
{
    int code = 0;

    if (test->next == NULL)
    {
        return 1;
    }
    else
    {
        while (test != NULL)
        {
            if (test->data.codigo > code)
            {
                code = test->data.codigo;
            }
            test = test->next;
        }
        return code;
    }
}
