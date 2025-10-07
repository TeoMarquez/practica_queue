#ifndef GUI_H
#define GUI_H

#include "cola.h"

// Menú principal: devuelve opción seleccionada (0-3)
int menu_principal();

// Funciones de cada opción
void manejar_añadir(Cola* cola);
void manejar_ver(Cola* cola);
void manejar_imprimir(Cola* cola);

// Función auxiliar para leer un string seguro
void leer_cadena(char* buffer, int max_len);

#endif
