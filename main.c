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
    
    
    free(text_bin);
    free(rst_ip);
    free(rst_r_ip);
    
    return EXIT_SUCCESS;
}















