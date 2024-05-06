// 12S23014 - Mikhael Valentino Gultom
// 12S23040 - Diana Hevila Manurung

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main(int _argc, char **_argv)
{
    struct dorm_t dorms[100];
    int num_dorms = 0;
    load_dorms(dorms, &num_dorms);

    struct student_t students[100];
    int num_students = 0;
    load_students(students, &num_students);

    char command[50];
    printf("Enter command: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0;

    if (strcmp(command, "dorm-print-all-detail") == 0) {
        for (int i = 0; i < num_dorms; i++) {
            print_dorm(dorms[i]);
        }
    } else if (strcmp(command, "student-print-all-detail") == 0) {
        for (int i = 0; i < num_students; i++) {
            print_student(students[i]);
        }
    } else {
        printf("Invalid command\n");
    }

    return 0;
}