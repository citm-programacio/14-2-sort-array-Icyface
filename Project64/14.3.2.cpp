#include <iostream>
using namespace std;

const int arraySize = 10;

// Funci�n para ordenar usando selecci�n
void mysort(int* unsorted, int*& sorted) {
    bool* marked = new bool[arraySize](); // Arreglo de marcadores (inicializado a falso)

    for (int i = 0; i < arraySize; i++) {
        int minIndex = -1;
        int minValue = INT_MAX;

        // Encontrar el m�nimo no marcado
        for (int j = 0; j < arraySize; j++) {
            if (!marked[j] && unsorted[j] < minValue) {
                minValue = unsorted[j];
                minIndex = j;
            }
        }

        // Marcar el elemento como seleccionado
        marked[minIndex] = true;

        // Colocar el m�nimo en el arreglo ordenado
        sorted[i] = minValue;
    }

    delete[] marked; // Liberar la memoria del arreglo de marcadores
}

// Funci�n para imprimir el arreglo
void printArray(const int* a, int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int u[arraySize] = { 0, 8, 1, 2, 4, 5, 5, 9, 20, 15 };
    int* s = new int[arraySize];

    printArray(u, arraySize); // Imprimir el arreglo original

    mysort(u, s); // Ordenar el arreglo

    printArray(s, arraySize); // Imprimir el arreglo ordenado

    delete[] s; // Liberar la memoria del arreglo ordenado
}
