#include <stdio.h>
#include <stdlib.h>
#include "filaprio.h"
#define MAX 100

typedef struct filap{
	int tam_heap;//tamanho do heap
	int vet_prio[MAX];//vetor que guarda as prioridades
}FilaP;

//fun��o que retona o �ndice do pai de certo valor cujo �ndice desse valor � ind.
int parent(int ind){
	if(ind != 0){
		return (ind - 1)/2;
	}
}

//fun��o que retorna o �ndice do filho esquerdo do valor cujo �ndice � ind.
int left(int ind){
	return (2*ind + 1);
}

//fun��o que retorna o �ndice do filho direito do valor cujo �ndice desse valor � ind.
int right(int ind){
	return (2*ind + 2);
}

//cria uma fila de prioridade vazia.
FilaP* filap_cria(){
	FilaP *fp = (FilaP*) malloc(sizeof(FilaP));
	if(fp == NULL){
		printf("ERRO, MEMORIA INSUFICIENTE!!!");
		exit(1);
	}
	fp->tam_heap = 0;
	return fp;
}

//devolve o elemento de maior prioridade na fila.
int heap_maximum(FilaP* fp){
	return fp->vet_prio[0];
}

//fun��o que faz com que o elemento de maior prioridade seja o primeiro da fila.
void max_heapfy(FilaP* fp, int ind){
	int Left = left(ind);
	int Right = right(ind);
	int maior;
	
	if(Left <= fp->tam_heap && fp->vet_prio[Left] > fp->vet_prio[ind]){
		maior = Left;	
	}else{
		maior = ind;
	}
	
	if(Right <= fp->tam_heap && fp->vet_prio[Right] > fp->vet_prio[maior]){
		maior = Right;
	}
	
	if(maior != ind){
		int aux = fp->vet_prio[ind];
		fp->vet_prio[ind] = fp->vet_prio[maior];
		fp->vet_prio[maior] = aux;//os valores do pai e do filho maior s�o trocados, desde que o filho seja maior que o pai
		max_heapfy(fp, maior);
	}
}

//devolve o elemento de maior prioridade e o retira da fila.
int heap_extract_max(FilaP* fp){
	if(fp->tam_heap < 1){
		printf("ERRO, FILA VAZIA!!!");
	}
	int max = fp->vet_prio[0];//valor m�ximo � o primeiro da fila
	fp->vet_prio[0] = fp->vet_prio[fp->tam_heap - 1];//o �ltimo elemento � colocado na primeira posi��o
	fp->tam_heap--;//tamanho do heap diminui, o maior elemento � extra�do
	max_heapfy(fp, 0);//max_heapfy aplicado na raiz garante que o elemento seja o primeiro
	return max;
}


//modifica a prioridade de determinado elemento no �ndice ind na fila (apenas se chave for maior).
void heap_increase_key(FilaP* fp, int ind, int chave){
	if(chave < fp->vet_prio[ind]){
		printf("ERRO, NOVA CHAVE MENOR QUE A ATUAL!!!\n");
	}
	fp->vet_prio[ind] = chave;
	while(ind > 0 && fp->vet_prio[parent(ind)] < fp->vet_prio[ind]){
		int aux = fp->vet_prio[parent(ind)];//aux recebe o pai do valor que est� no �ndice ind
		fp->vet_prio[parent(ind)] = fp->vet_prio[ind];//o pai de valor que est� no �ndice ind recebe tal valor, o valor de seu filho
		fp->vet_prio[ind] = aux;//o valor que est� no �ndice ind recebe o valor de aux, ou seja, o valor de seu pai
		ind = parent(ind);
	};
}

//insere um novo elemento na fila com prioridade chave.
void max_heap_insert(FilaP* fp, int chave){
	fp->tam_heap++;//O tamanho do heap � aumentado
	fp->vet_prio[fp->tam_heap-1] = -10;/*Um valor negativo � colocado na �ltima posi��o da fila para garantir que a condi��o em
										"heap_increase_key" seja sempre satisfeita (somente chaves positivas s�o consifderadas)*/
	heap_increase_key(fp, fp->tam_heap-1, chave);//essa chamada faz com o valor correto seja adicionado na fila e coloca-o na devida posi��o
}
