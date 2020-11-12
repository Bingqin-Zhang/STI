#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"crypto.h"

int main(){
    srand(time(NULL));
    int IP[8] = {1, 5, 2, 0, 3, 7, 4, 6};   
    int RIP[8] = {3, 0, 2, 4, 6, 1, 7, 5};
    int P10[10] = {2,4,1,6,3,9,0,8,7,5};
    int P8[8] = {5,2,6,3,7,4,9,8};
    int P4[4] = {1,3,2,0};
    int C_SHIFT[10] = {1,2,3,4,0,6,7,8,9,5};
    int EP[8] = {7,4,5,6,5,6,7,4};
    int LR_SHIT[8] = {4,5,6,7,0,1,2,3};
    
    char* msg = "H";
    
    printf("Initial Msg : \n");
    afficher_cle(char_to_bin(msg[0],8),8);

    int* crypte = (int*) malloc(sizeof(int)*8);
    int* decrypte = (int*) malloc(sizeof(int)*8);
    int* initial_key = cle(10);

    // Get sous-cle k1 et k2
    int* k1 = get_k1(initial_key, P8, P10, C_SHIFT);
    int* k2 = get_k2(initial_key, P8, P10, C_SHIFT);
    
    crypte = encryption(msg[0], k1, k2, IP, RIP, LR_SHIT, P4, EP);
    printf("Msg crypte : \n");
    afficher_cle(crypte, 8);
    
    decrypte = decryption(crypte, k1, k2, IP, RIP, LR_SHIT, P4, EP);
    printf("Msg decrypte : \n");
    afficher_cle(decrypte,8);

    return EXIT_SUCCESS;
}

