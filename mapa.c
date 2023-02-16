#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino){
	char personagem = m->matriz[xorigem][yorigem];
	m->matriz[xdestino][ydestino]=personagem;
	m->matriz[xorigem][yorigem]=VAZIO;
}

void encontramapa(MAPA* m, POSICAO* p, char c){
	// agora vamos percorrer a matriz para tentar achar o pacman (@). 
	for (int i = 0; i < m->linhas; i++){
		for(int j = 0; j < m->colunas; j++){	
	// Quando encontrar, ele assume acoordenada
			if(m->matriz[i][j]==c){
				p->x = i;
				p->y = j;
				break;
			}
		}
	}
}

void liberamapa(MAPA* m){
		/*Sempre que alocamos mem�ria dinamicamente, precisamos depois liberar ela, ou sen�o ficar� muito
	pesado e invi�vel-> Para isso, usamos free-> No caso do mapa, precisamos antes liberar as colunas, e
	depois liberar os espa�oes das linhas-> Pois na verdade temos um array de arrays, isso �, um ponteiro
	de ponteiros, de modo a antes precisarmos liberar os espa�os do array "filho" e depois os 
	espa�os do array "pai"
	*/
	for(int i = 0; i<m->linhas;i++){
		free(m->matriz[i]);
	}
	free(m->matriz);
}

void alocamapa(MAPA* m){	
	/*
	Malloc significa aloca��o de mem�ria, aqui estamos liberando o espa�o para os ponteiros apontarem o
	lugar que ficar� reservado para a linha, e em seguida um for para alocar em cada espa�o reservado a
	qtd de linhas-> 
	*/
	m->matriz = malloc(sizeof(char*)*m->linhas);
	for(int i=0;i<m->linhas;i++){
		m->matriz[i]=malloc (sizeof(char) * (m->colunas+1) );
	}
}

void lemapa(MAPA* m){
	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f==0){
		printf("Erro na leitura do mapa");
		exit(1);
	}
	/*
	Agora, irei fazer uma matriz com aloca��o din�mica de mem�ria, pois o tamanho do mapa pode mudar-> Para
	Isso, usamos o malloc, que aloca o espa�o suficiente para suprir a qtd necess�ria de mem�ria da vari�vel
	linhas-> Linhas e Colunas foram feitas lendo o arquivo mapa->txt, e padronizei que na primeira linha dele
	estariam informa��es sobre a qtd de linhas e colunas, respectivamente-> O mapa, linhas e colunas s�o
	vari�veis globais, pois as utilizaremos ao longo de todo o projeto->
	//Aqui, imprimiremos os numeros do mapa->txt nas variaveis globais linhas e colunas
	*/
	fscanf(f,"%d %d", &(m->linhas), &(m->colunas));
	alocamapa(m);
	//Aqui, percorremos uma matriz usando apenas o i, sem o j-> Para isso, colocamos apenas a primeira pos
	for(int i=0; i<5;i++){
		fscanf(f,"%s", m->matriz[i]);
	}
	fclose(f);
}

void imprimemapa(MAPA* m){
	for(int i=0; i<5;i++){
		printf("%s \n",m->matriz[i]);
	}
}

int ehvalida(MAPA* m, int x, int y) {
	if(x >= m->linhas) 
		return 0;
	if(y >= m->colunas) 
		return 0;

	return 1;	
}

int ehvazia(MAPA* m, int x, int y) {
	return m->matriz[x][y] == VAZIO;
}
