#ifndef _produtos_h
#define _produtos_h

#include "dados.h"

node createNode();
node addNode(node head, produto value);
void inserirProduto(node test, nodeM movimentos);
void listarProdutos(node test, nodeM movimentos);
void procurarProdutoDesignacao(node test, nodeM movimentos);
void editarProduto(node test, nodeM movimentos);
int obterCodigo(node test, nodeM movimentos);
int existeProduto(node test, char produto[]);
node remover(node test, char designacao[]);
void removerProduto(node test, nodeM movimentos);
void listarProdutosPorQtdMinStock(node test, nodeM movimentos);
node procurarNode(node test, char des[100]);
void listarProdutosPorFornecedor(node test, nodeM movimentos);

#endif