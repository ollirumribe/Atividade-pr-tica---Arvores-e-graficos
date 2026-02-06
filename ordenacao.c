#include <stdio.h>
#include <time.h>

void preencherDecrescente(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = n - i;
    }
}

void copiarVetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void bubbleSort(int v[], int n, long long *comp, long long *mov) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comp)++;
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*mov)++;
            }
        }
    }
}

void selectionSort(int v[], int n, long long *comp, long long *mov) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            (*comp)++;
            if (v[j] < v[min]) {
                min = j;
            }
        }

        if (min != i) {
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
            (*mov)++;
        }
    }
}

void testarAlgoritmo(int tamanho) {
    int original[10000];
    int copia[10000];

    preencherDecrescente(original, tamanho);

    // ---------------- BUBBLE SORT ----------------
    copiarVetor(original, copia, tamanho);

    long long comp = 0, mov = 0;
    clock_t inicio = clock();

    bubbleSort(copia, tamanho, &comp, &mov);

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    printf("Bubble Sort | %d | %.2f ms | %lld | %lld\n",
           tamanho, tempo, comp, mov);

    // ---------------- SELECTION SORT ----------------
    copiarVetor(original, copia, tamanho);

    comp = 0;
    mov = 0;
    inicio = clock();

    selectionSort(copia, tamanho, &comp, &mov);

    fim = clock();
    tempo = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

    printf("Selection Sort | %d | %.2f ms | %lld | %lld\n",
           tamanho, tempo, comp, mov);
}

int main() {
    printf("\nAlgoritmo | Tamanho | Tempo (ms) | Comparacoes | Movimentacoes\n\n");

    testarAlgoritmo(100);
    testarAlgoritmo(1000);
    testarAlgoritmo(10000);

    return 0;
}
