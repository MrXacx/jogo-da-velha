#include <stdio.h> //INPUT E OUTPUT
#include <stdlib.h> //LIMPAR A TELA COM SYSTEM("CLS")
#include <locale.h> //PERMITIR DE CARACTERES ESPECIAIS (EX: ACENTOS E "Ç")
#include <string.h> //POSSIBILITA FUNÇÕES STRING (EX: COMPARAÇÃO DE CARACTERES ENTRE STRINGS, "strcmp()".
#include <conio.h> //PARA UTILIZAÇÃO DO GETCHAR()
#define TAM_MAT 4
#define TAM_NAME 20
#define OK 200
#define FAIL 418

char tab[TAM_MAT][TAM_MAT], ply1[TAM_NAME], ply2[TAM_NAME];
void name(); //DEFINE O NOME DO JOGADOR E IMPEDE NOMES IGUAIS
void newTab(void); 
void exibe(int w1, int w2); //FAZ A CONTABILIZAÇÃO DAS VITÓRIAS
void coord(int *lin, int *col); //DEFINE O QUE PODE OU NÃO COLOCAR NAS COORDENADAS
int marca(int lin, int col, int vez); //POSSIBILITA A MARCAÇÃO COM 'X' E 'O'
int vitoria(int lin, int col); //DETERMINA A VITÓRIA VERIFICANDO AS SEQUÊNCIAS
int main(void){
	
	int vez=2, lin, col, ctr=FAIL,z=0, w1=0,w2=0;
	char run='s';
	
	setlocale(LC_ALL, "Portuguese_Brazil"); 
	printf("\tJOGO DA VELHA\n\n");
	printf("LINHAS SÃO HORIZONTAIS ENQUANTO COLUNAS SÃO VERTICAIS\n");
    name();
	
	while(run=='s' || run=='S'){
		newTab();

		do{
		   vez == 1 ? vez++ : vez--;
			
			do{
			   system("cls");
			   exibe(w1,w2);
			   printf("\n\n Vez de %s jogar!", vez == 1 ? ply1 : ply2);
			   coord(&lin,&col);
			}while(marca(lin, col, vez) == FAIL);
			z++;
			
			if (z > 4){
				ctr = vitoria(lin, col);
			}
		}while(ctr == FAIL && z<9);
		system("cls");
		
		if(ctr == FAIL){
			printf("\n\n DEU VELHA!\n\n");
		}
		
		else{
		    vez == 1 ? w1++ : w2++;
		    printf(" VITÓRIA DE %s!\n\n", (vez == 1 ? ply1 : ply2));
		}
		
		exibe(w1,w2);
		printf("\n\n Digite 's' para jogar novamente.");
		run = getch();
		z = 0;
		vez == 1 ? vez++ : vez--;
		ctr=FAIL;
	}
	return 0;
}

void name(){
	
	printf(" \nDefina o nome do jogador 1: ");
	scanf("%s", ply1);
	
	do{
		system("cls");
		printf(" Defina o nome do jogador 2: ");
		scanf("%s", ply2);
	}while(strcmp(ply1,ply2)==0);
}

void newTab(void){
	
	int i, a;
	
	for(i=0; i<TAM_MAT; i++){
		tab[0][i] = i + '0';
		tab[i][0] = i + '0';
	}
	
	for(i=1; i<TAM_MAT; i++){
		for(a=1; a<TAM_MAT; a++){
			tab[i][a] = ' ';
		}
	}
}

void exibe(int w1, int w2){
	
	int i, a;
	printf(" %s: %d vitórias\n %s: %d vitórias\n\n", ply1, w1,ply2, w2);
	
	for(i=0; i<TAM_MAT; i++){
		printf("   ");
		
		for(a=0; a<TAM_MAT; a++){
			printf("%c", tab[i][a]);
			printf( a != TAM_MAT-1 ? "|" : "");
		}
		
		printf( i != TAM_MAT-1 ? "\n  ----------\n" : "");
		
	}
}

void coord(int *lin, int *col){
	
	printf("\n Defina a linha: ");	
	
	if(scanf("%d", lin) != 1 || (*lin >= TAM_MAT || *lin <= 0)){ //FAZ O TRATAMENTO PARA LIMITAR O QUE O JOGADOR DIGITA
		getchar();
		*lin = 0;
		return;
	}
	
	printf(" Defina a coluna: ");
	if(scanf("%d", col) != 1 || (*col >= TAM_MAT || *col <= 0)){
		getchar();
		*col = 0;
		return;
	}
}

int marca(int lin, int col, int vez){
	
	if(tab[lin][col] != ' '){
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
