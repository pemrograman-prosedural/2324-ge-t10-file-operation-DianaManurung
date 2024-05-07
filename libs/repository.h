#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "student.h"
#include "dorm.h"

struct repository_t {
    struct student_t *students;
    int num_students;
    struct dorm_t *dorms;
    int num_dorms;
};

void init_repository(struct repository_t *repo);
void add_student_to_repository(struct repository_t *repo, struct student_t student);
void add_dorm_to_repository(struct repository_t *repo, struct dorm_t dorm);
void print_repository(struct repository_t repo);

#endif