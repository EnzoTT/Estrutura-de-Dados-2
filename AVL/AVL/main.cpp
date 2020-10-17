#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct node {
	const char* chave;
	int altura;
	struct node* esq;
	struct node* dir;
} No, Arvore;

/*----------------------*/
int maior(int esq, int dir) {
	return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura(Arvore * a) {
	if (a == NULL)
		return -1;
	else
		return a->altura;
	
}

int atualizar_altura(Arvore * a) {
	return(maior(altura(a->esq), altura(a->dir)) + 1);
}

/*----------------------*/
int balanceamento(Arvore * a) {
	//positivo direita, negativo esquerda
	return ((altura(a->dir) - altura(a->esq)));
}

/*----------------------*/
Arvore* rotacao_simples_esq(Arvore * a) {

		No* tmp = a->dir;
		a->dir = tmp->esq;
		tmp->esq = a;
		a->altura = atualizar_altura(a);
		tmp->altura = atualizar_altura(tmp);
		return tmp;
	
}
/*----------------------*/
Arvore* rotacao_simples_dir(Arvore * a) {
	No* tmp = a->esq;
	a->esq = tmp->dir;
	tmp->dir = a;
	a->altura = atualizar_altura(a);
	tmp->altura = atualizar_altura(tmp);
	return tmp;
}

/*----------------------*/
Arvore* rotacao_dupla_esq(Arvore * a) {
	a->dir = rotacao_simples_dir(a->dir);
	return rotacao_simples_esq(a);
}

/*----------------------*/
Arvore* rotacao_dupla_dir(Arvore * a) {
	a->esq = rotacao_simples_esq(a->esq);
	return rotacao_simples_dir(a);
}

/*----------------------*/
Arvore* atualizar_fb_dir(Arvore * a) {
	a->altura = atualizar_altura(a);
	if (balanceamento(a) == 2) {
		if (balanceamento(a->dir) >= 0) {
			a = rotacao_simples_esq(a);
		}
		else {
			a = rotacao_dupla_esq(a);
		}
	}
	return a;
}

/*----------------------*/
Arvore* atualizar_fb_esq(Arvore * a) {
	a->altura = atualizar_altura(a);
	if (balanceamento(a) == -2) {
		if (balanceamento(a->esq) <= 0) {
			a = rotacao_simples_dir(a);
		}
		else {
			a =rotacao_dupla_dir(a);
		}
	}
	return a;
}

/*----------------------*/
Arvore* inserir(Arvore * a, const char* chave) {
	if (a == NULL)
	{
		a = (No*) malloc (sizeof(No));
		strcpy((char*)a->chave, chave);
		a->altura = 0;
		a->esq = a->dir = NULL;
	}
	else if (strcmp(chave,a->chave)<0)
	{
		a->esq = inserir(a->esq, chave);
		a = atualizar_fb_esq(a);
	}
	else if (strcmp(chave, a->chave)>0)
	{
		a->dir = inserir(a->dir, chave);
		a = atualizar_fb_dir(a);
	}
	return a;
}

/*----------------------*
/*Arvore* remover(Arvore * a, char chave) {
	if (a == NULL) {
		return NULL;
	}
	else {
		if (chave < a->chave) {
			a->esq = remover(a->esq, chave);
			a = atualizar_fb_dir(a);
		}
		else if (chave > a->chave) {
			a->dir = remover(a->dir, chave);
			a = atualizar_fb_esq(a);
		}
		else {
			if ((a->esq == NULL) && (a->dir == NULL)) {
				free(a);
				a = NULL;
			}
			else if (a->esq == NULL) {
				No* tmp = a;
				a = a->dir;
				free(tmp);
			}
			else if (a->dir == NULL) {
				No* tmp = a;
				a = a->esq;
				free(tmp);
			}
			else {
				No* tmp = a->esq;
				while (tmp->dir != NULL) {
					tmp = tmp->dir;
				}
				a->chave = tmp->chave;
				tmp->chave = chave;
				a->esq = remover(a->esq, chave);
				a = atualizar_fb_dir(a);
			}
		}
		return a;
	}
}*/

/*----------------------*/
void imprimir_in_order(Arvore * a, int nivel) {
	if (a != NULL) {
		int i;
		for (i = 0; i < nivel; i++) {
			printf("      ");
		}
		printf("Chave: %s (altura: %d, fb: %+d) no nível: %d\n", a->chave, a->altura, balanceamento(a), nivel);
		imprimir_in_order(a->esq, nivel + 1);
		imprimir_in_order(a->dir, nivel + 1);
	}
}

/*----------------------*/
int main() {

	Arvore* AVL = NULL;

	//Questao 1
	/*AVL = inserir(AVL, 'Q');
	AVL = inserir(AVL, 'Z');
	AVL = inserir(AVL, 'B');
	AVL = inserir(AVL, 'Y');
	AVL = inserir(AVL, 'T');
	AVL = inserir(AVL, 'M');
	AVL = inserir(AVL, 'E');
	AVL = inserir(AVL, 'W');
	AVL = inserir(AVL, 'X');
	AVL = inserir(AVL, 'S');
	AVL = inserir(AVL, 'F');
	AVL = inserir(AVL, 'G');
	AVL = inserir(AVL, 'A');
	AVL = inserir(AVL, 'H');
	AVL = inserir(AVL, 'N');
	AVL = inserir(AVL, 'O');
	AVL = inserir(AVL, 'P');
	AVL = inserir(AVL, 'R');*/

	//Questao 2
	/*
	AVL = inserir(AVL, 14);
	AVL = inserir(AVL, 5);
	AVL = inserir(AVL, 28);
	AVL = inserir(AVL, 2);
	AVL = inserir(AVL,  8 );
	AVL = inserir(AVL,  18 );
	AVL = inserir(AVL,  33 );
	AVL = inserir(AVL,  1 );
	AVL = inserir(AVL,  3 );
	AVL = inserir(AVL,  6 );
	AVL = inserir(AVL,  11 );
	AVL = inserir(AVL,  15 );
	AVL = inserir(AVL,  20 );
	AVL = inserir(AVL,  30 );
	AVL = inserir(AVL,  38 );
	AVL = inserir(AVL,  4 );
	AVL = inserir(AVL,  7 );
	AVL = inserir(AVL,  10 );
	AVL = inserir(AVL,  12 );
	AVL = inserir(AVL,  16 );
	AVL = inserir(AVL,  19 );
	AVL = inserir(AVL,  21 );
	AVL = inserir(AVL,  29 );
	AVL = inserir(AVL,  31 );
	AVL = inserir(AVL,  35 );
	AVL = inserir(AVL,  39 );
	AVL = inserir(AVL,  13 );
	AVL = inserir(AVL,  22 );
	AVL = inserir(AVL,  32 );
	AVL = inserir(AVL,  34 );
	AVL = inserir(AVL,  36 );
	AVL = inserir(AVL,  40 );
	AVL = inserir(AVL,  37 );
	*/

	//Questao 3
	AVL = inserir(AVL, "Pedro");
	AVL = inserir(AVL, "Joaquim");
	AVL = inserir(AVL, "Sandra");
	AVL = inserir(AVL, "Daniele");
	AVL = inserir(AVL, "Jhony");
	AVL = inserir(AVL, "Bruna");
	AVL = inserir(AVL, "Roberto");
	AVL = inserir(AVL, "Ricardo");
	AVL = inserir(AVL, "Rafael");
	AVL = inserir(AVL, "Hayana");
	AVL = inserir(AVL, "Lorena");
	AVL = inserir(AVL, "Mariana");
	AVL = inserir(AVL, "Marina");
	AVL = inserir(AVL, "Roberta");
	AVL = inserir(AVL, "Chayene");
	AVL = inserir(AVL, "Edmundo");
	
	

	//AVL = remover (AVL, 'A');
	//AVL = remover (AVL, 'H');
	//AVL = remover (AVL, 'E');
	//AVL = remover (AVL, 'W');
	//AVL = remover (AVL, 'G');
	//AVL = remover (AVL, 'N');
	//AVL = remover (AVL, 'P');
	//AVL = remover (AVL, 'O');

	imprimir_in_order(AVL, 0);

	return 0;
}