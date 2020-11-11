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
	int* p_10,*p_8,*g,*d,*decG,*decD,*merge;
	//afficher_cle10(tab);
	
	p_10 = p10(tab);
	printf("p10 : ");
	afficher_cle10(p_10);
	
	g = separationG(p_10);
	d = separationD(p_10);
	decG = decalage(g);
	decD = decalage(d);
	merge = unir(decG,decD);
	//afficher_cle5(decG);
	//afficher_cle5(decD);
	printf("merge : ");
	afficher_cle10(merge);
	
	p_8 = p8(merge);
	printf("p8 : ");
	afficher_cle8(p_8);
	
	
	//--------------FREE---------------------------------
	free(text_bin);
    free(rst_ip);
    free(rst_r_ip);
	free(tab);
	free(p_10);
	free(p_8);
	free(g);
	free(d);
	free(decG);
	free(decD);
    return EXIT_SUCCESS;
}















