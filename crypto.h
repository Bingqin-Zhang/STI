#ifndef crypto_H
#define crypto_H

int* char_to_bin(char* c, int taille);
int* int_to_bin(int a, int taille);
int bin_to_int();
int* ip(int* c);
int* rip(int* n);


int* cle(int taille);
void afficher_cle(int* cle, int bit);
int* p10(int* cle);
int* p8(int* cle);
int* p4(int* cle);
int* decalage(int* cle);
int* ou_ex(int* ep, int* k, int bit);
int* F(int* cle,int* k);
int* SW(int* cle, int taille);

int* get_k1(int* key);
int* get_k2(int* key);
int* unir(int* t1, int* t2, int taille);
int* encryption(char* plaintext, int* k1, int* k2);
int* decryption(int* ciphertext, int* k1, int* k2);

#endif
