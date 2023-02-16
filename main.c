#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//Declarando uma matriz
	char mapa[5][10+1];
	
	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f==0){
		printf("Erro na leitura do mapa");
		exit(1);
	}
	
	//Aqui, percorremos uma matriz usando apenas o i, sem o j. Para isso, colocamos apenas a primeira pos
	for(int i=0; i<5;i++){
		fscanf(f,"%s", mapa[i]);
	}
	
	for(int i=0; i<5;i++){
		printf("%s \n",mapa[i]);
	}
	
	fclose(f);
	
}
