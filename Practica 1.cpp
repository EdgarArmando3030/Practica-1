#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* generar_arreglo(int n) {
    int* arreglo = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arreglo[i] = rand() % 1000 + 1;
    }
    return arreglo;
}


void imprimir_arreglo(int* arreglo, int n) {
    printf("Contenido del arreglo:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}


int busqueda_secuencial(int* arreglo, int n, int elemento) {
    for (int i = 0; i < n; i++) {
        if (arreglo[i] == elemento) {
            return i;
        }
    }
    return -1;
}


void ordenar_arreglo(int* arreglo, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}


void calcular_tiempo_ejecucion(int* arreglo, int n) {
    clock_t inicio = clock();
    generar_arreglo(1000);
    imprimir_arreglo(arreglo, n);
    busqueda_secuencial(arreglo, n, arreglo[0]);
    ordenar_arreglo(arreglo, n);
    busqueda_secuencial(arreglo, n, arreglo[0]);
    clock_t fin = clock();
    double tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución de las operaciones: %f segundos\n", tiempo_total);
}


void menu() {
    printf("1. Generar arreglo aleatorio\n");
    printf("2. Imprimir arreglo\n");
    printf("3. Busqueda secuencial\n");
    printf("4. Ordenar arreglo\n");
    printf("5. Calcular tiempo de ejecucion\n");
    printf("6. Salir\n");
}

int main() {
    int* arreglo = NULL;
    int n = 1000;
    int opcion;
    while (1) {
        menu();
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                arreglo = generar_arreglo(n);
                break;
            case 2:
                if (arreglo != NULL) {
                    imprimir_arreglo(arreglo, n);
                } else {
                    printf("Debe generar un arreglo primero\n");
                }
                break;
            case 3:
                if (arreglo != NULL) {
                    int elemento_buscar;
                    printf("Ingrese el elemento a buscar: ");
                    scanf("%d", &elemento_buscar);
                    int indice_encontrado = busqueda_secuencial(arreglo, n, elemento_buscar);
                    if (indice_encontrado != -1) {
                        printf("El elemento %d se encuentra en el indice %d\n", elemento_buscar, indice_encontrado);
                    } else {
                        printf("El elemento %d no se encuentra en el arreglo\n", elemento_buscar);
                    }
                } else {
                    printf("Debe generar un arreglo primero\n");
                }
                break;
            case 4:
                if (arreglo != NULL) {
                    ordenar_arreglo(arreglo, n);
                    printf("Arreglo ordenado:\n");
                    imprimir_arreglo(arreglo, n);
                } else {
                    printf("Debe generar un arreglo primero\n");
                }
                break;
            case 5:
                if (arreglo != NULL) {
                    calcular_tiempo_ejecucion(arreglo, n);
                } else {
                    printf("Debe generar un arreglo primero\n");
                }
                break;
            case 6:
                printf("¡Adios!\n");
                free(arreglo);
                return 0;
            default:
                printf("Opcion no válida. Por favor, seleccione una opción del menu.\n");
                break;
        }
    }
}

