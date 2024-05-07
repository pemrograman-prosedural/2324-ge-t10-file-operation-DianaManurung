#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "dorm.h"
#include "student.h"

#define MAX_DORM 100
#define MAX_STUDENT 100

// Function prototypes
void load_dorm_data(const char *filename, struct dorm_t *dorms, int *num_dorms);
void load_student_data(const char *filename, struct student_t *students, int *num_students, struct dorm_t *dorms, int num_dorms);

#endif
