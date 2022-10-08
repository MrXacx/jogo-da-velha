/*
 Falta fazer:
 - Função que checa se o jogo deu velha
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM_MAT 4
#define TAM_NAME 20
#define TRUE 500
#define FALSE 340
char tab[TAM_MAT][TAM_MAT];
void name(char ply1[TAM_NAME], char ply2[TAM_NAME]);
void newTab(void);
void exibeTab();
unsigned int marca(unsigned int lin, unsigned int col, unsigned int vez);
unsigned int vitoria(unsigned int lin, unsigned int col);
unsigned int velha(void);
int main(void){
	unsigned int vez=2, lin=0, col=0, ctr=FALSE, z=0;
	char ply1[TAM_NAME], ply2[TAM_NAME];
	setlocale(LC_ALL, "Portuguese_Brazil");
	name(ply1, ply2);
	newTab();
	while(ctr == FALSE){
		vez == 1 ? vez++ : vez--;
		do{
			system("clear");
			exibeTab();
			printf("\n\nVez de %s jogar!", vez == 1 ? ply1 : ply2);
			printf("\nDefina a linha: ");
			scanf("%d", &lin);
			printf("Defina a coluna: ");
			scanf("%d", &col);
		} while(marca(lin, col, vez) == FALSE);
		z++;
		if (z > 4){
			ctr = vitoria(lin, col);
		}
	}
	system("clear");
	exibeTab();
	printf("\nParabéns, %s, você ganhou!\n", (vez == 1 ? ply1 : ply2));
	return 0;
}
void name(char ply1[TAM_NAME], char ply2[TAM_NAME]){
	scanf("%s %s", ply1, ply2);
}
void newTab(void){
	unsigned int i, a;
	for(i=1; i<TAM_MAT; i++){
		tab[0][i] = i + '0';
		tab[i][0] = i + '0';
	}
	for(i=1; i<TAM_MAT; i++){
		for(a=1; a<TAM_MAT; a++){
			tab[i][a] = ' ';
		}
	}
	tab[0][0] = ' ';
}
void exibeTab(){
	unsigned int i, a;
	for(i=0; i<TAM_MAT; i++){
		for(a=0; a<TAM_MAT; a++){
			printf("%c|", tab[i][a]);
		}
		printf( i != TAM_MAT-1 ? "\n---------\n" : "");
	}
}
unsigned int marca(unsigned int lin, unsigned int col, unsigned int vez){
	if(tab[lin][col] != ' ' || (lin>=TAM_MAT || col >= TAM_MAT)){
		return FALSE;
	}
	tab[lin][col] = (vez == 1 ? 'X' : 'O');
	return TRUE;
}
unsigned int vitoria(unsigned int lin, unsigned int col){
	int nLin=1, nCol=1, nDp=0, nDs=0,i;
	
	for(i=1; i<TAM_MAT; i++){
		if(tab[lin][col] == tab[lin][i] && col != i){
			nLin++;
		}
		if(tab[lin][col] == tab[i][col] && lin != i){
			nCol++;
		}
	}
	if (nLin == 3 || nCol == 3){
		return TRUE;
	}
	else if(lin == col || ( (lin * 3) == col || lin == (col * 3))){
		for(i=1; i<TAM_MAT; i++){
			if(tab[lin][col] == tab[i][i]){
				nDp++;
			}
			if(tab[lin][col] == tab[i][TAM_MAT-i]){
				nDs++;
			}
		}
	}
	if (nDp == 3 || nDs == 3){
		return TRUE;
	}
	else{
		return FALSE;
	}
}
