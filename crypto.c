#include"crypto.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<math.h>

int* char_to_bin(char c, int taille){
    int* rst = int_to_bin(c, taille);
    return rst;
}

int* int_to_bin(int a, int taille){
    int* tmp = (int*) malloc(sizeof(int)*taille);
    int* rst = (int*) malloc(sizeof(int)*taille);
    int i, j, size = 0;
    
    for(i=0; i<taille; i++){
        if(a > 0){
            tmp[i] = a%2;
            a /= 2;
        }
        else { 
/*         Le caractere fait moins de 8 bits*/
            tmp[i] = 0;
        }
    }
    for(j=i-1; j>=0; j--){
        rst[size] = tmp[j];
        size++;
    }
    
    return rst;
}

int bin_to_int(int* t){
    int rst = 0;
    if(t[0] == 1)
        rst += 2;
    if(t[1] == 1)
        rst += 1;

    return rst;
}

int* permute(int* bits, int taille, int etape[taille]){
    int* rst = (int*) malloc(sizeof(int)*taille);
    int i;
    for(i=0; i<taille; i++){
        rst[i] = bits[etape[i]];
    }
    
    return rst;
}

int* cle(int n){
	int i, num;
	int* tab = (int*) malloc(sizeof(int)*n);
	for(i = 0; i<n; i++){
		num = rand() % 2;
		tab[i] = num;
	}
	return tab;
}

void afficher_cle(int* cle, int n){
	int i;
	for(i = 0; i<n; i++){
		printf("%d",cle[i]);
	}
	printf("\n");
}

int* ou_ex(int* t1, int* t2, int n){
	int i;
	int* tab = (int*) malloc(sizeof(int)*n);
	for(i =0 ; i<n ; i++){
		if(t1[i] == t2[i])
			tab[i] = 0;
		else
			tab[i] = 1;
	}
	return tab;
}


int* F(int* cle, int* k, int* P4, int* EP){
	int* ep = permute(cle,8,EP);
	int* res = (int*) malloc(sizeof(int)*8);
	int s0[4][4] = {1,0,3,2,3,2,1,0,0,2,1,3,3,1,3,2};
	int s1[4][4] = {0,1,2,3,2,0,1,3,3,0,1,0,2,1,0,3};
	
	res = ou_ex(ep,k,8);
	
	int t1[2] = {res[0],res[3]};
	int t2[2] = {res[1],res[2]};
	int row = bin_to_int(t1);
	int col = bin_to_int(t2);
	int* sortie = int_to_bin(s0[row][col], 2);

	int t3[2] = {res[4],res[7]};
	int t4[2] = {res[5],res[6]};
	row = bin_to_int(t3);
	col = bin_to_int(t4);

	int* sortie2 = int_to_bin(s1[row][col], 2);
	
	int* tab = unir(sortie, sortie2, 4);
	
	int* p4 = permute(tab,4,P4);

	return p4;
}

int* Fk(int* cle, int* k, int* P4, int* EP){
    int* p4 = F(cle, k, P4, EP);
    int i;
    int* tab = (int*) malloc(sizeof(int)*4);
	for(i =0 ; i<4 ; i++){
		tab[i] = cle[i];
	}
    tab = ou_ex(tab, p4, 4);
   
    for(i =0 ; i<4 ; i++){
		cle[i] = tab[i];
	}

    return cle;
}

int* get_k1(int* key, int* P8, int* P10, int* C_SHIFT){
    return permute(permute(permute(key,10,P10),10,C_SHIFT),8,P8);
}

int* get_k2(int* key, int* P8, int* P10, int* C_SHIFT){
    return permute(permute(permute(permute(permute(key,10,P10),10,C_SHIFT),10,C_SHIFT),10,C_SHIFT),8,P8);
}

int* unir(int* t1, int* t2, int n){
    int i;
    int* rst = (int*) malloc(sizeof(int)*n);
    for(i=0; i< n/2; i++){
        rst[i] = t1[i];
        rst[i+(n/2)] = t2[i];
    }
    
    return rst;
}

int* encryption(int* plaintext, int* k1, int* k2, int* IP, int* RIP, int* LR_SHIFT, int* P4, int* EP){
    int* a = Fk(permute(plaintext,8,IP),k1, P4, EP);
    a = permute(a,8,LR_SHIFT);
    a = Fk(a,k2,P4,EP);
    a = permute(a,8,RIP);

    return a;
}

int* decryption(int* ciphertext, int* k1, int* k2, int* IP, int* RIP, int* LR_SHIFT, int* P4, int* EP){
    int* rst = permute(Fk(permute(Fk(permute(ciphertext,8,IP),k2, P4, EP),8,LR_SHIFT),k1, P4, EP),8,RIP);
    return rst;
}







