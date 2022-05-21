#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "menus.h"
#include "produtos.h"
#include "movimentos.h"
#include "ficheiro.h"


// struct produto
// {
//     int codigo;
//     char designacao[50];
//     char fornecedor[50];
//     float precoUnitario;
//     int quantidadeMinima;
//     int quantidadeStock;
// };

// struct movimento
// {
//     char produto[50];
//     int **data;
//     bool entrada;
//     int quantidade;
// };

// // Creating a node
// struct NodeProdutos
// {
//     struct produto data;
//     struct NodeProdutos *next;
// };

// struct NodeMovimentos
// {
//     struct movimento data;
//     struct NodeMovimentos *next;
// };

// typedef struct NodeProdutos *node; // Define node as pointer of data type struct LinkedList
// typedef struct produto produto;

// typedef struct NodeMovimentos *nodeM; // Define node as pointer of data type struct LinkedList
// typedef struct movimento movimento;

// void menuPrincipal(node produtos, nodeM movimentos);
// void menuProduto(node test, nodeM movimentos);
// void inserirProduto(node test, nodeM movimentos);
// void listarProdutos(node test, nodeM movimentos);
// void procurarProdutoDesignacao(node test, nodeM movimentos);
// int obterCodigo(node test, nodeM movimentos);
// void voltar(node test, nodeM movimentos);
// void editarProduto(node test, nodeM movimentos);
// void menuEditarProduto(node test, node selected, nodeM movimentos);
// void menuListarProdutos(node test, nodeM movimentos);
// void registarMovimento(node test, nodeM movimentos);
// void menuMovimentos(node test, nodeM movimentos);
// node remover(node test, char designacao[]);
// void removerProduto(node test, nodeM movimentos);
// int verificarStock(node test, char produto[]);
// int existeProduto(node test, char produto[]);
// void consultarMovimentos(node test, nodeM movimentos);

// node createNode()
// {
//     node temp;                                        // declare a node
//     temp = (node)malloc(sizeof(struct NodeProdutos)); // allocate memory using malloc()
//     temp->next = NULL;                                // make next point to NULL
//     return temp;                                      // return the new node
// }

// nodeM createNodeMovimentos()
// {
//     nodeM temp;                                          // declare a node
//     temp = (nodeM)malloc(sizeof(struct NodeMovimentos)); // allocate memory using malloc()
//     temp->next = NULL;                                   // make next point to NULL
//     return temp;                                         // return the new node
// }

// nodeM addMovimento(nodeM head, movimento value)
// {
//     nodeM temp, p;                 // declare two nodes temp and p
//     temp = createNodeMovimentos(); // createNode will return a new node with data = value and next pointing to NULL.
//     temp->data = value;            // add element's value to data part of node
//     temp->next = NULL;

//     if (head == NULL)
//     {
//         head = temp; // when linked list is empty
//     }
//     else
//     {
//         p = head; // assign head to p
//         while (p->next != NULL)
//         {
//             p = p->next; // traverse the list until p is the last node.The last node always points to NULL.
//         }
//         p->next = temp; // Point the previous last node to the new node created.
//     }
//     return head;
// }

// node addNode(node head, produto value)
// {
//     node temp, p;        // declare two nodes temp and p
//     temp = createNode(); // createNode will return a new node with data = value and next pointing to NULL.
//     temp->data = value;  // add element's value to data part of node
//     temp->next = NULL;

//     if (head == NULL)
//     {
//         head = temp; // when linked list is empty
//     }
//     else
//     {
//         p = head; // assign head to p
//         while (p->next != NULL)
//         {
//             p = p->next; // traverse the list until p is the last node.The last node always points to NULL.
//         }
//         p->next = temp; // Point the previous last node to the new node created.
//     }
//     return head;
// }

int main()
{   
    fflush(stdin);
    node startNodeProdutos = NULL;
    nodeM startNodeMovimentos = NULL;
    startNodeProdutos = carregarDadosProdutosFich(startNodeProdutos);
    menuPrincipal(startNodeProdutos, startNodeMovimentos);
}

// void menuPrincipal(node test, nodeM movimentos)
// {

//     int choice;

//     printf("\n");
//     printf("*========================*\n");
//     printf("| 1 - Gerir Produtos     |\n");
//     printf("| 2 - Gerir Movimentos   |\n");
//     printf("| 3 - Sair               |\n");
//     printf("*========================*\n");
//     printf("\n-> ");
//     fflush(stdin);

//     scanf("%d", &choice);

