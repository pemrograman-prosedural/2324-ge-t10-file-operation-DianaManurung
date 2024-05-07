#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h" // Add inclusion of dorm.h since struct dorm_t is used here

struct student_t { 
    char id[12]; 
    char name[40]; 
    char year[5]; 
    enum gender_t gender; 
    struct dorm_t *dorm; 
};

struct student_t create_student(char *input);
void print_student(struct student_t mhs);

#endif
