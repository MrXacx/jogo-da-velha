/*
 Falta fazer:
 - Não deixar que os usuários digitem letras nas coordenadas
 - Otimizar o código
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAM_MAT 4
#define TAM_NAME 20
#define OK 200
#define FAIL 418
char tab[TAM_MAT][TAM_MAT], ply1[TAM_NAME], ply2[TAM_NAME];
void name();
void newTab(void);
void exibe(int w1, int w2);
int marca(int lin, int col, int vez);
int vitoria(int lin, int col);
int main(void){
	int vez=2, lin=0, col=0, ctr=FAIL, z=0, w1=0,w2=0;
	setlocale(LC_ALL, "Portuguese_Brazil");
	name(ply1, ply2);
	newTab();
	while(ctr == FAIL && z<9){
		vez == 1 ? vez++ : vez--;
		do{
			system("cls");
			exibe(w1,w2);
			printf("\n\n Vez de %s jogar!", vez == 1 ? ply1 : ply2);
			printf("\n Defina a linha: ");
			scanf("%d", &lin);
			printf(" Defina a coluna: ");
			scanf("%d", &col);
		} while(marca(lin, col, vez) == FAIL);
		z++;
		if (z > 4){
			ctr = vitoria(lin, col);
		}
	}
	system("cls");
	
	if(ctr == FAIL){
		printf("\n\n DEU VELHA!\n\n");
	}
	else{
		vez == 1 ? w1++ : w2++;
		printf("\n\n VITÓRIA DE %s!\n\n", (vez == 1 ? ply1 : ply2));
	}
	exibe(w1,w2);
	
	return 0;
}
void name(){
	scanf("%s", ply1);
	do{
		scanf("%s", ply2);
	} while(strcmp(ply1,ply2)==0);
}
void newTab(void){
	int i, a;
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
void exibe(int w1, int w2){
	int i, a;
	printf("%s: %d vitórias\n%s: %d vitórias\n\n", ply1, w1,ply2, w2);
	for(i=0; i<TAM_MAT; i++){
		printf("   ");
		for(a=0; a<TAM_MAT; a++){
			printf("%c", tab[i][a]);
			printf( a != TAM_MAT-1 ? "|" : "");
		}
		printf( i != TAM_MAT-1 ? "\n  ----------\n" : "");
	}
}
int marca(int lin, int col, int vez){
	if(tab[lin][col] != ' ' || (lin>=TAM_MAT || col >= TAM_MAT)){
		return FAIL;
	}
	tab[lin][col] = (vez == 1 ? 'X' : 'O');
	return OK;
}
int vitoria(int lin, int col){
	int aux1=1, aux2=1,i;
	for(i=1; i<TAM_MAT; i++){
		if(tab[lin][col] == tab[lin][i] && col != i){
			aux1++;
		}
		if(tab[lin][col] == tab[i][col] && lin != i){
			aux2++;
		}
	}
	if (aux1 == 3 || aux2 == 3){
		return OK;
	}
	else if(lin == col || ((lin * 3) == col || lin == (col * 3))){
		aux1=0;
		aux2=0;
		for(i=1; i<TAM_MAT; i++){
			if(tab[lin][col] == tab[i][i]){
				aux1++;
			}
			if(tab[lin][col] == tab[i][TAM_MAT-i]){
				aux2++;
			}
		}
		if (aux1 == 3 || aux2 == 3){
			return OK;
		}
	}
	return FAIL;
}
