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
	int* tab = cle();
	int* p_10,*k1,*k2,*dec,*dec2,*EP;
	
	p_10 = p10(tab);
	printf("p10 : ");
	afficher_cle(p_10,10);
	
	
	dec = decalage10(p_10);
	printf("dec : ");
	afficher_cle(dec,10);
	
	k1 = p8(dec);
	printf("k1 : ");
	afficher_cle(k1,8);
	
	dec2 = decalage10(dec);
	dec2 = decalage10(dec2);
	
	k2 = p8(dec2);
	printf("k2 : ");
	afficher_cle(k2,8);
	
	int pos[4] = {1,0,1,1};
	EP = F(pos,k1);
	afficher_cle(EP,8);
	
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
	free(EP);
    return EXIT_SUCCESS;
}