//     switch (choice)
//     {
//     case 1:
//         menuProduto(test, movimentos);
//         break;
//     case 2:
//         menuMovimentos(test, movimentos);
//         break;
//     case 3:
//         break;
//     default:
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf("!!              Insira uma escolha valida!            !!\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         menuPrincipal(test, movimentos);
//         break;
//     }
// }

// void menuProduto(node test, nodeM movimentos)
// {
//     int choice;

//     printf("\n");
//     printf("*========================*\n");
//     printf("| 1 - Inserir Produto    |\n");
//     printf("| 2 - Editar Produto     |\n");
//     printf("| 3 - Consultar Produto  |\n");
//     printf("| 4 - Remover Produto    |\n");
//     printf("| 5 - Listar Produtos    |\n");
//     printf("| 6 - Voltar             |\n");
//     printf("*========================*\n");
//     fflush(stdin);
//     printf("\n-> ");

//     scanf("%d", &choice);

//     switch (choice)
//     {
//     case 1:
//         inserirProduto(test, movimentos);
//         break;
//     case 2:
//         editarProduto(test, movimentos);
//         break;
//     case 3:
//         procurarProdutoDesignacao(test, movimentos);
//         break;
//     case 4:
//         removerProduto(test, movimentos);
//         break;
//     case 5:
//         menuListarProdutos(test, movimentos);
//         break;
//     case 6:
//         menuPrincipal(test, movimentos);
//         break;
//     default:
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf("!!              Insira uma escolha valida!            !!\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         menuPrincipal(test, movimentos);
//         break;
//     }
// }

// void removerProduto(node test, nodeM movimentos)
// {
//     char nome[100];

//     printf("\nInsira o nome do produto que pretende remover:\n");
//     printf("-> \n");
//     scanf("%s", nome);
//     printf("\n");
//     test = remover(test, nome);
//     menuProduto(test, movimentos);
// }

// node remover(node test, char designacao[])
// {
//     node ant, aux;
//     ant = test;
//     aux = test;
//     int encontrou = 0;
//     while (encontrou == 0 && aux != NULL)
//     {
//         if (!strcmp(aux->data.designacao, designacao))
//         {
//             encontrou = 1;
//         }
//         else
//         {
//             ant = aux;
//             aux = aux->next;
//         }
//     }
//     if (encontrou)
//     {
//         if (ant == aux && aux == test)
//         {
//             test = NULL;
//             return test;
//         }
//         else
//         {
//             ant->next = aux->next;
//         }
//         free(aux);
//         aux = NULL;
//     }
//     else
//     {
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf("-> Nao foram encontrados produtos com a designacao: %s\n", designacao);
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//     }
//     return test;
// }

// void listarProdutos(node test, nodeM movimentos)
// {
//     int counter = 0;
//     node link = test;
//     if (link == NULL)
//     {
//         printf("\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf("!!                   Nao ha produtos!                 !!\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         menuPrincipal(test, movimentos);
//     }
//     else
//     {
//         while (link != NULL)
//         {
//             ++counter;
//             // printf("\n-------\n-> %d\n-> %s\n-------\n", link->data.codigo, link->data.designacao);
//             printf("*========================*\n");
//             printf("Codigo: %d             \n", link->data.codigo);
//             printf("Designacao: %s         \n", link->data.designacao);
//             printf("*========================*\n");
//             link = link->next;
//         }
//         //printf("\n%d", counter);
//         menuPrincipal(test, movimentos);
//     }
// }

// void listarProdutosPorFornecedor(node test, nodeM movimentos)
// {
//     int counter = 0;
//     char nome[100];
//     node link = test;

//     printf("\n");
//     printf("Insira o nome do fornecedor:");
//     printf("-> \n");
//     printf("\n");
//     printf("-> ");
//     fflush(stdout);
//     scanf("%s", nome);

//     while (link != NULL)
//     {
//         if (!strcmp(link->data.fornecedor, nome))
//         {
//             ++counter;
//             printf("*========================*\n");
//             printf("Codigo: %d             \n", link->data.codigo);
//             printf("Designacao: %s         \n", link->data.designacao);
//             printf("*========================*\n");            
//             //printf("\n-------\n-> %d\n-> %s\n-------\n", link->data.codigo, link->data.designacao);
//         }
//         link = link->next;
//     }
//     //printf("\n%d", counter);
//     menuPrincipal(test, movimentos);
// }

// void inserirProduto(node test, nodeM movimentos)
// {
//     int codigo;
//     char designacao[50];
//     char fornecedor[50];
//     float precoUnitario;
//     int quantidadeMinima;
//     int quantidadeStock;

//     printf("\n");
//     printf("*=====================================*\n");
//     fflush(stdout);
//     printf("| Insira o nome do produto:           |\n");
//     fflush(stdout);
//     printf("  > ");
//     scanf("%s", designacao);
//     printf("+-------------------------------------+\n");

//     printf("| Insira o nome do fornecedor:        |\n");
//     fflush(stdout);
//     printf("  > ");
//     scanf("%s", fornecedor);
//     printf("+-------------------------------------+\n");

//     printf("| Insira o preco por unidade:         |\n");
//     fflush(stdout);
//     printf("  > ");
//     scanf("%f", &precoUnitario);
//     printf("+-------------------------------------+\n");

//     printf("| Insira a quantidade minima:         |\n");
//     fflush(stdout);
//     printf("  > ");
//     scanf("%d", &quantidadeMinima);
//     printf("+-------------------------------------+\n");

//     printf("| Insira a quantidade em stock:       |\n");
//     fflush(stdout);
//     printf("  > ");
//     scanf("%d", &quantidadeStock);
//     printf("+-------------------------------------+\n");

//     produto Produto;

//     strcpy(Produto.designacao, designacao);
//     strcpy(Produto.fornecedor, fornecedor);
//     Produto.precoUnitario = precoUnitario;
//     Produto.quantidadeMinima = quantidadeMinima;
//     Produto.quantidadeStock = quantidadeStock;
//     Produto.codigo = obterCodigo(test, movimentos);

//     node link = addNode(test, Produto);
//     menuPrincipal(link, movimentos);
// }

// node procurarNode(node test, char des[100])
// {
//     char oremos[100];
//     char senhor[100];

//     node list = test;

//     while (list != NULL)
//     {

//         if (!strcmp(list->data.designacao, des))
//         {
//             return list;
//         }
//         list = list->next;
//     }
//     return NULL;
// }

// void procurarProdutoDesignacao(node test, nodeM movimentos)
// {

//     node link;
//     char search[100];
//     printf("Introduza a designacao do produto \n");
//     printf("-> \n");
//     scanf("%s", search);
//     link = procurarNode(test, search);

//     if (link == NULL)
//     {
//         printf("\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf(" Nao foram encontrados produtos com a designacao %s \n", search);
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf("\n");
//         voltar(test, movimentos);
//     }
//     else
//     {
//         printf("\n");
//         printf("#########################################################\n\n");
//         printf("->  Produto: ");
//         printf("%s\n", link->data.designacao);
//         printf("_________________________________________________________\n\n");
//         printf("->  Codigo: ");
//         printf("%d\n", link->data.codigo);
//         printf("_________________________________________________________\n\n");
//         printf("->  Fornecedor: ");
//         printf("%s\n", link->data.fornecedor);
//         printf("_________________________________________________________\n\n");
//         printf("->  Preco por Unidade: ");
//         printf("%f\n", link->data.precoUnitario);
//         printf("_________________________________________________________\n\n");
//         printf("->  Quantidade Minima: ");
//         printf("%d\n", link->data.quantidadeMinima);
//         printf("_________________________________________________________\n\n");
//         printf("->  Quantidade em Stock: ");
//         printf("%d\n\n", link->data.quantidadeStock);
//         printf("#########################################################");
//         voltar(test, movimentos);
//     }
// }

// int obterCodigo(node test, nodeM movimentos)
// {
//     int code = 0;

//     if (test == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         while (test != NULL)
//         {
//             if (test->data.codigo > code)
//             {
//                 code = test->data.codigo;
//             }
//             test = test->next;
//         }
//         return code + 1;
//     }
// }

// void voltar(node test, nodeM movimentos)
// {
//     int selection;
//     printf("\n");
//     printf("\nSelecione 1 para voltar para o menu principal\n");
//     printf("\n");
//     printf("-> ");
//     scanf("%d", &selection);

//     if (selection == 1)
//     {
//         menuPrincipal(test, movimentos);
//     }
// }

// void editarProduto(node test, nodeM movimentos)
// {

//     char nome[100];

//     printf("\nInsira o nome do produto que pretende editar:\n");
//     printf("-> \n");
//     scanf("%s", nome);
//     printf("\n");
//     if (existeProduto(test, nome))
//     {
//         menuEditarProduto(test, procurarNode(test, nome), movimentos);
//     }
//     else
//     {
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf("-> Nao foram encontrados produtos com a designacao: %s\n", nome);
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         menuProduto(test, movimentos);
//     }
// }

// void menuEditarProduto(node test, node selected, nodeM movimentos)
// {

//     int choice;
//     char nome[100];
//     int quantidade;
//     float preco;

//     printf("\n");
//     printf("*=================================*\n");
//     printf("| 1 - Editar Designacao           |\n");
//     printf("| 2 - Editar Fornecedor           |\n");
//     printf("| 3 - Editar Preco por unidade    |\n");
//     printf("| 4 - Editar Quantidade Minima   |\n");
//     printf("| 5 - Editar Quantidade em Stock  |\n");
//     printf("| 6 - Voltar                      |\n");
//     printf("*=================================*\n");
//     fflush(stdin);
//     printf("\n-> ");

//     scanf("%d", &choice);

//     switch (choice)
//     {
//     case 1:
//         printf("\n");
//         printf("Insira a nova designacao:");
//         printf("\n");
//         printf("-> ");
//         scanf("%s", nome);
//         strcpy(selected->data.designacao, nome);
//         printf("\n");
//         printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//         printf("$$           Alteracoes efetuadas com sucesso!        $$\n");
//         printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//         printf("\n");
//         menuProduto(test, movimentos);
//         break;
//     case 2:
//         printf("\n");
//         printf("Insira o novo fornecedor:");
//         printf("\n");
//         printf("-> ");
//         scanf("%s", nome);
//         strcpy(selected->data.fornecedor, nome);
//         printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//         printf("$$           Alteracoes efetuadas com sucesso!        $$\n");
//         printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//         menuProduto(test, movimentos);
//         break;
//     case 3:
//         printf("\n");
//         printf("insira o novo preco por unidade:");
//         printf("\n");
//         printf("-> ");
//         scanf("%f", &preco);
//         selected->data.precoUnitario = preco;
//         printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//         printf("$$           Alteracoes efetuadas com sucesso!        $$\n");
//         printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//         menuProduto(test, movimentos);
//         break;
//     case 4:
//         printf("\n");
//         printf("insira a nova quantidade minima:");
//         printf("\n");
//         printf("-> ");
//         scanf("%d", &quantidade);
//         selected->data.quantidadeMinima = quantidade;
//         printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//         printf("$$           Alteracoes efetuadas com sucesso!        $$\n");
//         printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//         menuProduto(test, movimentos);
//         break;
//     case 5:
//         printf("\n");
//         printf("Insira a nova quantidade em stock:");
//         printf("\n");
//         printf("-> ");
//         scanf("%d", &quantidade);
//         selected->data.quantidadeStock = quantidade;
//         printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//         printf("$$           Alteracoes efetuadas com sucesso!        $$\n");
//         printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//         menuProduto(test, movimentos);
//         break;
//     case 6:
//         menuProduto(test, movimentos);
//         break;
//     default:
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf("!!              Insira uma escolha valida!            !!\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         menuPrincipal(test, movimentos);
//         break;
//     }
// }

// void listarProdutosPorQtdMinStock(node test, nodeM movimentos)
// {
//     node link = test;

//     while (link != NULL)
//     {
//         if (link->data.quantidadeStock < link->data.quantidadeMinima)
//         {
//             printf("*========================*\n");
//             printf("Codigo: %d             \n", link->data.codigo);
//             printf("Designacao: %s         \n", link->data.designacao);
//             printf("*========================*\n");
//             //printf("\n-------\n-> %d\n-> %s\n-------\n", link->data.codigo, link->data.designacao);
//         }
//         link = link->next;
//     }
//     menuPrincipal(test, movimentos);
// }

// void menuListarProdutos(node produtos, nodeM movimentos)
// {
//     int choice;

//     printf("\n");
//     printf("*================================================================================*\n");
//     printf("| 1 - Listar Todos os Produtos                                                   |\n");
//     printf("| 2 - Listar produtos por Fornecedor                                             |\n");
//     printf("| 3 - Listar produtos com uma quantidade em stock inferior a quantidade minima   |\n");
//     printf("| 4 - Voltar                                                                     |\n");
//     printf("*================================================================================*\n");
//     printf("\n-> ");
//     fflush(stdin);

//     scanf("%d", &choice);

//     switch (choice)
//     {
//     case 1:
//         listarProdutos(produtos, movimentos);
//         break;
//     case 2:
//         listarProdutosPorFornecedor(produtos, movimentos);
//         break;
//     case 3:
//         listarProdutosPorQtdMinStock(produtos, movimentos);
//         break;
//     case 4:
//         menuProduto(produtos, movimentos);
//         break;
//     default:
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf("!!              Insira uma escolha valida!            !!\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         menuPrincipal(produtos, movimentos);
//         break;
//     }
// }

// int existeProduto(node test, char produto[])
// {
//     while (test != NULL)
//     {
//         if (!strcmp(test->data.designacao, produto))
//         {
//             return 1;
//         }
//         else
//         {
//             test = test->next;
//         }
//     }
//     return 0;
// }

// int verificarStock(node test, char produto[])
// {
//     while (test != NULL)
//     {
//         if (!strcmp(test->data.designacao, produto))
//         {
//             return test->data.quantidadeStock;
//         }
//         else
//         {
//             test = test->next;
//         }
//     }
//     printf("\nwbc\n");
//     return -1;
// }

// int verificarQtdMinima(node test, char produto[])
// {
//     while (test != NULL)
//     {
//         if (!strcmp(test->data.designacao, produto))
//         {
//             return test->data.quantidadeMinima;
//         }
//         else
//         {
//             test = test->next;
//         }
//     }
//     return -1;
// }

// int adicionarStock(node test, char produto[], int num)
// {
//     while (test != NULL)
//     {
//         if (!strcmp(test->data.designacao, produto))
//         {
//             test->data.quantidadeStock += num;
//             return 1;
//         }

//         test = test->next;
//     }
//     return -1;
// }

// int removerStock(node test, char produto[], int num)
// {
//     while (test != NULL)
//     {
//         if (!strcmp(test->data.designacao, produto))
//         {
//             test->data.quantidadeStock -= num;
//             return 1;
//         }

//         test = test->next;
//     }
//     return -1;
// }

// int **obterData()
// {
//     int **data = (int **)malloc(2 * sizeof(int *));
//     for (int i = 0; i < 2; i++)
//         data[i] = (int *)malloc(3 * sizeof(int));

//     time_t rawtime;
//     struct tm *timeinfo;

//     time(&rawtime);
//     timeinfo = localtime(&rawtime);

//     data[0][0] = timeinfo->tm_mday;
//     data[0][1] = timeinfo->tm_mon + 1;
//     data[0][2] = timeinfo->tm_year + 1900;
//     data[1][0] = timeinfo->tm_hour;
//     data[1][1] = timeinfo->tm_min;
//     data[1][2] = timeinfo->tm_sec;

//     return data;
// }

// void registarMovimento(node test, nodeM movimentos)
// {
//     int choice, stock, qtdMinima, choice2;
//     char *date;
//     bool entrada;
//     int quantidade;
//     char produto[50];

//     node aux;
//     aux = test;

//     movimento mov;

//     fflush(stdout);
//     printf("\n");
//     printf("Indique o produto que pretende movimentar:\n");
//     printf("-> ");
//     fflush(stdout);
//     scanf("%s", produto);
//     fflush(stdout);
//     if (!existeProduto(test, produto))
//     {
//         printf("\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf("!!         O produto que selecionou não existe!       !!\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         menuMovimentos(test, movimentos);
//     }
//     else
//     {
//         strcpy(mov.produto, produto);
//         fflush(stdout);

//         mov.data = obterData();

//         printf("Indique o tipo de movimento:\n");
//         fflush(stdout);
//         printf("\nInsira 1 para Entrada ou 2 para Saida:\n");
//         printf("-> ");
//         fflush(stdout);
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             mov.entrada = true;
//             break;
//         case 2:
//             mov.entrada = false;
//             break;
//         default:
//             printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//             printf("!!              Insira uma escolha valida!            !!\n");
//             printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//             menuPrincipal(test, movimentos);
//             break;
//         }

//         fflush(stdout);
//         printf("\nInsira a quantidade:\n");
//         printf("-> \n");
//         fflush(stdout);
//         scanf("%d", &quantidade);
//         mov.quantidade = quantidade;

//         if (!mov.entrada)
//         {
//             stock = verificarStock(test, produto);
//             qtdMinima = verificarQtdMinima(test, produto);

//             if (quantidade > stock)
//             {
//                 printf("\n");
//                 printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//                 printf("!!  Nao existe stock suficiente para este movimento.  !!\n");
//                 printf("!!  Por favor verifique a quantidade atual em stock.  !!\n");
//                 printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//                 menuMovimentos(test, movimentos);
//             }
//             else if ((stock - quantidade) < qtdMinima)
//             {
//                 printf("\n");
//                 printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//                 printf("!!  Este movimento ira reduzir o stock para valores abaixo do stock minimo.  !!\n");
//                 printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//                 printf("\n");
//                 printf("\nSe pretende continuar insira 1. Senao, insira 2:\n");

//                 scanf("%d", &choice2);

//                 switch (choice2)
//                 {
//                 case 1:
//                 {
//                     nodeM link = addMovimento(movimentos, mov);
//                     removerStock(test, produto, quantidade);
//                     printf("\n");
//                     printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//                     printf("$$            Registo efetuado com sucesso!           $$\n");
//                     printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//                     menuMovimentos(test, link);
//                     break;
//                 }
//                 case 2:
//                     menuMovimentos(test, movimentos);
//                     break;
//                 default:
//                     printf("\n");
//                     printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//                     printf("!!              Insira uma escolha valida!            !!\n");
//                     printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//                     menuMovimentos(test, movimentos);
//                     break;
//                 }
//             }
//             else
//             {
//                 nodeM link = addMovimento(movimentos, mov);
//                 removerStock(test, produto, quantidade);
//                 printf("\n");
//                 printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//                 printf("$$            Registo efetuado com sucesso!           $$\n");
//                 printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//                 menuMovimentos(test, link);
//             }
//         }
//         else
//         {
//             nodeM link = addMovimento(movimentos, mov);
//             adicionarStock(test, produto, quantidade);
//             printf("\n");
//             printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//             printf("$$            Registo efetuado com sucesso!           $$\n");
//             printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//             menuMovimentos(test, link);
//         }
//     }
// }

// void consultarMovimentos(node test, nodeM movimentos)
// {
//     int di, mi, yi, df, mf, yf;
//     printf("\nDefina um periodo de tempo:\n");
//     printf("--- Inicio ---\n");
//     printf("Dia : ");
//     scanf("%d", &di);
//     printf("Mes : ");
//     scanf("%d", &mi);
//     printf("Ano : ");
//     scanf("%d", &yi);
//     printf("\n--- Fim ---\n");
//     printf("Dia : ");
//     scanf("%d", &df);
//     printf("Mes : ");
//     scanf("%d", &mf);
//     printf("Ano : ");
//     scanf("%d", &yf);

//     if (movimentos == NULL)
//     {
//         printf("\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf("!!          Nao foram registados movimentos!          !!\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         voltar(test, movimentos);
//     }
//     else
//     {
//         while (movimentos != NULL)
//         {
//             int **data;
//             data = movimentos->data.data;
//             if (data[0][0] >= di && data[0][1] >= mi && data[0][2] >= yi && data[0][1] <= df && data[0][1] >= mf && data[0][2] >= yf)
//             {
//                 printf("\n");
//                 printf("*========================*\n");
//                 printf("Designacao: %s             \n", movimentos->data.produto);
//                 printf("Quantidade: %d         \n", movimentos->data.quantidade);
//                 printf("Data: %d-%d-%d         \n", movimentos->data.data[0][0], movimentos->data.data[0][1], movimentos->data.data[0][2]);
//                 printf("*========================*\n");
//                 //printf("\n%s\n%d\n%d-%d-%d\n", movimentos->data.produto, movimentos->data.quantidade, movimentos->data.data[0][0], movimentos->data.data[0][1], movimentos->data.data[0][2]);
//                 movimentos = movimentos->next;
//             }
//         }

//         voltar(test, movimentos);
//     }
// }

// void menuMovimentos(node test, nodeM movimentos)
// {

//     int choice;

//     printf("\n");
//     printf("*==========================*\n");
//     printf("| 1 - Registar Movimento   |\n");
//     printf("| 2 - Consultar Movimentos |\n");
//     printf("| 3 - Voltar               |\n");
//     printf("*==========================*\n");
//     fflush(stdin);
//     printf("\n-> ");

//     scanf("%d", &choice);

//     switch (choice)
//     {
//     case 1:
//         registarMovimento(test, movimentos);
//         break;
//     case 2:
//         consultarMovimentos(test, movimentos);
//         break;
//     case 3:
//         menuPrincipal(test, movimentos);
//         break;
//     default:
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         printf("!!              Insira uma escolha valida!            !!\n");
//         printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
//         menuPrincipal(test, movimentos);
//         break;
//     }
// }
