#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "gender.h"
#include "dorm.h"
#include "student.h"

#define DORM_REPOSITORY_PATH "./storage/dorm-repository.txt"
#define STUDENT_REPOSITORY_PATH "./storage/student-repository.txt"

void load_dorms(struct dorm_t *dorms, int *num_dorms);
void load_students(struct student_t *students, int *num_students);

#endif
