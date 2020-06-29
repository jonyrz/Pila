#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int x,lin=1;
	x=0;
	pila p;
	NODO D;
	char c;
	int op;
	D.Linea=1; 
	ini_pila(&p);
	FILE * archivo; 
	
		puts("ELIGE ARCHIVO");
    puts("Abrir Archivo 1");
    puts("Abrir Archivo 2");
    puts("Abrir Archivo 3");
    puts("Abrir Archivo 4");
    
        printf("\n Opcion: ");
        scanf("%d", &op);
       
		
		switch(op){
			case 1:
            archivo = fopen("1.c", "r");
            printf ("Error en linea final\n 10");
        	   	 break;
        	case 2:
            archivo = fopen("2.c", "r");
            
       			 break;
        	case 3:
            archivo = fopen("3.c", "r");
        		 break;
        	case 4:
            archivo = fopen("4.c", "r");
         		 break;
		}
	
	
		if (archivo == NULL) {
		printf("%s\n", "Error al abrir el archivo");
		exit(0);
		}
		
	while((c=fgetc(archivo))!=EOF){ 
		switch(c){
			case '(': case '[': case '{': 
				D.Llave=c; 
				push(&p, D); 
			break;
			
			case ')': case ']': case'}':	
			
				if(empty(p))
				{ 
				printf("\n ERROR 2 en INICIO; en linea: %d", lin); 
				
			    x=1;
			   }
			   
			else{ 
				D=top(p);
					if(D.Llave=='('&& c==')'|| D.Llave=='['&& c==']' || D.Llave=='{'&& c=='}' ){
						D=Pop(&p); 
					}
					else printf("\n ERROR 3 no compatibles; en linea: %d", lin); 
				
				
				}
				
			break;
			case '\n': 
		
			lin++;
			break;
			}
			}
			
		if(empty(p) && x==0) 
		{
		printf("\n Se encuentra balanceado");
		} else {	
			printf("\n Error, no se encuentra balanceado");	
				
		}
}

