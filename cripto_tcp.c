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
 astr:texto a ser criptografado  (ate 36 bytes)
 akey:chave (ate 36 bytes)
 step: values 0x0000 ate 0xffff
*/
char *encode_node(char *astr ,char *akey ,long int step)
{
	int i=0;
	for (i = 0 ;i<strlen(astr);++i )
	{
		enc[i]= (astr[i]) + (step << 2  + akey[i] >> 2 );
	}
	return (enc);
}
////////////////////////////////// Decripta //////////////////////////////////
/*
 astr:texto a ser descriptografado  (ate 36 bytes)
 akey:chave (ate 36 bytes)
 step: values 0x0000 ate 0xffff
*/
char *decode_node(char *astr ,char *akey ,long int step)
{
	int i=0;
	for (i = 0 ;i<strlen(astr);++i )
	{
		dec[i]= (astr[i]) -   (step << 2  + akey[i] >> 2 ); 
	}
	return (dec);
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