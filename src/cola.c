#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

Cola* crear_cola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->frente = NULL;
    cola->final = NULL;
    cola->cantidad = 0;
    return cola;
}

void encolar(Cola* cola, const char* contenido) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    strncpy(nuevo->contenido, contenido, MAX_CONTENIDO-1);
    nuevo->contenido[MAX_CONTENIDO-1] = '\0';
    nuevo->siguiente = NULL;

    if (cola->final) cola->final->siguiente = nuevo;
    else cola->frente = nuevo;

    cola->final = nuevo;
    cola->cantidad++;
}

char* desencolar(Cola* cola) {
    if (!cola->frente) return NULL;

    Nodo* temp = cola->frente;
    static char buffer[MAX_CONTENIDO];
    strncpy(buffer, temp->contenido, MAX_CONTENIDO);

    cola->frente = temp->siguiente;
    if (!cola->frente) cola->final = NULL;

    free(temp);
    cola->cantidad--;
    return buffer;
}

void ver_cola(Cola* cola) {
    if (!cola->frente) {
        printf("La cola esta vacia.\n");
        return;
    }

    Nodo* actual = cola->frente;
    int index = 0;
    while (actual) {
        printf("%d: %s\n", index, actual->contenido);
        actual = actual->siguiente;
        index++;
    }
}

int editar_nodo(Cola* cola, int posicion, const char* nuevo_contenido) {
    if (posicion < 0 || posicion >= cola->cantidad) return 0;
    Nodo* actual = cola->frente;
    for (int i = 0; i < posicion; i++) actual = actual->siguiente;
    strncpy(actual->contenido, nuevo_contenido, MAX_CONTENIDO-1);
    actual->contenido[MAX_CONTENIDO-1] = '\0';
    return 1;
}

int eliminar_nodo(Cola* cola, int posicion) {
    if (posicion < 0 || posicion >= cola->cantidad) return 0;

    Nodo* actual = cola->frente;
    Nodo* anterior = NULL;

    for (int i = 0; i < posicion; i++) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (anterior) anterior->siguiente = actual->siguiente;
    else cola->frente = actual->siguiente;

    if (actual == cola->final) cola->final = anterior;

    free(actual);
    cola->cantidad--;
    return 1;
}

void destruir_cola(Cola* cola) {
    while (cola->frente) {
        Nodo* temp = cola->frente;
        cola->frente = temp->siguiente;
        free(temp);
    }
    free(cola);
}
