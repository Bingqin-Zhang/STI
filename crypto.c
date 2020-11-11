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

void afficher_cle(int* cle, int bit){
	int i;
	for(i = 0; i<bit; i++){
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
	for(i =0 ; i<8 ; i++){
		tab[i] = cle[pos[i]];
	}
	return tab;
}

int* p4(int* cle){
	int pos[4] = {1,3,2,0};
	int i;
	int* tab = (int*) malloc(sizeof(int)*4);
	for(i =0 ; i<4 ; i++){
		tab[i] = cle[pos[i]];
	}
	return tab;
}



int* decalage10(int* cle){
	int pos[10] = {1,2,3,4,0,6,7,8,9,5};
	int i;
	int* tab = (int*) malloc(sizeof(int)*10);
	for(i =0 ; i<10 ; i++){
		tab[i] = cle[pos[i]];
	}
	return tab;
}

int* ou_ex(int* ep, int* k,int bit){
	int i;
	int* tab = (int*) malloc(sizeof(int)*8);
	for(i =0 ; i<bit ; i++){
		if(ep[i] == k[i])
			tab[i] = 0;
		else
			tab[i] = 1;
	}
	return tab;
}


int* F(int* cle,int* k){
	int pos[8] = {3,0,1,2,1,2,3,0};
	int i;
	int* ep = (int*) malloc(sizeof(int)*8);
	int* res = (int*) malloc(sizeof(int)*8);
	int s0[4][4] = {1,0,3,2,3,2,1,0,0,2,1,3,3,1,3,2};
	int s1[4][4] = {0,1,2,3,2,0,1,3,3,0,1,0,2,1,0,3};
	for(i =0 ; i<8 ; i++){
		ep[i] = cle[pos[i]];
	}
	res = ou_ex(ep,k,8);
	
	int row,col;
	row = bin_to_int({res[0],res[3]});
	col = bin_to_int({res[1],res[2]});
	
	int row2,col2;
	row2 = bin_to_int({res[4],res[7]});
	col2 = bin_to_int({res[5],res[6]});
	
	int sortie = s0[row][col];
	int sortie2 = s1[row2][col2];
	
	int* s = int_to_bin(sortie,2);
	int* s2 = int_to_bin(sortie2,2);
	
	int* tab = (int*) malloc(sizeof(int)*4);
	for(i =0 ; i<2 ; i++){
		tab[i] = s[i];
		tab[2+i] = s2[i];
	}
	
	int* p_4 = p4(tab);
	
	return p_4;
}









