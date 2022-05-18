// struct movimento
// {
//     char produto[50];
//     int **data;
//     bool entrada;
//     int quantidade;
// };

// struct NodeMovimentos
// {
//     struct movimento data;
//     struct NodeMovimentos *next;
// };

// typedef struct NodeMovimentos *nodeM; // Define node as pointer of data type struct LinkedList
// typedef struct movimento movimento;

nodeM createNodeMovimentos();
nodeM addMovimento(nodeM head, movimento value);
void registarMovimento(node test, nodeM movimentos);
void consultarMovimentos(node test, nodeM movimentos);
int **obterData();
int verificarStock(node test, char produto[]);
int verificarQtdMinima(node test, char produto[]);
int adicionarStock(node test, char produto[], int num);
int removerStock(node test, char produto[], int num);