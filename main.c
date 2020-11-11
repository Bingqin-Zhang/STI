#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"crypto.h"

int main(){
    int* original_key = cle(10);
    
    int* k1 = get_k1(original_key);
    int* k2 = get_k2(original_key);
    
    char* c = "c";
    afficher_cle(char_to_bin(c,8),8);

    int* crypte = encryption(c, k1, k2);
    
    afficher_cle(crypte,8);
    
    
    
    int* decrypte = decryption(crypte, k1, k2);
    afficher_cle(decrypte,8);
    
    return EXIT_SUCCESS;
}















