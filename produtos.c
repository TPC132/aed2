#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "produtos.h"
#include "menus.h"
#include "movimentos.h"

void inserirProduto(node test, nodeM movimentos)
{
    //int codigo;
    char designacao[50];
    char fornecedor[50];
    float precoUnitario;
    int quantidadeMinima;
    int quantidadeStock;

    printf("\n");
    printf("*=====================================*\n");
    fflush(stdout);
    printf("| Insira o nome do produto:           |\n");
    fflush(stdout);
    printf("  > ");
    scanf("%s", designacao);
    printf("+-------------------------------------+\n");

    printf("| Insira o nome do fornecedor:        |\n");
    fflush(stdout);
    printf("  > ");
    scanf("%s", fornecedor);
    printf("+-------------------------------------+\n");

    printf("| Insira o preco por unidade:         |\n");
    fflush(stdout);
    printf("  > ");
    scanf("%f", &precoUnitario);
    printf("+-------------------------------------+\n");

    printf("| Insira a quantidade minima:         |\n");
    fflush(stdout);
    printf("  > ");
    scanf("%d", &quantidadeMinima);
    printf("+-------------------------------------+\n");

    printf("| Insira a quantidade em stock:       |\n");
    fflush(stdout);
    printf("  > ");
    scanf("%d", &quantidadeStock);
    printf("+-------------------------------------+\n");

    produto Produto;

    strcpy(Produto.designacao, designacao);
    strcpy(Produto.fornecedor, fornecedor);
    Produto.precoUnitario = precoUnitario;
    Produto.quantidadeMinima = quantidadeMinima;
    Produto.quantidadeStock = quantidadeStock;
    Produto.codigo = obterCodigo(test, movimentos);

    node link = addNode(test, Produto);
    menuPrincipal(link, movimentos);
}

void listarProdutos(node test, nodeM movimentos)
{
    int counter = 0;
    node link = test;
    if (link == NULL)
    {
        printf("\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!                   Nao ha produtos!                 !!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        menuPrincipal(test, movimentos);
    }
    else
    {
        while (link != NULL)
        {
            ++counter;
            // printf("\n-------\n-> %d\n-> %s\n-------\n", link->data.codigo, link->data.designacao);
            printf("*========================*\n");
            printf("Codigo: %d             \n", link->data.codigo);
            printf("Designacao: %s         \n", link->data.designacao);
            printf("*========================*\n");
            link = link->next;
        }
        //printf("\n%d", counter);
        menuPrincipal(test, movimentos);
    }
}

void procurarProdutoDesignacao(node test, nodeM movimentos)
{

    node link;
    char search[100];
    printf("Introduza a designacao do produto \n");
    printf("-> \n");
    scanf("%s", search);
    link = procurarNode(test, search);

    if (link == NULL)
    {
        printf("\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf(" Nao foram encontrados produtos com a designacao %s \n", search);
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("\n");
        voltar(test, movimentos);
    }
    else
    {
        printf("\n");
        printf("#########################################################\n\n");
        printf("->  Produto: ");
        printf("%s\n", link->data.designacao);
        printf("_________________________________________________________\n\n");
        printf("->  Codigo: ");
        printf("%d\n", link->data.codigo);
        printf("_________________________________________________________\n\n");
        printf("->  Fornecedor: ");
        printf("%s\n", link->data.fornecedor);
        printf("_________________________________________________________\n\n");
        printf("->  Preco por Unidade: ");
        printf("%f\n", link->data.precoUnitario);
        printf("_________________________________________________________\n\n");
        printf("->  Quantidade Minima: ");
        printf("%d\n", link->data.quantidadeMinima);
        printf("_________________________________________________________\n\n");
        printf("->  Quantidade em Stock: ");
        printf("%d\n\n", link->data.quantidadeStock);
        printf("#########################################################");
        voltar(test, movimentos);
    }
}

int obterCodigo(node test, nodeM movimentos)
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

void editarProduto(node test, nodeM movimentos)
{

    char nome[100];

    printf("\nInsira o nome do produto que pretende editar:\n");
    printf("-> \n");
    scanf("%s", nome);
    printf("\n");
    if (existeProduto(test, nome))
    {
        menuEditarProduto(test, procurarNode(test, nome), movimentos);
    }
    else
    {
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("-> Nao foram encontrados produtos com a designacao: %s\n", nome);
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        menuProduto(test, movimentos);
    }
}

node remover(node test, char designacao[])
{
    node ant, aux;
    ant = test;
    aux = test;
    int encontrou = 0;
    while (encontrou == 0 && aux != NULL)
    {
        if (!strcmp(aux->data.designacao, designacao))
        {
            encontrou = 1;
        }
        else
        {
            ant = aux;
            aux = aux->next;
        }
    }
    if (encontrou)
    {
        if (ant == aux && aux == test)
        {
            test = NULL;
            return test;
        }
        else
        {
            ant->next = aux->next;
        }
        free(aux);
        aux = NULL;
    }
    else
    {
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("-> Nao foram encontrados produtos com a designacao: %s\n", designacao);
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
    return test;
}

void removerProduto(node test, nodeM movimentos)
{
    char nome[100];

    printf("\nInsira o nome do produto que pretende remover:\n");
    printf("-> \n");
    scanf("%s", nome);
    printf("\n");
    test = remover(test, nome);
    menuProduto(test, movimentos);
}


void listarProdutosPorQtdMinStock(node test, nodeM movimentos)
{
    node link = test;

    while (link != NULL)
    {
        if (link->data.quantidadeStock < link->data.quantidadeMinima)
        {
            printf("*========================*\n");
            printf("Codigo: %d             \n", link->data.codigo);
            printf("Designacao: %s         \n", link->data.designacao);
            printf("*========================*\n");
            //printf("\n-------\n-> %d\n-> %s\n-------\n", link->data.codigo, link->data.designacao);
        }
        link = link->next;
    }
    menuPrincipal(test, movimentos);
}

node procurarNode(node test, char des[100])
{
    //char oremos[100];
    //char senhor[100];

    node list = test;

    while (list != NULL)
    {

        if (!strcmp(list->data.designacao, des))
        {
            return list;
        }
        list = list->next;
    }
    return NULL;
}


node createNode()
{
    node temp;                                        // declare a node
    temp = (node)malloc(sizeof(struct NodeProdutos)); // allocate memory using malloc()
    temp->next = NULL;                                // make next point to NULL
    return temp;                                      // return the new node
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

int existeProduto(node test, char produto[])
{
    while (test != NULL)
    {
        if (!strcmp(test->data.designacao, produto))
        {
            return 1;
        }
        else
        {
            test = test->next;
        }
    }
    return 0;
}

void listarProdutosPorFornecedor(node test, nodeM movimentos)
{
    int counter = 0;
    char nome[100];
    node link = test;

    printf("\n");
    printf("Insira o nome do fornecedor:");
    printf("-> \n");
    printf("\n");
    printf("-> ");
    fflush(stdout);
    scanf("%s", nome);

    while (link != NULL)
    {
        if (!strcmp(link->data.fornecedor, nome))
        {
            ++counter;
            printf("*========================*\n");
            printf("Codigo: %d             \n", link->data.codigo);
            printf("Designacao: %s         \n", link->data.designacao);
            printf("*========================*\n");
            // printf("\n-------\n-> %d\n-> %s\n-------\n", link->data.codigo, link->data.designacao);
        }
        link = link->next;
    }
    // printf("\n%d", counter);
    menuPrincipal(test, movimentos);
}
