#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"crypto.h"

int main(){

    int IP[8] = {1, 5, 2, 0, 3, 7, 4, 6};  
    int RIP[8] = {3, 0, 2, 4, 6, 1, 7, 5};
    int P10[10] = {2,4,1,6,3,9,0,8,7,5};
    int P8[8] = {5,2,6,3,7,4,9,8};
    int P4[4] = {1,3,2,0};
    int C_SHIFT[10] = {1,2,3,4,0,6,7,8,9,5};
    int EP[8] = {7,4,5,6,5,6,7,4};
    int LR_SHIT[8] = {4,5,6,7,0,1,2,3};
    
    //char* c = "c";
    int c[8] = {1,0,0,1,0,1,1,1};
    //afficher_cle(c,8);
    //printf("Initial text : %c\n", bin_to_char(c));
    //int* initial_key = cle();
    int initial_key[10] = {1, 0, 1, 0, 0, 0, 0 , 0, 1, 0};

    // Get sous-cle k1 et k2
    int* k1 = get_k1(initial_key, P8, P10, C_SHIFT);
    int* k2 = get_k2(initial_key, P8, P10, C_SHIFT);
    
    
    int* crypte = encryption(c, k1, k2, IP, RIP, LR_SHIT, P4, EP);
    //printf("Crypte : %c\n", bin_to_char(crypte));
    afficher_cle(crypte,8);
    int* decrypte = decryption(crypte, k1, k2, IP, RIP, LR_SHIT, P4, EP);
    //printf("decrypte : %c\n", bin_to_char(decrypte));
    afficher_cle(decrypte,8);
    return EXIT_SUCCESS;
}

