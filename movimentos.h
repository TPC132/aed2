#ifndef _movimentos_h
#define _movimentos_h

#include "dados.h"

nodeM createNodeMovimentos();
nodeM addMovimento(nodeM head, movimento value);
void registarMovimento(node test, nodeM movimentos);
void consultarMovimentos(node test, nodeM movimentos);
int **obterData();
int verificarStock(node test, char produto[]);
int verificarQtdMinima(node test, char produto[]);
int adicionarStock(node test, char produto[], int num);
int removerStock(node test, char produto[], int num);
void consultarMovimentosDeProduto(node test, nodeM movimentos);

#endif