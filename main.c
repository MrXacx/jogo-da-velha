#include <stdio.h> // input e output
#include <stdlib.h> // usar comandos de prompt (system())
#include <locale.h> // permite caracteres especiais
#include <string.h> // possibilita operações especiais com string  (strcmp())
#include <conio.h> // para usar o getch();
#define TAM_MAT 4
#define TAM_NAME 20
#define OK 200
#define FAIL 418

char tab[TAM_MAT][TAM_MAT], ply1[TAM_NAME], ply2[TAM_NAME];
void name(); // recebe os nomes dos jogadores
void newTab(void); // cria um tabuleiro limpo
void exibe(int w1, int w2); // exibe o tabuleiro e o placar
void coord(int *lin, int *col); // recebe e valida coordenadas
int marca(int lin, int col, int vez); // preenche casas do tabuleiro com 'X' e 'O'
int vitoria(int lin, int col); // analisa vitória 
int main(void){
	
	int vez=2, lin, col, ctr=FAIL,z=0, w1=0,w2=0;
	char run=10;
	
	setlocale(LC_ALL, "Portuguese_Brazil"); 
	printf("\tJOGO DA VELHA\n\n ATENÇÃO: as linhas estão dispostas na HORIZONTAL, enquanto as colunas estão na VERTICAL\n");
    name();
	
	while((int)run==10){
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
		    printf("\n\n VITÓRIA DE %s!\n\n", (vez == 1 ? ply1 : ply2));
		}
		
		exibe(w1,w2);
		printf("\n\n Pressione ENTER para jogar novamente.");
		//run = getch();
		z = 0;
		vez == 1 ? vez++ : vez--;
		ctr=FAIL;
	}
	return 0;
}

void name(){
	
	printf(" \nDefina o nome do jogador 1: ");
	fgets(ply1, 20, stdin);
	do{
		system("cls");
		printf(" Defina o nome do jogador 2: ");
		fflush(stdin);
		fgets(ply2, 20, stdin);
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
	
	if(scanf("%d", lin) != 1 || (*lin >= TAM_MAT || *lin <= 0)){ // trata o input
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
