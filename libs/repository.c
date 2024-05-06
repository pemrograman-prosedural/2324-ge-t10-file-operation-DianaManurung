#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load_dorms(struct dorm_t *dorms, int *num_dorms) {
    FILE *file = fopen(DORM_REPOSITORY_PATH, "r");
    if (file == NULL) {
        printf("Failed to open dorm repository\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        struct dorm_t dorm = create_dorm(line);
        dorms[*num_dorms] = dorm;
        (*num_dorms)++;
    }

    fclose(file);
}

void load_students(struct student_t *students, int *num_students) {
    FILE *file = fopen(STUDENT_REPOSITORY_PATH, "r");
    if (file == NULL) {
        printf("Failed to open student repository\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        struct student_t student = create_student(line);
        students[*num_students] = student;
        (*num_students)++;
    }

    fclose(file);
}