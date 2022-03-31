#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{
    double codigo;
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
void verProdutos(node test);

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

    printf("1: Gerir Produtos\n2: Registar Movimento\n3: Consultar\n");

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

    printf("1: Inserir Produto\n2: Ver produtos\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        inserirProduto(test);
        break;
    case 2:
        verProdutos(test);
        break;
    default:
        printf("Insira uma escolha válida");
        menuPrincipal(test);
        break;
    }
}

void verProdutos(node test)
{
}

void inserirProduto(node test)
{
    double codigo;
    char designacao[50];
    char fornecedor[50];
    float precoUnitario;
    int quantidadeMinima;
    int quantidadeStock;

    produto Product;

    printf("Insira o nome do produto:\n");
    gets(designacao);

    printf("Insira o nome do fornecedor:\n");
    gets(fornecedor);

    produto Produto;

    strcpy(Produto.designacao, designacao);
    strcpy(Produto.fornecedor, fornecedor);


    addNode(test, Product);

    node p;
    p = test;
    while (p != NULL)
    {
        printf("%s ", p->data.designacao);
        p = p->next;
    }
}
