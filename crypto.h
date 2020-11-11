#ifndef crypto_H
#define crypto_H

int* char_to_bin(char* c);
int* int_to_bin(int a);
int* ip(int* c);
int* rip(int* n);


int* cle();
void afficher_cle10(int* cle);
void afficher_cle8(int* cle);
void afficher_cle5(int* cle);
int* p10(int* cle);
int* p8(int* cle);
int* decalage10(int* cle);
int* F(int* cle);

#endif
