#ifndef _menus_h
#define _menus_h

#include "produtos.h"
#include "movimentos.h"
#include "dados.h"

void menuPrincipal(node produtos, nodeM movimentos);
void menuProduto(node test, nodeM movimentos);
void menuEditarProduto(node test, node selected, nodeM movimentos);
void menuListarProdutos(node test, nodeM movimentos);
void menuMovimentos(node test, nodeM movimentos);
void voltar(node test, nodeM movimentos);

#endif