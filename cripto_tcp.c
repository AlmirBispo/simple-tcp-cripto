////////////////////////////////////////////////////////////////////////////////////
//Yehovah is the holly name
//Funcao que permite encriptacao e decriptacao em comunicacao tcp
//autor: Almir Bispo
//data: 18/08/2024
////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

char enc[36]="";
char dec[36]="";
char msg[512]="";

//////////////////////////////////Encripta //////////////////////////////////
/*
adata: message
akey: private key
step:integer
*/
char* encode_node(const char* adata, const char* akey, int step) {
    int i;
    int part;
    size_t length = strlen(adata);
    char* enc = (char*)malloc(length + 1);
    enc[0] = '\0'; // Initialize the string

    for (i = 0; i < length; i++) {
        part = (int)akey[i];
        enc[i] = (char)((int)adata[i] + (step << 2) + (part >> 2));
    }
    enc[length] = '\0'; // Null-terminate the string
    return enc;
}
/*
adata: message
akey: private key
step:integer
*/
char* decode_node(const char* adata, const char* akey, int step) {
    int i;
    int part;
    size_t length = strlen(adata);
    char* enc = (char*)malloc(length + 1);
    enc[0] = '\0'; // Initialize the string

    for (i = 0; i < length; i++) {
        part = (int)akey[i];
        enc[i] = (char)((int)adata[i] - (step << 2) - (part >> 2));
    }
    enc[length] = '\0'; // Null-terminate the string
    return enc;
}

////////////////////////////////////////////////////////////////////

/*
Exemplo
	char key[36]="ndckdhncjdncsdf84dj45nf844h484h844j";
	char msg[50]="";
    strcpy(msg , encode_node( "Pastel", key, 0xddfa) );
    printf("%s" , "Criptografado\n");
    printf("%s" , msg);
    printf("%s" , "\nDescriptografado\n");
    printf("%s" ,decode_node( msg  ,key ,0xddfa)  );
*/
