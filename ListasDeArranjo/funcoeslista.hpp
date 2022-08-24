#include "funcoeslista.cpp"

struct TipoItem;
struct TipoLista;
void criaListaVazia(TipoLista &lista);
bool verificaListaVazia(TipoLista &lista);
bool verificaListaCheia(TipoLista &lista);
void imprimeLista(TipoLista &lista);
bool insereItem(TipoLista &lista, TipoItem item);
int pesquisaItem(TipoLista &lista, TipoItem item);
void removeItem(TipoLista &lista, int posicao);