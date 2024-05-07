#include "repository.h"
#include <stdlib.h>
#include <string.h>

void parse_line(const char *line, struct data_file *data) {
    strcpy(data->file_id, strtok(line, "|"));
    strcpy(data->file_name, strtok(NULL, "|"));
    strcpy(data->file_year, strtok(NULL, "|"));
    strcpy(data->file_gender, strtok(NULL, "|"));
}

int read_file(FILE *file, struct data_file *data, void (*create_function)(struct data_file *data, void *struct_ptr, int *num_gender), void *struct_ptr, unsigned short int *size_ptr, unsigned short int *pointer, int *num_gender) {
    char buffer[60];
    while (fgets(buffer, sizeof(buffer), file)) {
        parse_line(buffer, data);
        create_function(data, struct_ptr, num_gender);
        (*size_ptr)++;
        (*pointer)++;
    }
    fflush(file);
    fclose(file);
    return 1;
}

void parse_file_std(FILE *std, struct student_t *mhs, unsigned short int *size_mhs, unsigned short int *prt_mhs) {
    struct data_file data;
    int num_gender;
    read_file(std, &data, (void (*)(struct data_file *, void *, int *))create_student, mhs, size_mhs, prt_mhs, &num_gender);
}

void parse_file_drm(FILE *fdrm, struct dorm_t *dorms, unsigned short int *size_drm, unsigned short int *prt_drm) {
    struct data_file data;
    int num_gender;
    read_file(fdrm, &data, (void (*)(struct data_file *, void *, int *))create_dorm, dorms, size_drm, prt_drm, &num_gender);
}
