#include"crypto.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<math.h>

int* char_to_bin(char c, int taille){
    int* rst = int_to_bin((int) c, taille); // On converti notre caractère en binaire
    return rst;
}

int* int_to_bin(int a, int taille){ // a notre caractere transformé en entier et taille le nombre de bits qu'on veux dans le tableau rst
    int* tmp = (int*) malloc(sizeof(int)*taille); //On alloue de la memoire 
    int* rst = (int*) malloc(sizeof(int)*taille); //On alloue de la memoire 
    int i, j, size = 0;
    
    for(i=0; i<taille; i++){
        if(a > 0){      // Tant que a est supérieur à 0 on fait la division euclidienne
            tmp[i] = a%2;
            a /= 2;
        }
        else {          //On a obtenu moins de bits que la taille esperee alors on comble avec des 0
         
            tmp[i] = 0;
        }
    }
    for(j=i-1; j>=0; j--){      // On renverse le tableau pour l'écriture binaire de base 2
        rst[size] = tmp[j];
        size++;
    }
    
    return rst;
}

int bin_to_int(int* t){
    // Fonction exclusivement reservee pour la conversion en binaire des resultat obtenus avec les SBOX
    int rst = 0;
    if(t[0] == 1)
        rst += 2;
    if(t[1] == 1)
        rst += 1;

    return rst;
}

int* permute(int* bits, int taille, int etape[taille]){
    int* rst = (int*) malloc(sizeof(int)*taille); //On alloue de la memoire 
    int i;
    for(i=0; i<taille; i++){
        rst[i] = bits[etape[i]]; // Ici on echange chaque bit de place en suivant les positions qui sont dans le tableau etape 
        //le changement s'effectue en fonction du type de permutation que l'on doit procéder
    }
    
    return rst;
}

int* cle(int n){
	int i, num;
	int* tab = (int*) malloc(sizeof(int)*n); //On alloue de la memoire
	for(i = 0; i<n; i++){
		num = rand() % 2; // On choisit un nombre aléatoire soit 0 soit 1
		tab[i] = num; // Ce nombre est affecté à un tableau d'entier qui sera le tableau qui contiendra n bits
	}
	return tab; // On retourne le tableau de n bits
}

void afficher_cle(int* cle, int n){
	int i;
	for(i = 0; i<n; i++){
		printf("%d",cle[i]); // Ici on affiche la cle (avec un bloc de n bits)
	}
	printf("\n");
}

int* ou_ex(int* t1, int* t2, int n){
	int i;
	int* tab = (int*) malloc(sizeof(int)*n); //On alloue de la memoire
	for(i =0 ; i<n ; i++){
		if(t1[i] == t2[i]) 
			tab[i] = 0; // Si les deux bits sont identique alors on a 0
		else
			tab[i] = 1; // Si les deux bits ne sont pas identique alors on a 1
	}
	return tab; // On retourne le tableau resultat de l'operation xor sur chacun des n bits
}


int* F(int* cle, int* k, int* P4, int* EP){
	int* ep = permute(cle,8,EP); // On effectue notre expansion permutation de notre cle
	int* res = (int*) malloc(sizeof(int)*8); //On alloue de la memoire
	int s0[4][4] = {1,0,3,2,3,2,1,0,0,2,1,3,3,1,3,2}; //Sbox 0
	int s1[4][4] = {0,1,2,3,2,0,1,3,3,0,1,0,2,1,0,3}; //Sbox 1
	
	res = ou_ex(ep,k,8); // On effectue le ou exclusif entre ep et la sous cle k qu'on stocke dans res
	
	int t1[2] = {res[0],res[3]}; // t1 contient le premier et le quatrieme bit de notre xor entre ep et k
	int t2[2] = {res[1],res[2]}; // t2 contient le deuxieme et le troisieme bit de notre xor entre ep et k
	int row = bin_to_int(t1); // row la ligne correspond à l'entier que désigne t1 (on convertit nos deux bits en entier)
	int col = bin_to_int(t2); // col la colonne correspond à l'entier que désigne t2 (on convertit nos deux bits en entier)
	int* sortie = int_to_bin(s0[row][col], 2); // sortie va chercher dans la premiere sbox l'entier qui se trouve à la ligne row et à la colonne col et puis convertir cet entier en binaire 

	int t3[2] = {res[4],res[7]}; // t3 contient le cinquieme et le huitieme bit de notre xor entre ep et k
	int t4[2] = {res[5],res[6]}; // t4 contient le sixieme et le septieme bit de notre xor entre ep et k
	row = bin_to_int(t3); // row la ligne correspond à l'entier que désigne t3 (on convertit nos deux bits en entier)
	col = bin_to_int(t4); // col la colonne correspond à l'entier que désigne t4 (on convertit nos deux bits en entier)

	int* sortie2 = int_to_bin(s1[row][col], 2); // sortie2 va chercher dans la deuxieme Sbox l'entier qui se trouve à la ligne row et à la colonne col et puis convertir cet entier en binaire
	
	int* tab = unir(sortie, sortie2, 4); // tab contient l'union des 2 bits de sortie et les 2 deux bits de sortie2
	
	int* p4 = permute(tab,4,P4); // On effectue la permutation 4 sur notre tab

	return p4; // On renvoie le resultat qu'on a obtenue de la permutation 4
}

