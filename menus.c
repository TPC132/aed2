#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "menus.h"
#include "produtos.h"
#include "movimentos.h"
#include "ficheiro.h"



void menuPrincipal(node test, nodeM movimentos)
{

    int choice;

    printf("\n");
    printf("*========================*\n");
    printf("| 1 - Gerir Produtos     |\n");
    printf("| 2 - Gerir Movimentos   |\n");
    printf("| 3 - Sair               |\n");
    printf("*========================*\n");
    printf("\n-> ");
    fflush(stdin);

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        menuProduto(test, movimentos);
        break;
    case 2:
        menuMovimentos(test, movimentos);
        break;
    case 3:
        guardarDadosProdutosFich(test);
        exit(0);
        break;
    default:
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!              Insira uma escolha valida!            !!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        menuPrincipal(test, movimentos);
        break;
    }
}

void menuProduto(node test, nodeM movimentos)
{
    int choice;

    printf("\n");
    printf("*========================*\n");
    printf("| 1 - Inserir Produto    |\n");
    printf("| 2 - Editar Produto     |\n");
    printf("| 3 - Consultar Produto  |\n");
    printf("| 4 - Remover Produto    |\n");
    printf("| 5 - Listar Produtos    |\n");
    printf("| 6 - Voltar             |\n");
    printf("*========================*\n");
    fflush(stdin);
    printf("\n-> ");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        inserirProduto(test, movimentos);
        break;
    case 2:
        editarProduto(test, movimentos);
        break;
    case 3:
        procurarProdutoDesignacao(test, movimentos);
        break;
    case 4:
        removerProduto(test, movimentos);
        break;
    case 5:
        menuListarProdutos(test, movimentos);
        break;
    case 6:
        menuPrincipal(test, movimentos);
        break;
    default:
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!              Insira uma escolha valida!            !!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        menuPrincipal(test, movimentos);
        break;
    }
}


void menuEditarProduto(node test, node selected, nodeM movimentos)
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
    printf("| 4 - Editar Quantidade Minima   |\n");
    printf("| 5 - Editar Quantidade em Stock  |\n");
    printf("| 6 - Voltar                      |\n");
    printf("*=================================*\n");
    fflush(stdin);
    printf("\n-> ");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\n");
        printf("Insira a nova designacao:");
        printf("\n");
        printf("-> ");
        scanf("%s", nome);
        strcpy(selected->data.designacao, nome);
        printf("\n");
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("$$           Alteracoes efetuadas com sucesso!        $$\n");
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("\n");
        menuProduto(test, movimentos);
        break;
    case 2:
        printf("\n");
        printf("Insira o novo fornecedor:");
        printf("\n");
        printf("-> ");
        scanf("%s", nome);
        strcpy(selected->data.fornecedor, nome);
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("$$           Alteracoes efetuadas com sucesso!        $$\n");
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        menuProduto(test, movimentos);
        break;
    case 3:
        printf("\n");
        printf("insira o novo preco por unidade:");
        printf("\n");
        printf("-> ");
        scanf("%f", &preco);
        selected->data.precoUnitario = preco;
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("$$           Alteracoes efetuadas com sucesso!        $$\n");
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        menuProduto(test, movimentos);
        break;
    case 4:
        printf("\n");
        printf("insira a nova quantidade minima:");
        printf("\n");
        printf("-> ");
        scanf("%d", &quantidade);
        selected->data.quantidadeMinima = quantidade;
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("$$           Alteracoes efetuadas com sucesso!        $$\n");
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        menuProduto(test, movimentos);
        break;
    case 5:
        printf("\n");
        printf("Insira a nova quantidade em stock:");
        printf("\n");
        printf("-> ");
        scanf("%d", &quantidade);
        selected->data.quantidadeStock = quantidade;
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("$$           Alteracoes efetuadas com sucesso!        $$\n");
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        menuProduto(test, movimentos);
        break;
    case 6:
        menuProduto(test, movimentos);
        break;
    default:
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!              Insira uma escolha valida!            !!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        menuPrincipal(test, movimentos);
        break;
    }
}

void menuListarProdutos(node produtos, nodeM movimentos)
{
    int choice;

    printf("\n");
    printf("*================================================================================*\n");
    printf("| 1 - Listar Todos os Produtos                                                   |\n");
    printf("| 2 - Listar produtos por Fornecedor                                             |\n");
    printf("| 3 - Listar produtos com uma quantidade em stock inferior a quantidade minima   |\n");
    printf("| 4 - Voltar                                                                     |\n");
    printf("*================================================================================*\n");
    printf("\n-> ");
    fflush(stdin);

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        listarProdutos(produtos, movimentos);
        break;
    case 2:
        listarProdutosPorFornecedor(produtos, movimentos);
        break;
    case 3:
        listarProdutosPorQtdMinStock(produtos, movimentos);
        break;
    case 4:
        menuProduto(produtos, movimentos);
        break;
    default:
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!              Insira uma escolha valida!            !!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        menuPrincipal(produtos, movimentos);
        break;
    }
}


void menuMovimentos(node test, nodeM movimentos)
{

    int choice;

    printf("\n");
    printf("*==========================*\n");
    printf("| 1 - Registar Movimento   |\n");
    printf("| 2 - Consultar Movimentos |\n");
    printf("| 3 - Voltar               |\n");
    printf("*==========================*\n");
    fflush(stdin);
    printf("\n-> ");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        registarMovimento(test, movimentos);
        break;
    case 2:
        consultarMovimentos(test, movimentos);
        break;
    case 3:
        menuPrincipal(test, movimentos);
        break;
    default:
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!              Insira uma escolha valida!            !!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        menuPrincipal(test, movimentos);
        break;
    }
}


void voltar(node test, nodeM movimentos)
{
    int selection;
    printf("\n");
    printf("\nSelecione 1 para voltar para o menu principal\n");
    printf("\n");
    printf("-> ");
    scanf("%d", &selection);

    if (selection == 1)
    {
        menuPrincipal(test, movimentos);
    }
}





