#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
	int id;          /*Identificador armazenado no nó. */
	struct noA* next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
	int E; /* Quantidade de arestas. */
	int V; /* Quantidade de vértices. */
	NoA** Adj; /* Lista de adjacências. */
} GrafoA;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
	int E; /* Quantidade de arestas. */
	int V; /* Quantidade de vértices. */
	int** Mat; /* Matrix de adjacências. */
} GrafoM;

/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj(int tamanho) {
	int v;
	GrafoA* G = (GrafoA*)malloc(sizeof(GrafoA));
	G->E = 0;
	G->V = tamanho;
	G->Adj = (NoA * *)malloc(tamanho * sizeof(NoA*));
	for (v = 0; v < G->V; v++) {
		G->Adj[v] = NULL;
	}
	return G;
}

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat(int tamanho) {
	int v;
	GrafoM* G = (GrafoM*)malloc(sizeof(GrafoM));
	G->E = 0;
	G->V = tamanho;
	G->Mat = (int**)malloc(tamanho * sizeof(int*));
	for (v = 0; v < G->V; v++) {
		G->Mat[v] = (int*)malloc(tamanho * sizeof(int));
	}
	return G;
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj(GrafoA* G) {
	int v;
	for (v = 0; v < G->V; v++) {
		if (G->Adj[v] != NULL) {
			free(G->Adj[v]);
		}
	}
	free(G->Adj);
	free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat(GrafoM* G) {
	int v;
	for (v = 0; v < G->V; v++) {
		if (G->Mat[v] != NULL) {
			free(G->Mat[v]);
		}
	}
	free(G->Mat);
	free(G);
}

void inicializar_grafo_mat(GrafoM* grafo) {
	int i, j;
	for (i = 0; i < grafo->V; i++)
	{
		for (j = 0; j < grafo->V; j++)
		{
			grafo->Mat[i][j] = 0;
		}
	}

}

void adicionar_aresta_mat(int i, int j ,GrafoM* grafo)
{
	grafo->Mat[i][j] = 1;
	grafo->Mat[j][i] = 1;
}

void _adicionar_aresta_adj(int i, int j, grafoA* grafo)
{
	NoA* aux, * ultimo = NULL;
	for (aux = grafo->Adj[i]; aux != NULL; aux = aux->next)
	{
		if (aux->id == j)
		{
			printf("Ja existe");
			return;
		}
		ultimo = aux;
	}
	NoA* novo = (NoA*)malloc(sizeof(NoA));
	novo->id = j;
	novo->next = NULL;
	if (ultimo != NULL)
	{
		ultimo->next = novo;
	}
	else
	{
		grafo->Adj[i] = novo;
	}
}

void adicionar_aresta_adj(int i, int j, grafoA* grafo)
{
	_adicionar_aresta_adj(i, j, grafo);
	_adicionar_aresta_adj(j, i, grafo);
	grafo->E++;
}


void imprimir_grafo_adj(GrafoA* grafo)
{
	int i;
	
	for (i = 0; i < grafo->V; i++)
	{
		NoA* aux = grafo->Adj[i];
		printf("%d ->", i);
		while (aux != NULL)
		{
			printf("%d ", aux->id);
			aux = aux->next;
		}
		printf("\n");
	}
}

void imprimir_grafo_mat(GrafoM* grafo)
{
	int i, j;
	for (i = 0; i < grafo->V; i++)
	{
		for (j = 0; j < grafo->V; j++)
		{
			printf("%d ", grafo->Mat[i][j]);
		}
		printf("\n");
	}
}

/* */
int main() {

	int Va = 6; /*Número de vértices*/

	GrafoA* Ga = criar_grafo_adj(Va);

	int Vm = 6; /*Número de vértices*/

	GrafoM* Gm = criar_grafo_mat(Vm);
	/*inicializar_grafo_mat(Gm);

	adicionar_aresta_mat(0, 1, Gm);
	adicionar_aresta_mat(0, 2, Gm);
	adicionar_aresta_mat(0, 5, Gm);
	adicionar_aresta_mat(1, 2, Gm);
	adicionar_aresta_mat(1, 3, Gm);
	adicionar_aresta_mat(2, 3, Gm);
	adicionar_aresta_mat(2, 4, Gm);
	adicionar_aresta_mat(3, 4, Gm);
	adicionar_aresta_mat(4, 5, Gm);

	imprimir_grafo_mat(Gm);*/

	adicionar_aresta_adj(0, 1, Ga);
	adicionar_aresta_adj(0, 2, Ga);
	adicionar_aresta_adj(0, 5, Ga);
	adicionar_aresta_adj(1, 2, Ga);
	adicionar_aresta_adj(1, 3, Ga);
	adicionar_aresta_adj(2, 3, Ga);
	adicionar_aresta_adj(2, 4, Ga);
	adicionar_aresta_adj(3, 4, Ga);
	adicionar_aresta_adj(4, 5, Ga);

	imprimir_grafo_adj(Ga); 





	liberar_grafo_adj(Ga);
	liberar_grafo_mat(Gm);

	return 0;
}
