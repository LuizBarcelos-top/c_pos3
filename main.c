#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

/*para um ponteiro de ponteiros(matriz) usamos dois **
char** mapa;
int linhas;
int colunas;
*/



int acabou(){
	return 0;
}

int ehdirecao(char direcao) {
	return
		direcao == ESQUERDA || 
		direcao == CIMA ||
		direcao == BAIXO ||
		direcao == DIREITA;
}

void move(char direcao){
	
	if(!ehdirecao(direcao)){
		return;
	}
	/* Após isso, é preciso tirar o pacman antigo do mapa
	m.matriz[heroi.x][heroi.y] = '.';
	Agora faremos um switch case para cada hipotese de movimento seguindo a logica wasd
	*/
	
	int proximox= heroi.x;
	int proximoy= heroi.y;
	
	switch(direcao){
		case ESQUERDA:
			//Caso aperte A, vai para a esquerda
			proximoy--;
			break;
		case CIMA:
			proximox--;
			break;
		case BAIXO:
			proximox++;
			break;
		case DIREITA:
			proximoy++;
			break;
	}
	if(!ehvalida(&m, proximox, proximoy)){
		return;
	}
		

	if(!ehvazia(&m, proximox, proximoy))
		return;
	
	andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
	

	heroi.x = proximox;
	heroi.y = proximoy;

	
}

int main(int argc, char *argv[]) {
	
	lemapa(&m);
	encontramapa(&m, &heroi, HEROI);
	
	
	do{
		imprimemapa(&m);
		
		char comando;
		scanf(" %c", &comando);
		move(comando);
		
	} while(!acabou());


	liberamapa(&m);
}


