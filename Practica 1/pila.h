//Declaracion de la estructura 
struct nodo{
	int Linea;
	char Llave;
	struct nodo *sig;
};


//Seccion De Alias
typedef struct nodo NODO;
typedef NODO* pila;
typedef enum{NO_MEMORY, OK} mensaje;
typedef enum{FALSE, TRUE} booleano;


//prototipos de funciones

void ini_pila(pila*);//inicializa la pila

void liberar_pila(pila*);//Libera la pila

mensaje push(pila*, NODO);//Ingresar datos en pila

NODO Pop(pila*);//Sacar datos de pila

NODO top(pila);//Sacar una copia del primer elemento de la pila

booleano empty(pila);//Verificar que la pila este vacia


