// repository.c
#include "repository.h"
#include <stdio.h>
#include <stdlib.h>

void load_initial_data_from_file(struct repository_t *repo, const char *dorm_file, const char *student_file) {
    FILE *dorm_fp = fopen(dorm_file, "r");
    if (dorm_fp == NULL) {
        printf("Error: Unable to open dorm repository file.\n");
        exit(1);
    }

    char dorm_line[100];
    while (fgets(dorm_line, sizeof(dorm_line), dorm_fp) != NULL) {
        struct dorm_t dorm = create_dorm(dorm_line);
        add_dorm_to_repository(repo, dorm);
    }
    fclose(dorm_fp);

    FILE *student_fp = fopen(student_file, "r");
    if (student_fp == NULL) {
        printf("Error: Unable to open student repository file.\n");
        exit(1);
    }

    char student_line[100];
    while (fgets(student_line, sizeof(student_line), student_fp) != NULL) {
        struct student_t student = create_student(student_line);
        add_student_to_repository(repo, student);
    }
    fclose(student_fp);
}
