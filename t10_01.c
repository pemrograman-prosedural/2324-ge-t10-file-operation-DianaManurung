// 12S23014 - Mikhael Valentino Gultom
// 12S23040 - Diana Hevila Manurung

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main() {
    struct dorm_t dorms[MAX_DORM];
    struct student_t students[MAX_STUDENT];
    int num_dorms = 0, num_students = 0;

    // Load initial data
    load_dorm_data("./storage/dorm-repository.txt", dorms, &num_dorms);
    load_student_data("./storage/student-repository.txt", students, &num_students, dorms, num_dorms);

    // Print all dorm details
    for (int i = 0; i < num_dorms; i++) {
        print_dorm(dorms[i]);
        printf("|%hu\n", dorms[i].residents_num);
    }

    // Print all student details
    for (int i = 0; i < num_students; i++) {
        print_student(students[i]);
        printf("|unassigned\n");
    }

    return 0;
}