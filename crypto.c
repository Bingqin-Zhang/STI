#include"crypto.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

/** Fonction qui prend une chaine de caracteres et renvoie son evriture en binaire

    @param c la chaine de caracteres à convertir
    @return la conversion en binaire
*/
int* char_to_bin(char* c){
    int* rst;
    int i;
    for(i=0; i<strlen(c); i++){
        int tmp = c[i];
        rst = int_to_bin(tmp);
    }
    
    return rst;
}

/** Fonction qui prend un entier et renvoie son equivalent en binaire

    @param a l'entier à covertir
    @return la conversion en binaire
*/
int* int_to_bin(int a){
    int* tmp = (int*) malloc(sizeof(int)*8);
    int* rst = (int*) malloc(sizeof(int)*8);
    int i, j, size = 0;
    
    for(i=0; i<8; i++){
        if(a > 0){
            tmp[i] = a%2;
            a /= 2;
        }
        else { 
/*         Le caracteres fait moins de 8 bits*/
            tmp[i] = 0;
        }
    }
    printf("Texte brut en binaire :");
    for(j=i-1; j>=0; j--){
        rst[size] = tmp[j];
        printf(" %d", rst[size]);
        size++;
        
    }
    printf("\n");
    
    return rst;
}

/** Fonction qui cree IP a partir des bits du texe brut

    @param 
    @return
*/
int* ip(int* text){
    int pos[8] = {1, 5, 2, 0, 3, 7, 4, 6};
    int* rst = (int*) malloc(sizeof(int)*8);
    int i;
    printf("IP :");
    for(i=0; i<8; i++){
        rst[i] = text[pos[i]];
        printf(" %d", rst[i]);
    }
    printf("\n");
    
    return rst;
}

/** Fonction qui cree IP a partir des bits du texe brut

    @param 
    @return
*/
int* rip(int* n){
    int pos[8] = {1, 5, 2, 0, 3, 7, 4, 6};
    int* rst = (int*) malloc(sizeof(int)*8);
    int i;
    printf("Reverse IP :");
    for(i=0; i<8; i++){
        rst[i] = n[pos[i]];
        printf(" %d", rst[i]);
    }
    printf("\n");
    
    return rst;
}




int* cle(){
	int i, num;
	int* tab = (int*) malloc(sizeof(int)*10);
	for(i = 0; i<10; i++){
		num = rand() % 2;
		tab[i] = num;
	}
	return tab;
}

void afficher_cle10(int* cle){
	int i;
	for(i = 0; i<10; i++){
		printf("%d",cle[i]);
	}
	printf("\n");
}

void afficher_cle8(int* cle){
	int i;
	for(i = 0; i<8; i++){
		printf("%d",cle[i]);
	}
	printf("\n");
}

void afficher_cle5(int* cle){
	int i;
	for(i = 0; i<5; i++){
		printf("%d",cle[i]);
	}
	printf("\n");
}

int* p10(int* cle){
	int pos[10] = {2,4,1,6,3,9,0,8,7,5};
	int i;
	int* tab = (int*) malloc(sizeof(int)*10);
	for(i =0 ; i<10 ; i++){
		tab[i] = cle[pos[i]];
	}
	return tab;
}

int* p8(int* cle){
	int pos[8] = {5,2,6,3,7,4,9,8};
	int i;
	int* tab = (int*) malloc(sizeof(int)*8);
	for(i =0 ; i<10 ; i++){
		tab[i] = cle[pos[i]];
	}
	return tab;
}

int* separationG(int* cle){
	int i;
	int* tab = (int*) malloc(sizeof(int)*5);
	for(i =0 ; i<5 ; i++){
		tab[i] = cle[i];
	}
	return tab;
}

int* separationD(int* cle){
	int i;
	int* tab = (int*) malloc(sizeof(int)*5);
	for(i =0 ; i<5 ; i++){
		tab[i] = cle[i+5];
	}
	return tab;
}

int* decalage(int* cle){
	int pos[5] = {4,3,2,1,0};
	int i;
	int* tab = (int*) malloc(sizeof(int)*5);
	for(i =0 ; i<5 ; i++){
		tab[i] = cle[pos[i]];
	}
	return tab;
}

int* unir(int* cle1, int* cle2){
	int i;
	int* tab = (int*) malloc(sizeof(int)*10);
	for(i =0 ; i<5 ; i++){
		tab[i] = cle1[i];
		tab[5+i] = cle2[i];
	}
	return tab;
}















