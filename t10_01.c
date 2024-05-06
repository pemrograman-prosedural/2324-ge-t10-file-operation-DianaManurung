// 12S23014 - Mikhael Valentino Gultom
// 12S23040 - Diana Hevila Manurung

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

// Misalkan ini adalah struktur data simulator Anda
typedef struct {
    int data[100];
    int size;
} Simulator;

// Fungsi untuk menginisialisasi simulator dengan data awal
void initialize_simulator(Simulator* simulator, int* initial_data, int size) {
    for (int i = 0; i < size; i++) {
        simulator->data[i] = initial_data[i];
    }
    simulator->size = size;
}

// Fungsi untuk mencetak data dalam simulator
void print_simulator_data(Simulator* simulator) {
    for (int i = 0; i < simulator->size; i++) {
        printf("%d ", simulator->data[i]);
    }
    printf("\n");
}

int main() {
    // Membuka file data awal
    FILE *file = fopen("initial_data.txt", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    // Membaca data dari file
    int initial_data[100];
    int size = 0;
    while (fscanf(file, "%d", &initial_data[size]) != EOF) {
        size++;
    }

    // Menutup file
    fclose(file);

    // Membuat dan menginisialisasi simulator dengan data awal
    Simulator simulator;
    initialize_simulator(&simulator, initial_data, size);

    // Mencetak data dalam simulator
    print_simulator_data(&simulator);

    return 0;
}