#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"crypto.h"

int main(){
    srand(time(NULL));
    int IP[8] = {1, 5, 2, 0, 3, 7, 4, 6};                               // Permutation initial
    int RIP[8] = {3, 0, 2, 4, 6, 1, 7, 5};                              // Permutation final ( IP^-1)
    int P10[10] = {2,4,1,6,3,9,0,8,7,5};                                // Permutation 10
    int P8[8] = {5,2,6,3,7,4,9,8};                                      // Permutation 8
    int P4[4] = {1,3,2,0};                                              // Permutation 4
    int C_SHIFT[10] = {1,2,3,4,0,6,7,8,9,5};                            // Permutation circulaire de 5 bits de la partie gauche et la partie droite
    int EP[8] = {7,4,5,6,5,6,7,4};                                      // EP correspond a l'expansion/permutation
    int LR_SHIT[8] = {4,5,6,7,0,1,2,3};                                 // Permutation de 4 bits de la partie gauche et la partie droite
    
    char* msg = "H";                                                    // Message a chiffrer, un caractere correspond a 1 octet donc 8 bits
    
    printf("Initial Msg : \n");
    int* texte = char_to_bin(msg[0],8);
    afficher_cle(texte,8);                                                   // Transformation du message en binaire pour l'afficher

    int* crypte = (int*) malloc(sizeof(int)*8);                         // Tableau qui va contenir les 8 bits chiffres
    int* decrypte = (int*) malloc(sizeof(int)*8);                       // Tableau qui va contenir les 8 bits dechiffres
    int* initial_key = cle(10);                                         // Cle initiale de 10 bits generee aleatoirement

    // Get sous-cle k1 et k2
    int* k1 = get_k1(initial_key, P8, P10, C_SHIFT);                    // On cree la sous cle k1
    int* k2 = get_k2(initial_key, P8, P10, C_SHIFT);                    // On cree la sous cle k2
    
    crypte = encryption(texte, k1, k2, IP, RIP, LR_SHIT, P4, EP);      // On chiffre le message initial
    printf("Msg crypte : \n");
    afficher_cle(crypte, 8);                                            // On affiche les 8 bits chiffres
    
    decrypte = decryption(crypte, k1, k2, IP, RIP, LR_SHIT, P4, EP);    // On dechiffre les 8 bits chiffres
    printf("Msg decrypte : \n");
    afficher_cle(decrypte,8);                                           // On affiche le resultat du dechiffrement

    // Liberation de la memoire
    free(crypte);
    free(decrypte);    
    free(k1);
    free(k2);
    
    return EXIT_SUCCESS;
}

