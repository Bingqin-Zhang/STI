#ifndef crypto_H
#define crypto_H

/** Fonction qui prend un caractere et renvoie son ecriture en binaire

    @param c le caracteres
    @return la conversion en binaire
*/
int* char_to_bin(char c, int taille);

/** Fonction qui prend un entier et renvoie son equivalent en binaire

    @param a un entier
    @return la conversion en binaire
*/
int* int_to_bin(int a, int taille);

/** Fonction qui prend du binaire et renvoie son equivalent en entier (utilise pour les SBOX)

    @param t un tableau de 2 bits
    @return la conversion en entier
*/
int bin_to_int(int* t);

/** Fonction qui execute une permution sur des bits selon le type de permutation

    @param bits un tableau de bits
    @param taille le nombe de bits
    @param etape represente le type de permutation
    @return rst le resultat de la permutation sur les bits
*/
int* permute(int* bits, int taille, int etape[taille]);

/** Fonction qui initialise une cle aleatoire de n bits

    @param n le nombre de bits
    @return un tab contenant la cle
*/
int* cle(int n);

/** Fonction qui permet d'afficher un tableau de n bits

    @param cle les bits
    @param n le nombre de bits
    @return
*/
void afficher_cle(int* cle, int n);

/** Fonction qui fait l'operation XOR sur n bits entre t1 et t2

    @param t1 un tableau de n bits
    @param t2 un tableau de n bits
    @param n le nombre de bits
    @return le resultat du XOR sur t1 avec t2
*/
int* ou_ex(int* t1, int* t2, int n);

/** Fonction qui prend une cle puis utilise les 4 bits de droite pour cree 8 bits avec EP. Par la suite, on fait un XOR sur le resultat precedent et k, puis on utilise le resultat pour utiliser les SBOX ce qui nous donnera 4 bits en sortie qui subira la permutation P4.

    @param cle la cle de 8 bits
    @param k une sous cle
    @param P4 la permutation 4
    @param EP l'expansion/permutation
    @return un tableau de 4 bits
*/
int* F(int* cle, int* k, int* P4, int* EP);

/** Fonction qui execute un XOR sur les 4 bits de gauche de la cle avec le resultat de la fonction F

    @param cle la cle de 8 bits
    @param k une sous cle
    @param P4 la permutation 4
    @param EP l'expansion/permutation
    @return un tableau de 8 bits
*/
int* Fk(int* cle, int* k, int* P4, int* EP);

/** Fonction qui genere la sous cle k1

    @param key cle initiale
    @param P8 la permutation 8
    @param p10 la permutation 10
    @param C_SHIFT la permutation circulaire
    @return la sous cle k1
*/
int* get_k1(int* key, int* P8, int* P10, int* C_SHIFT);

/** Fonction qui genere la sous cle k2

    @param key cle initiale
    @param P8 la permutation 8
    @param p10 la permutation 10
    @param C_SHIFT la permutation circulaire
    @return la sous cle k2
*/
int* get_k2(int* key, int* P8, int* P10, int* C_SHIFT);

/** Fonction qui fait l'union de 2 blocs de n/2 bits

    @param t1 le premier bloc de n/2 bits 
    @param t2 le deuxieme bloc de n/2 bits
    @param n la taille de l'union des deux blocs
    @return le bloc de n bits
*/
int* unir(int* t1, int* t2, int n);

/** Fonction qui chiffre un bloc de 8 bits

    @param plaintext le bloc de bits a chiffrer
    @param k1 la sous cle k1
    @param k2 la sous cle k2
    @param IP la permutation initiale
    @param RIP la permutation finale
    @param LR_SHIFT la permutation gauche droite
    @param P4 la permutation 4
    @param EP l'expansion/permutation
    @return le bloc de bits chiffre
*/
int* encryption(int* plaintext, int* k1, int* k2, int* IP, int* RIP, int* LR_SHIFT, int* P4, int* EP);

/** Fonction qui dechiffre un bloc de 8 bits chiffrer

    @param ciphertext le bloc de bits a dechiffrer
    @param k1 la sous cle k1
    @param k2 la sous cle k2
    @param IP la permutation initiale
    @param RIP la permutation finale
    @param LR_SHIFT la permutation gauche droite
    @param P4 la permutation 4
    @param EP l'expansion/permutation
    @return le bloc de bits dechiffre
*/
int* decryption(int* ciphertext, int* k1, int* k2, int* IP, int* RIP, int* LR_SHIFT, int* P4, int* EP);


#endif
