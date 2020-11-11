#ifndef crypto_H
#define crypto_H

int* char_to_bin(char* c);
int* int_to_bin(int a);
int* ip(int* c);
int* rip(int* n);


int* cle();
void afficher_cle(int* cle, int bit);
int* p10(int* cle);
int* p8(int* cle);
int* decalage10(int* cle);
int* ou_ex(int* ep, int* k1,int bit);
int* F(int* cle,int* k1);

#endif
