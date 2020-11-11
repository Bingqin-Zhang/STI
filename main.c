#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"crypto.h"

int main(){

    srand(time(NULL));
    
    char* text = "d";
    int* text_bin = char_to_bin(text);
    int* rst_ip = ip(text_bin);
    int* rst_r_ip = rip(rst_ip);
    
    //---------------------------------------------------
    //srand(time(NULL)); 
	int* tab = cle();
	int* p_10,*k1,*k2,*dec,*dec2;
	//afficher_cle10(tab);
	
	p_10 = p10(tab);
	printf("p10 : ");
	afficher_cle10(p_10);
	
	
	dec = decalage10(p_10);
	printf("dec : ");
	afficher_cle10(dec);
	
	k1 = p8(dec);
	printf("k1 : ");
	afficher_cle8(k1);
	
	dec2 = decalage10(dec);
	dec2 = decalage10(dec2);
	
	k2 = p8(dec2);
	printf("k2 : ");
	afficher_cle8(k2);
	
	//--------------FREE---------------------------------
	free(text_bin);
    free(rst_ip);
    free(rst_r_ip);
	free(tab);
	free(p_10);
	free(dec);
	free(dec2);
	free(k1);
	free(k2);
    return EXIT_SUCCESS;
}















