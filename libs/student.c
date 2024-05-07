#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct student_t create_student(char *input) {
    struct student_t student;
    strcpy(student.id, strtok(input, "|"));
    strcpy(student.name, strtok(NULL, "|"));
    strcpy(student.year, strtok(NULL, "|"));
    char *gender = strtok(NULL, "|");
    if (strcmp(gender, "male") == 0) {
        student.gender = GENDER_MALE;
    } else if (strcmp(gender, "female") == 0) {
        student.gender = GENDER_FEMALE;
    }
    student.dorm = NULL;
    return student;
}