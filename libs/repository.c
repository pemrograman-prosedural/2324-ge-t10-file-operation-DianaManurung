#include "repository.h"
#include <stdio.h>

void create_dorm_file() {
    // Membuat file dorm-repository.txt
    FILE *dorm_file = fopen("./storage/dorm-repository.txt", "w");
    if (dorm_file == NULL) {
        printf("Failed to create dorm file\n");
        return;
    }
    fclose(dorm_file);
}

void create_student_file() {
    // Membuat file student-repository.txt
    FILE *student_file = fopen("./storage/student-repository.txt", "w");
    if (student_file == NULL) {
        printf("Failed to create student file\n");
        return;
    }
    fclose(student_file);
}