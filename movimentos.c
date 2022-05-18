#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "movimentos.h"
#include "produtos.h"
#include "menus.h"

void registarMovimento(node test, nodeM movimentos)
{
    int choice, stock, qtdMinima, choice2;
    char *date;
    bool entrada;
    int quantidade;
    char produto[50];

    node aux;
    aux = test;

    movimento mov;

    fflush(stdout);
    printf("\n");
    printf("Indique o produto que pretende movimentar:\n");
    printf("-> ");
    fflush(stdout);
    scanf("%s", produto);
    fflush(stdout);
    if (!existeProduto(test, produto))
    {
        printf("\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!         O produto que selecionou não existe!       !!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        menuMovimentos(test, movimentos);
    }
    else
    {
        strcpy(mov.produto, produto);
        fflush(stdout);

        mov.data = obterData();

        printf("Indique o tipo de movimento:\n");
        fflush(stdout);
        printf("\nInsira 1 para Entrada ou 2 para Saida:\n");
        printf("-> ");
        fflush(stdout);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            mov.entrada = true;
            break;
        case 2:
            mov.entrada = false;
            break;
        default:
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            printf("!!              Insira uma escolha valida!            !!\n");
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            menuPrincipal(test, movimentos);
            break;
        }

        fflush(stdout);
        printf("\nInsira a quantidade:\n");
        printf("-> \n");
        fflush(stdout);
        scanf("%d", &quantidade);
        mov.quantidade = quantidade;

        if (!mov.entrada)
        {
            stock = verificarStock(test, produto);
            qtdMinima = verificarQtdMinima(test, produto);

            if (quantidade > stock)
            {
                printf("\n");
                printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                printf("!!  Nao existe stock suficiente para este movimento.  !!\n");
                printf("!!  Por favor verifique a quantidade atual em stock.  !!\n");
                printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                menuMovimentos(test, movimentos);
            }
            else if ((stock - quantidade) < qtdMinima)
            {
                printf("\n");
                printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                printf("!!  Este movimento ira reduzir o stock para valores abaixo do stock minimo.  !!\n");
                printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                printf("\n");
                printf("\nSe pretende continuar insira 1. Senao, insira 2:\n");

                scanf("%d", &choice2);

                switch (choice2)
                {
                case 1:
                {
                    nodeM link = addMovimento(movimentos, mov);
                    removerStock(test, produto, quantidade);
                    printf("\n");
                    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
                    printf("$$            Registo efetuado com sucesso!           $$\n");
                    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
                    menuMovimentos(test, link);
                    break;
                }
                case 2:
                    menuMovimentos(test, movimentos);
                    break;
                default:
                    printf("\n");
                    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                    printf("!!              Insira uma escolha valida!            !!\n");
                    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                    menuMovimentos(test, movimentos);
                    break;
                }
            }
            else
            {
                nodeM link = addMovimento(movimentos, mov);
                removerStock(test, produto, quantidade);
                printf("\n");
                printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
                printf("$$            Registo efetuado com sucesso!           $$\n");
                printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
                menuMovimentos(test, link);
            }
        }
        else
        {
            nodeM link = addMovimento(movimentos, mov);
            adicionarStock(test, produto, quantidade);
            printf("\n");
            printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
            printf("$$            Registo efetuado com sucesso!           $$\n");
            printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
            menuMovimentos(test, link);
        }
    }
}


void consultarMovimentos(node test, nodeM movimentos)
{
    int di, mi, yi, df, mf, yf;
    printf("\nDefina um periodo de tempo:\n");
    printf("--- Inicio ---\n");
    printf("Dia : ");
    scanf("%d", &di);
    printf("Mes : ");
    scanf("%d", &mi);
    printf("Ano : ");
    scanf("%d", &yi);
    printf("\n--- Fim ---\n");
    printf("Dia : ");
    scanf("%d", &df);
    printf("Mes : ");
    scanf("%d", &mf);
    printf("Ano : ");
    scanf("%d", &yf);

    if (movimentos == NULL)
    {
        printf("\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("!!          Nao foram registados movimentos!          !!\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        voltar(test, movimentos);
    }
    else
    {
        while (movimentos != NULL)
        {
            int **data;
            data = movimentos->data.data;
            if (data[0][0] >= di && data[0][1] >= mi && data[0][2] >= yi && data[0][1] <= df && data[0][1] >= mf && data[0][2] >= yf)
            {
                printf("\n");
                printf("*========================*\n");
                printf("Designacao: %s             \n", movimentos->data.produto);
                printf("Quantidade: %d         \n", movimentos->data.quantidade);
                printf("Data: %d-%d-%d         \n", movimentos->data.data[0][0], movimentos->data.data[0][1], movimentos->data.data[0][2]);
                printf("*========================*\n");
                //printf("\n%s\n%d\n%d-%d-%d\n", movimentos->data.produto, movimentos->data.quantidade, movimentos->data.data[0][0], movimentos->data.data[0][1], movimentos->data.data[0][2]);
                movimentos = movimentos->next;
            }
        }

        voltar(test, movimentos);
    }
}


int **obterData()
{
    int **data = (int **)malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; i++)
        data[i] = (int *)malloc(3 * sizeof(int));

    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    data[0][0] = timeinfo->tm_mday;
    data[0][1] = timeinfo->tm_mon + 1;
    data[0][2] = timeinfo->tm_year + 1900;
    data[1][0] = timeinfo->tm_hour;
    data[1][1] = timeinfo->tm_min;
    data[1][2] = timeinfo->tm_sec;

    return data;
}


int verificarStock(node test, char produto[])
{
    while (test != NULL)
    {
        if (!strcmp(test->data.designacao, produto))
        {
            return test->data.quantidadeStock;
        }
        else
        {
            test = test->next;
        }
    }
    printf("\nwbc\n");
    return -1;
}


int verificarQtdMinima(node test, char produto[])
{
    while (test != NULL)
    {
        if (!strcmp(test->data.designacao, produto))
        {
            return test->data.quantidadeMinima;
        }
        else
        {
            test = test->next;
        }
    }
    return -1;
}

int adicionarStock(node test, char produto[], int num)
{
    while (test != NULL)
    {
        if (!strcmp(test->data.designacao, produto))
        {
            test->data.quantidadeStock += num;
            return 1;
        }
 
        test = test->next;
    }
    return -1;
}

int removerStock(node test, char produto[], int num)
{
    while (test != NULL)
    {
        if (!strcmp(test->data.designacao, produto))
        {
            test->data.quantidadeStock -= num;
            return 1;
        }

        test = test->next;
    }
    return -1;
}


nodeM createNodeMovimentos()
{
    nodeM temp;                                          // declare a node
    temp = (nodeM)malloc(sizeof(struct NodeMovimentos)); // allocate memory using malloc()
    temp->next = NULL;                                   // make next point to NULL
    return temp;                                         // return the new node
}

nodeM addMovimento(nodeM head, movimento value)
{
    nodeM temp, p;                 // declare two nodes temp and p
    temp = createNodeMovimentos(); // createNode will return a new node with data = value and next pointing to NULL.
    temp->data = value;            // add element's value to data part of node
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