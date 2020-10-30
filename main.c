#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int bin[1000], bin_size = 0;

void char_to_int_to_bin(char* c);
void int_to_bin(int a);

int main(){

    srand(time(NULL));
    char* text = "d";
    char_to_int_to_bin(text);
    /*int i; 
    printf("Binaire : \n");  
    for(i=0; i<bin_size; i++){
        printf(" %d", bin[i]);
    }*/
    printf("\n");

    return EXIT_SUCCESS;
}

/** Fonction qui prend une chaine de caracteres et renvoie son entier selon la table ASCII

    @param c la chaine de caracteres à covertir
    @return la conversion en entier
*/
void char_to_int_to_bin(char* c){
    int i;
    for(i=0; i < strlen(c); i++ ){
        int tmp = c[i];
        int_to_bin(tmp);
    }
}

/** Fonction qui prend un entier et renvoie son equivalent en binaire

    @param a l'entier à covertir
    @return la conversion en binaire
*/
void int_to_bin(int a){
    int tmp[1000];
    int i, j;
    
    for(i=0; i<8; i++){
        if(a > 0){
            tmp[i] = a%2;
            a /= 2;
        }
        else{
            tmp[i] = 0;
        }
    }

    for(j=i-1; j>=0; j--){
        bin[bin_size] = tmp[j];
        printf(" %d", bin[bin_size]);
        
    }printf("\n");
}
















