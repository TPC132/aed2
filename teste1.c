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
void procurarProdutoDesignacao(node test);
int obterCodigo(node test);
void voltar(node test);
void editarProduto(node test);
void menuEditarProduto(node test, node selected);
void menuListarProdutos(node test);

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
    temp->next = NULL;

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
    node startNode = NULL;
    menuPrincipal(startNode);
}

void menuPrincipal(node test)
{

    int choice;

    printf("\n");
    printf("*========================*\n");
    printf("| 1 - Gerir Produtos     |\n");
    printf("| 2 - Registar Movimento |\n");
    printf("| 3 - Consultar          |\n");
    printf("*========================*\n");
    printf("\n-> ");
    fflush(stdin);

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        menuProduto(test);
        break;
    case 2:
        if (test != NULL)
        {
            printf("Something");
        }
        else if (test == NULL)
        {
            printf("Bulldog");
        }
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

    printf("\n");
    printf("*========================*\n");
    printf("| 1 - Inserir Produto    |\n");
    printf("| 2 - Editar Produto     |\n");
    printf("| 3 - Consultar Produto  |\n");
    printf("| 4 - Remover Produto    |\n");
    printf("| 5 - Listar Produtos    |\n");
    printf("*========================*\n");
    fflush(stdin);
    printf("\n-> ");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        inserirProduto(test);
        break;
    case 2:
        editarProduto(test);
        break;
    case 3:
        procurarProdutoDesignacao(test);
        break;
    case 4:

        break;
    case 5:
        menuListarProdutos(test);
        break;
    default:
        printf("Insira uma escolha válida");
        menuPrincipal(test);
        break;
    }
}

void listarProdutos(node test)
{
    int counter = 0;
    node link = test;
    while (link != NULL)
    {
        ++counter;
        printf("\n-------\n-> %d\n-> %s\n-------\n", link->data.codigo, link->data.designacao);
        link = link->next;
    }
    printf("\n%d", counter);
    menuPrincipal(test);
}

void listarProdutosPorFornecedor(node test)
{
    int counter = 0;
    char nome[100];
    node link = test;

    printf("\n");
    printf("Insira o nome do fornecedor:");
    printf("\n");
    printf("\n");
    printf("-> ");
    fflush(stdout);
    scanf("%s", nome);

    while (link != NULL)
    {
        if (!strcmp(link->data.fornecedor, nome))
        {
            ++counter;
            printf("\n-------\n-> %d\n-> %s\n-------\n", link->data.codigo, link->data.designacao);
        }
        link = link->next;
    }
    printf("\n%d", counter);
    menuPrincipal(test);
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
    Produto.codigo = obterCodigo(test);

    node link = addNode(test, Produto);
    menuPrincipal(link);
}

node procurarNode(node test, char des[100])
{
    int counter = 0;
    char oremos[100];
    char senhor[100];

    node list = test;

    while (list != NULL)
    {
        ++counter;

        if (!strcmp(list->data.designacao, des))
        {
            return list;
        }
        list = list->next;
    }
    return NULL;
}

void procurarProdutoDesignacao(node test)
{

    node link;
    char search[100];
    printf("Introduza a designacao do produto \n");
    scanf("%s", search);
    link = procurarNode(test, search);

    if (link == NULL)
    {
        printf("Nao foram encontrados produtos com a designacao %s", search);
        voltar(test);
    }
    else
    {
        printf("\n");
        printf("Produto: ");
        printf("%s\n", link->data.designacao);
        printf("Codigo: ");
        printf("%d\n", link->data.codigo);
        printf("Fornecedor: ");
        printf("%s\n", link->data.fornecedor);
        printf("Preco por Unidade: ");
        printf("%f\n", link->data.precoUnitario);
        printf("Quantidade Minima: ");
        printf("%d\n", link->data.quantidadeMinima);
        printf("Quantidade em Stock: ");
        printf("%d\n", link->data.quantidadeStock);
        voltar(test);
    }
}

int obterCodigo(node test)
{
    int code = 0;

    if (test == NULL)
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
        return code + 1;
    }
}

void voltar(node test){
    int selection;
    printf("\n");
    printf("\nSelecione 1 para voltar para o menu principal\n");
    printf("\n");
    printf("-> ");
    scanf("%d", &selection);

    if (selection == 1)
    {
        menuPrincipal(test);
    }
}

void editarProduto(node test){

    char nome[100];

    printf("\nInsira o nome do produto que pretende editar:\n");
    printf("\n");
    scanf("%s", nome);
    printf("\n");
    menuEditarProduto(test, procurarNode(test, nome));

}

void menuEditarProduto(node test, node selected)
{

    int choice;
    char nome[100];
    int quantidade;
    float preco;

    printf("\n");
    printf("*=================================*\n");
    printf("| 1 - Editar Designacao           |\n");
    printf("| 2 - Editar Fornecedor           |\n");
    printf("| 3 - Editar Preco por unidade    |\n");
    printf("| 4 - Editar  Quantidade Minima   |\n");
    printf("| 5 - Editar Quantidade em Stock  |\n");
    printf("*=================================*\n");
    fflush(stdin);
    printf("\n-> ");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\n");
        printf("insira a nova designacao:");
        printf("\n");
        printf("-> ");
        scanf("%s", nome);
        strcpy(selected->data.designacao, nome);
        printf("\n");
        printf("Alteracoes efetuadas com sucesso!");
        printf("\n");
        menuProduto(test);
        break;
    case 2:
        printf("\n");
        printf("insira o novo fornecedor:");
        printf("\n");
        printf("-> ");
        scanf("%s", nome);
        strcpy(selected->data.fornecedor, nome);
        printf("\n");
        printf("Alteracoes efetuadas com sucesso!");
        printf("\n");
        menuProduto(test);
        break;
    case 3:
        printf("\n");
        printf("insira o novo preco por unidade:");
        printf("\n");
        printf("-> ");
        scanf("%f", &preco);
        selected->data.precoUnitario = preco;
        printf("\n");
        printf("Alteracoes efetuadas com sucesso!");
        printf("\n");
        menuProduto(test);
        break;
    case 4:
        printf("\n");
        printf("insira a nova quantidade minima:");
        printf("\n");
        printf("-> ");
        scanf("%d", &quantidade);
        selected->data.quantidadeMinima = quantidade;
        printf("\n");
        printf("Alteracoes efetuadas com sucesso!");
        printf("\n");
        menuProduto(test);
        break;
    case 5:
        printf("\n");
        printf("insira a nova quantidade em stock:");
        printf("\n");
        printf("-> ");
        scanf("%d", &quantidade);
        selected->data.quantidadeStock = quantidade;
        printf("\n");
        printf("Alteracoes efetuadas com sucesso!");
        printf("\n");
        menuProduto(test);
        break;
    default:
        printf("Insira uma escolha válida");
        menuPrincipal(test);
        break;
    }
}

void menuListarProdutos(node test)
{
    int choice;

    printf("\n");
    printf("*================================================================================*\n");
    printf("| 1 - Listar Todos os Produtos                                                   |\n");
    printf("| 2 - Listar produtos por Fornecedor                                             |\n");
    printf("| 3 - Listar produtos com uma quantidade em stock inferior a quantidade minima   |\n");
    printf("*================================================================================*\n");
    printf("\n-> ");
    fflush(stdin);

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        listarProdutos(test);
        break;
    case 2:
        listarProdutosPorFornecedor(test);
        break;
    case 3:

        break;
    default:
        printf("Insira uma escolha válida");
        menuPrincipal(test);
        break;
    }
}
