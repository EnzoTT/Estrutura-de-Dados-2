#include <stdio.h>
#include <stdlib.h>

/***************** Arvore.h *********************/

typedef struct _arvore {
	char info;
	struct _arvore* esq;
	struct _arvore* dir;
} Arvore;

Arvore* cria_arv_vazia();

void destroi_arv(Arvore* arv);

Arvore* constroi_arv(char elem, Arvore* esq, Arvore* dir);

/***************** Arvore.c *********************/

/*Cria uma arvore vazia!*/
Arvore* cria_arv_vazia() {
	return NULL;
}

/*Destroi uma arvore!*/
void destroi_arv(Arvore* arv) {
	if (arv != NULL) {
		destroi_arv(arv->esq);
		destroi_arv(arv->dir);
		free(arv);
	}
}

/*Cria um no em uma arvore!*/
Arvore* constroi_arv(char elem, Arvore* esq, Arvore* dir) {
	Arvore* arv = (Arvore*)malloc(sizeof(Arvore));
	arv->info = elem;
	arv->esq = esq;
	arv->dir = dir;
	return arv;
}
//RED
void imprimir_Pre_Ordem(Arvore* a)
{
	if (a != NULL)
	{
		printf("%c ", a->info);
		imprimir_Pre_Ordem(a->esq);
		imprimir_Pre_Ordem(a->dir);
	}
}

//ERD
void imprimir_In_Ordem(Arvore* a)
{
	if (a != NULL)
	{
		imprimir_In_Ordem(a->esq);
		printf("%c ", a->info);
		imprimir_In_Ordem(a->dir);
	}
}

//EDR
void imprimir_Pos_Ordem(Arvore* a)
{
	if (a != NULL)
	{
		imprimir_Pos_Ordem(a->esq);
		imprimir_Pos_Ordem(a->dir);
		printf("%c ", a->info);
	}
}

void imprime_arv_marcadores(Arvore* a)
{
	if (a != NULL)
	{
	
		printf("<%c", a->info);
		imprime_arv_marcadores(a->esq);
		imprime_arv_marcadores(a->dir);
		printf(">");

	}
	else
	{
		printf("<>");
	}
}

int pertence_arv(Arvore* a, char c)
{

	if (a != NULL)
	{
		if (c == a->info) return 1;
		if(pertence_arv(a->esq, c))return 1;
		if(pertence_arv(a->dir, c))return 1;
	}
	else
	{
		return 0;
	}
}

int conta_nos(Arvore* a) 
{

	if (a != NULL)
	{

		return(1 + conta_nos(a->esq) + conta_nos(a->dir));

	}
	return 0;
}

int calcula_altura_arvore(Arvore* a)
{
	if (a != NULL)
	{
		if (calcula_altura_arvore(a->dir) > calcula_altura_arvore(a->esq))
			return(calcula_altura_arvore(a->dir)+1);
		return(calcula_altura_arvore(a->esq) + 1);
	}
	return -1;
}

int conta_nos_folha(Arvore* a)
{
	if (a != NULL)
	{
		if ((a->dir == NULL && a->esq == NULL))
		{
			return(conta_nos_folha(a->dir) + 1 + conta_nos_folha(a->esq));

		}
		return(conta_nos_folha(a->dir) + conta_nos_folha(a->esq));
	}
	return 0;
	
}




int main() {

	Arvore* a = constroi_arv('a',
		constroi_arv('b',
			cria_arv_vazia(),
			constroi_arv('d', cria_arv_vazia(), cria_arv_vazia())
		),
		constroi_arv('c',
			constroi_arv('e', cria_arv_vazia(), cria_arv_vazia()),
			constroi_arv('f',cria_arv_vazia(), cria_arv_vazia())
		)
	);
	printf("\nPre ordem: ");
	imprimir_Pre_Ordem(a);
	printf("\nPos ordem: ");
	imprimir_Pos_Ordem(a);
	printf("\nIn ordem: ");
	imprimir_In_Ordem(a);

	printf("\n");
	imprime_arv_marcadores(a);

	printf("\n");
	printf("%d", pertence_arv(a, 'h'));

	printf("\n");
	printf("%d", conta_nos(a));

	printf("\n");
	printf("%d", calcula_altura_arvore(a));

	printf("\n");
	printf("%d", conta_nos_folha(a));
	

	destroi_arv(a);

	return 0;
}