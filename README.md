# Simulador de Cola de Impresora - C

## Descripción

Proyecto en C que simula el encolamiento y manejo de archivos para impresión usando estructuras dinámicas (colas enlazadas).
Importante: Este proyecto no interactúa con una impresora real; es únicamente una representación de la lógica de encolamiento y procesamiento de archivos.

El programa permite:

- Añadir archivos a la cola (máximo 40 caracteres por nombre/contenido)
- Ver, editar o eliminar archivos de la cola
- Imprimir archivos en orden FIFO (simulación por printf)

## Estructura de carpetas
- practica_queue_impresora/
  - headers/      # Archivos .h
  - src/          # Archivos .c
  - main.c        # Programa principal
  - compilar.bat  # Script de compilación en Windows
  - README.md

## Cómo compilar

Abrir terminal en la carpeta del proyecto

Ejecutar:

```
compilar.bat
```

## Cómo usar el programa

### 1 Menú principal:
- 1 Añadir archivo
- 2 Ver / Editar / Eliminar archivos
- 3 Imprimir archivos (simulación)
- 0 Salir

### 2 Ver archivos: Se muestran en bloques de 10

### 3 Comandos:
- A : Página anterior
- D : Página siguiente
- E -X : Editar archivo número X
- D -X : Eliminar archivo número X
- Q : Salir del modo ver

### 4 Añadir / Editar archivos: Se verifica que el contenido no exceda 40 caracteres

### 5 Imprimir: Los archivos se muestran en orden FIFO y se eliminan de la cola
