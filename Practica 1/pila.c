#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

booleano empty(pila s){ // Determinar si la pila esta vacia 
	if(s==NULL){  
		return TRUE;
	}
	return FALSE;
}

NODO Pop(pila*s){ 
	NODO w;
	w=**s;
	free(*s);
	*s=w.sig;
	w.sig=NULL;
	return w;
}

void ini_pila(pila*s){ //Inicializamos la pila en nulo
	*s=NULL;  
}

void liberar_pila(pila *s){ //Liberamos la pila  verificando si esta vacia y en caso contrario sacamos el elemento o los elementos que esten en la pila
	while(!empty(*s)){
		Pop(s);
	}
}

NODO top(pila s){ //Creamos copia del elemento encontrado 
	NODO copia;
	copia=*s;
	copia.sig=NULL; 
	return copia;
}

mensaje push(pila *s, NODO D){ 
	pila temp;
	temp=(pila)malloc(sizeof(NODO)); //Asignamos tamaño de la pila
	if(temp==NULL){ 
		return NO_MEMORY;
	}
	*temp=D;
	if(empty(*s)){
		temp->sig=NULL;
	}
	else{
		temp->sig=*s; 
	}
	*s=temp;
	return OK;
}
