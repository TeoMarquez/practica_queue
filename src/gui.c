#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gui.h"

#define PAGINA 10

int menu_principal() {
    int opcion;
    printf("\n=== Simulador de Impresora ===\n");
    printf("1. Encolar archivo\n");
    printf("2. Ver / Editar / Eliminar archivos\n");
    printf("3. Imprimir archivos\n");
    printf("0. Salir\n");
    printf("Seleccione: ");
    scanf("%d", &opcion);
    getchar(); // limpiar \n
    return opcion;
}

void leer_cadena(char* buffer, int max_len) {
    if(fgets(buffer, max_len, stdin) != NULL) {
        size_t len = strlen(buffer);
        if(len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        } else {
            // Si el usuario ingresó más caracteres que max_len-1, limpiar stdin
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }
    } else {
        buffer[0] = '\0'; 
    }
}

// Añadir archivo
void manejar_añadir(Cola* cola) {
    char nombre[MAX_CONTENIDO];
    printf("Ingrese el nombre/contenido del archivo (max 40 chars): ");
    leer_cadena(nombre, MAX_CONTENIDO);
    encolar(cola, nombre);
    printf("Archivo agregado!\n");
}

// Paginación y selección de archivo
void manejar_ver(Cola* cola) {
    if(cola->cantidad == 0) {
        printf("No hay archivos en la cola.\n");
        return;
    }

    int pagina = 0;
    char comando[10];

    while(1) {
        system("cls"); 
        printf("=== Ver archivos (pagina %d) ===\n", pagina+1);

        Nodo* actual = cola->frente;
        for(int i=0; i<pagina*PAGINA && actual; i++) actual = actual->siguiente;

        int index = pagina*PAGINA;
        for(int i=0; i<PAGINA && actual; i++) {
            printf("%d: %s\n", index + 1, actual->contenido);
            actual = actual->siguiente;
            index++;
        }

        printf("\nComandos: A-anterior, D-siguiente, E -X editar, D -X borrar, Q-salir\n");
        printf("Ingrese comando: ");
        fgets(comando, 10, stdin);

        if(comando[0]=='Q' || comando[0]=='q') break;

        if(comando[0]=='A' || comando[0]=='a') {
            if(pagina>0) pagina--;
        } else if(comando[0]=='D' || comando[0]=='d') {
            if(comando[1]==' ' && comando[2]) {
                int pos = atoi(&comando[2]) - 1;  
                if(eliminar_nodo(cola,pos)) printf("Archivo eliminado!\n");
                else printf("Posicion invalida.\n");
                getchar();
            } else if( (pagina+1)*PAGINA < cola->cantidad) {
                pagina++;
            }
        } else if(comando[0]=='E' || comando[0]=='e') {
            if(comando[1]==' ' && comando[2]) {
                int pos = atoi(&comando[2]) - 1;
                char nuevo[MAX_CONTENIDO];
                printf("Nuevo contenido: ");
                leer_cadena(nuevo, MAX_CONTENIDO);
                if(editar_nodo(cola,pos,nuevo)) printf("Archivo editado!\n");
                else printf("Posicion invalida.\n");
                getchar();
            }
        }
    }
}

void manejar_imprimir(Cola* cola) {
    if(cola->cantidad==0) {
        printf("No hay archivos para imprimir.\n");
        return;
    }

    printf("\n=== Imprimiendo archivos ===\n");
    while(cola->cantidad > 0) {
        char* contenido = desencolar(cola);
        printf("Imprimiendo: %s\n", contenido);
    }
    printf("Todos los archivos han sido impresos!\n");
}
