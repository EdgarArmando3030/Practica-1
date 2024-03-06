import random
import time

# Función para generar un arreglo de números enteros aleatorios
def generar_arreglo(n):
    return [random.randint(1, 1000) for _ in range(n)]

# Función para imprimir el contenido de un arreglo
def imprimir_arreglo(arreglo):
    print("Contenido del arreglo:")
    print(arreglo)

# Función de búsqueda secuencial
def busqueda_secuencial(arreglo, elemento):
    for i in range(len(arreglo)):
        if arreglo[i] == elemento:
            return i
    return -1

# Función de ordenamiento de arreglo
def ordenar_arreglo(arreglo):
    arreglo.sort()

# Función para calcular el tiempo de ejecución
def calcular_tiempo_ejecucion(arreglo):
    inicio = time.time()
    generar_arreglo(1000)
    imprimir_arreglo(arreglo)
    busqueda_secuencial(arreglo, arreglo[0])
    ordenar_arreglo(arreglo)
    busqueda_secuencial(arreglo, arreglo[0])
    fin = time.time()
    tiempo_total = fin - inicio
    print("Tiempo de ejecución de las operaciones: ", tiempo_total, "segundos")

# Menú principal
def menu():
    print("1. Generar arreglo aleatorio")
    print("2. Imprimir arreglo")
    print("3. Búsqueda secuencial")
    print("4. Ordenar arreglo")
    print("5. Calcular tiempo de ejecución")
    print("6. Salir")

arreglo = []
while True:
    menu()
    opcion = int(input("Ingrese su opción: "))
    
    if opcion == 1:
        arreglo = generar_arreglo(1000)
    elif opcion == 2:
        if arreglo:
            imprimir_arreglo(arreglo)
        else:
            print("Debe generar un arreglo primero")
    elif opcion == 3:
        if arreglo:
            elemento_buscar = int(input("Ingrese el elemento a buscar: "))
            indice_encontrado = busqueda_secuencial(arreglo, elemento_buscar)
            if indice_encontrado != -1:
                print(f"El elemento {elemento_buscar} se encuentra en el índice {indice_encontrado}")
            else:
                print(f"El elemento {elemento_buscar} no se encuentra en el arreglo")
        else:
            print("Debe generar un arreglo primero")
    elif opcion == 4:
        if arreglo:
            ordenar_arreglo(arreglo)
            print("Arreglo ordenado:")
            imprimir_arreglo(arreglo)
        else:
            print("Debe generar un arreglo primero")
    elif opcion == 5:
        if arreglo:
            calcular_tiempo_ejecucion(arreglo)
        else:
            print("Debe generar un arreglo primero")
    elif opcion == 6:
        print("¡Adiós!")
        break
    else:
        print("Opción no válida. Por favor, seleccione una opción del menú.")
