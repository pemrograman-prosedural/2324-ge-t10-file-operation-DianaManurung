#include "repository.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parse_file(FILE *file, struct data_file *data, unsigned short int *size, unsigned short int *pointer, int *num_gender, int (*create_function)(const char*, const char*, const char*, int)) {
    char buffer[60];

    while (fgets(buffer, sizeof(buffer), file)) {
        strcpy(data->file_id, strtok(buffer, "|"));
        strcpy(data->file_name, strtok(NULL, "|"));
        strcpy(data->file_year, strtok(NULL, "|"));
        strcpy(data->file_gender, strtok(NULL, "|"));

        *num_gender = gender_to_value(data->file_gender);

        create_function(data->file_id, data->file_name, data->file_year, *num_gender);

        (*size)++;
        (*pointer)++;
    }

    fflush(file);
    fclose(file);
}

void parse_file_std(FILE *std, struct student_t *students, unsigned short int *size_mhs, unsigned short int *prt_mhs, int *num_gender) {
    struct data_file data;
    parse_file(std, &data, size_mhs, prt_mhs, num_gender, create_student);
}

void parse_file_drm(FILE *fdrm, struct dorm_t *dorms, unsigned short int *size_drm, unsigned short int *prt_drm, int *num_gender) {
    struct data_file data;
    parse_file(fdrm, &data, size_drm, prt_drm, num_gender, create_dorm);
}
