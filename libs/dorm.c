#include "dorm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct dorm_t create_dorm(char *input) {
    struct dorm_t dorm;
    strcpy(dorm.name, strtok(input, "|"));
    dorm.capacity = atoi(strtok(NULL, "|"));
    char *gender = strtok(NULL, "|");
    if (strcmp(gender, "male") == 0) {
        dorm.gender = GENDER_MALE;
    } else if (strcmp(gender, "female") == 0) {
        dorm.gender = GENDER_FEMALE;
    }
    dorm.residents_num = atoi(strtok(NULL, "|"));
    return dorm;
}