int* Fk(int* cle, int* k, int* P4, int* EP){
    int* p4 = F(cle, k, P4, EP); // p4 va contenir le resultat de la fonction F en prenant un bloc de 8 bits cle et notre sous cle k
    int i;
    int* tab = (int*) malloc(sizeof(int)*4); //On alloue de la memoire
	for(i =0 ; i<4 ; i++){
		tab[i] = cle[i]; // tab va prendre les 4 premieres valeurs de cle
	}
    tab = ou_ex(tab, p4, 4); // On va faire un ou exclusif entre tab et p4 (le resultat de F) et on le stocke dans tab
   
    for(i =0 ; i<4 ; i++){
		cle[i] = tab[i]; // On remplace les 4 premiers bits de cle par les 4 bits obtenus danss tab 
	}

    return cle; // On retourne donc notre cle ainsi modifiée
}

int* get_k1(int* key, int* P8, int* P10, int* C_SHIFT){
    return permute(permute(permute(key,10,P10),10,C_SHIFT),8,P8); // Ici on génère notre sous cle k1 avec la permutation 10, la rotation circulaire, et la permutation 8
}

int* get_k2(int* key, int* P8, int* P10, int* C_SHIFT){
    return permute(permute(permute(permute(permute(key,10,P10),10,C_SHIFT),10,C_SHIFT),10,C_SHIFT),8,P8); //On génère ici la sous cle k2 avec la permutation 10, trois rotations circulaires, et la permutation 8
}

int* unir(int* t1, int* t2, int n){
    int i;
    int* rst = (int*) malloc(sizeof(int)*n); //On alloue de la memoire
    for(i=0; i< n/2; i++){
        rst[i] = t1[i]; // Puisque t1 et t2 sont de taille n/2 bits, alors on commence à mettre tous les éléments de t1 dans res
        rst[i+(n/2)] = t2[i]; // Puis on ajoute tous les éléments de t2
    }
    
    return rst; // le tableau res contenant l'union des deux tabeaux de bits
}

int* encryption(int* plaintext, int* k1, int* k2, int* IP, int* RIP, int* LR_SHIFT, int* P4, int* EP){
    int* a = Fk(permute(plaintext,8,IP),k1, P4, EP); // Pour encrypter notre plaintext on commence par effectuer la fonction Fk sur la permutation initiale de plaintext et k1 notre sous cle
    a = permute(a,8,LR_SHIFT); // Ensuite on échange les 4 bits les plus à gauche avec les 4 bits les plus à droite
    a = Fk(a,k2,P4,EP); // On effectue la fonction Fk sur 4 les bits les plus à gauche (ceux qui étaient inchangés) avec la sous cle k2
    a = permute(a,8,RIP); // Enfin on fait la permutation finale

    return a;
}

int* decryption(int* ciphertext, int* k1, int* k2, int* IP, int* RIP, int* LR_SHIFT, int* P4, int* EP){
    int* rst = permute(Fk(permute(Fk(permute(ciphertext,8,IP),k2, P4, EP),8,LR_SHIFT),k1, P4, EP),8,RIP); // Pour decrypter notre ciphertext (texte chiffré) on commence par effectuer la fonction Fk sur la permutation initiale de plaintext et k2 notre sous cle. Ensuite on échange les 4 bits les plus à gauche avec les 4 bits les plus à droite. On effectue la fonction Fk sur 4 les bits les plus à gauche (ceux qui étaient inchangés) avec la sous cle k1. Enfin on fait la permutation finale.
    return rst;
}







