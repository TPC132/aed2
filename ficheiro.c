#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "menus.h"
#include "produtos.h"
#include "movimentos.h"
#include "ficheiro.h"

node carregarDadosProdutosFich(node lista)
{
    FILE *fich;
    produto dados;
    node aux = lista;
    if ((fich = fopen("produtos.dat", "rb")) != NULL)
    {
        int n;
        while (!feof(fich))
        {
            n = fread(&dados, sizeof(produto), 1, fich);
            if (n == 1)
            {

                node temp;
                temp = createNode();
                temp->data = dados; 
                temp->next = NULL;

                if (lista == NULL)
                {
                    printf("aqui");
                    lista = temp;
                    aux = lista;
                }
                else
                {
                    while (aux->next != NULL)
                    {
                        aux = aux->next;
                    }
                    aux->next = temp;
                }
            }
        }
    }
    fclose(fich);
    return lista;
}

void guardarDadosProdutosFich(node lista)
{
    FILE *fich;
    fich = fopen("produtos.dat", "wb");
    node aux = lista;
    produto ass;
    while (aux != NULL)
    {
        ass = aux->data;
        fwrite(&ass, sizeof(produto), 1, fich);
        aux = aux->next;
    }
    fclose(fich);
}

nodeM carregarDadosMovimentosFich(nodeM lista)
{
    FILE *a;
    movimento p;
    if ((a = fopen("movimentos.dat", "rb")) != NULL)
    {
        int n;
        while (!feof(a))
        {
            n = fread(&p, sizeof(movimento), 1, a);
            if (n == 1)
            {
                nodeM aux = lista;

                if (lista == NULL)
                {
                    nodeM novoNodo = (nodeM)malloc(sizeof(nodeM));
                    novoNodo->data = p;
                    novoNodo->next = NULL;
                    lista = novoNodo;
                }
                else
                {
                    while (aux != NULL)
                    {
                        aux = aux->next;
                    }
                    nodeM novoNodo = (nodeM)malloc(sizeof(nodeM));
                    novoNodo->data = p;
                    novoNodo->next = NULL;
                    aux->next = novoNodo;
                }
            }
        }
    }
    fclose(a);
    return lista;
}

void guardarDadosMovimentosFich(nodeM lista)
{
    FILE *fich;
    fich = fopen("movimentos.dat", "wb");
    nodeM aux = lista;
    movimento ass;
    while (aux != NULL)
    {
        ass = aux->data;
        fwrite(&ass, sizeof(movimento), 1, fich);
        aux = aux->next;
    }
    fclose(fich);
}

node testi(node lista)
{
    FILE *fich;
    produto dados;
    if ((fich = fopen("produtos.dat", "rb")) != NULL)
    {
        printf("yes");
        int n;
        while (!feof(fich))
        {
            n = fread(&dados, sizeof(produto), 1, fich);
            if (n == 1)
            {
                printf("yes");
                node aux = lista;

                if (lista == NULL)
                {
                    printf("aqui");
                    node novoNodo = (node)malloc(sizeof(node));
                    novoNodo->data = dados;
                    novoNodo->next = NULL;
                    lista = novoNodo;
                }
                else
                {
                    while (aux != NULL)
                    {
                        aux = aux->next;
                    }
                    node novoNodo = (node)malloc(sizeof(node));
                    novoNodo->data = dados;
                    novoNodo->next = NULL;
                    aux->next = novoNodo;
                }
            }
        }
    }
    fclose(fich);
    printf("---OK---");
    return lista;
}