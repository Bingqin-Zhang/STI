#ifndef crypto_H
#define crypto_H

int* char_to_bin(char c, int taille);
int* int_to_bin(int a, int taille);
int bin_to_int();
char bin_to_char(int* tab);
int* permute(int* bits, int taille, int etape[taille]);
int* cle(int taille);
void afficher_cle(int* cle, int bit);
int* ou_ex(int* ep, int* k, int bit);
int* F(int* cle,int* k, int* P4, int* EP);
int* Fk(int* cle, int* k, int* P4, int* EP);
int* get_k1(int* key, int* P8, int* P10, int* C_SHIFT);
int* get_k2(int* key, int* P8, int* P10, int* C_SHIFT);
int* unir(int* t1, int* t2, int taille);
int* encryption(char plaintext, int* k1, int* k2, int* IP, int* RIP, int* LR_SHIFT, int* P4, int* EP);
int* decryption(int* ciphertext, int* k1, int* k2, int* IP, int* RIP, int* LR_SHIFT, int* P4, int* EP);

#endif
