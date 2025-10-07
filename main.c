#include "cola.h"
#include "gui.h"
#include <stdio.h>

int main() {
    Cola* cola = crear_cola();
    int opcion;

    do {
        opcion = menu_principal();
        switch(opcion) {
            case 1:
                manejar_añadir(cola);
                break;
            case 2:
                manejar_ver(cola);
                break;
            case 3:
                manejar_imprimir(cola);
                break;
            case 0:
                printf("Saliendo del simulador...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while(opcion != 0);

    destruir_cola(cola);
    return 0;
}
