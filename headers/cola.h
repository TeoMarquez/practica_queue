#ifndef COLA_H
#define COLA_H

#define MAX_CONTENIDO 41

typedef struct Nodo {
    char contenido[MAX_CONTENIDO];
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* frente;
    Nodo* final;
    int cantidad;
} Cola;

// Crear cola vacía
Cola* crear_cola();

// Añadir un nodo al final de la cola
void encolar(Cola* cola, const char* contenido);

// Eliminar y devolver el nodo del frente
char* desencolar(Cola* cola);

// Ver todos los nodos en orden FIFO
void ver_cola(Cola* cola);

// Editar un nodo en la posición indicada (0-index)
int editar_nodo(Cola* cola, int posicion, const char* nuevo_contenido);

// Eliminar un nodo en la posición indicada (0-index)
int eliminar_nodo(Cola* cola, int posicion);

// Destruir toda la cola y liberar memoria
void destruir_cola(Cola* cola);

#endif
