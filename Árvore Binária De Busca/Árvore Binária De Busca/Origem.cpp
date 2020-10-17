#include <stdio.h>
#include <stdlib.h>


typedef struct arvore {
	int info;
	struct arvore* esq;
	struct arvore* dir;
} Arvore;

int Buscar(Arvore* a, int v)
{
	if (a == NULL) {
		return 0;
	}
	else if (v < a->info) {
		return Buscar(a->esq, v);
	}
	else if (v > a->info) {
		return Buscar(a->dir, v);
	}
	else {
		return 1;
	}
}

Arvore* inserir(Arvore* a, int v)
{

if (a == NULL) {
	a = (Arvore*)malloc(sizeof(Arvore));
	a->info = v;
	a->esq = NULL;
	a->dir = NULL;
}
else if (v < a->info) {
	a->esq = inserir(a->esq, v);
}
else {
	a->dir = inserir(a->dir, v);
}
return a;
}

Arvore* Remover(Arvore* a, int v)
{
	if (a == NULL) { return NULL; }
	else {
		if (a->info > v)
			a->esq = Remover(a->esq, v);
		else if (a->info < v)
			a->dir = Remover(a->dir, v);
		else
			if ((a->esq == NULL) && (a->dir == NULL)) {
				free(a);
				a = NULL;
			}
			else if (a->dir == NULL) {
				Arvore* tmp = a;
				a = a->esq;
				free(tmp);
			}
			else if (a->esq == NULL) {
				Arvore* tmp = a;
				a = a->dir;
				free(tmp);
			}
			else {
				Arvore* tmp = a->esq;
				while (tmp->dir != NULL)
					tmp = tmp->dir;
				a->info = tmp->info;
				tmp->info = v;
				a->esq = Remover(a->esq, v);
			}
		return a;
	}
}

void imprimir_in_order(Arvore * a) 
{
	if (a != NULL) {
		imprimir_in_order(a->esq);
		printf("%d\n", a->info);
		imprimir_in_order(a->dir);
	}
}

int Min(Arvore* a) {
	if (a != NULL)
	{
		while (a->esq != NULL)
		{
			a = a->esq;
		}
		printf("%d", a->info);
		return a->info;
	}
}
int Max(Arvore* a) {
	if (a != NULL)
	{
		while (a->dir != NULL)
		{
			a = a->dir;
		}
		return a->info;
	}
}

void imprime_decrescente(Arvore* a){	if (a != NULL) {
		imprime_decrescente(a->dir);
		printf("%d\n", a->info);
		imprime_decrescente(a->esq);
	}}int maximo(int a, int b)
{
	return(a > b ? a : b);
}

int maior_ramo(Arvore* a) {
	if (a != NULL)
	{
		return (a->info + maximo(maior_ramo(a->dir), maior_ramo(a->esq)));
	}
	else {
		return 0;
	}
}

int ancestral(Arvore* a, int e1, int e2)
{
}

int main()
{
	Arvore* a = NULL;
	a = inserir(a, 50);
	a = inserir(a, 30);
	a = inserir(a, 90);
	a = inserir(a, 20);
	a = inserir(a, 40);
	a = inserir(a, 95);
	a = inserir(a, 10);
	a = inserir(a, 35);
	a = inserir(a, 45);
	//imprimir_in_order(a);
	//imprime_decrescente(a);
	printf("%d", ancestral(a, 20, 40));
	//int i;
	/*Questao 2
	for (i = 0; i < 100;i++)
	{
		a = inserir(a, i);
	}*/
	
	/*Questao 3
	for (i = 0; i < 1000; i++)
	{
		a = inserir(a, rand()%100000);
	}*/
	//Min(a);
	//Buscar(a, 100000);
	


}

/*Questao 2
Tempo = 47.75s

Questao 3
Tempo = 0,040s

*/