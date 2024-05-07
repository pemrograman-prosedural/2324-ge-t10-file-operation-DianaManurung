// 12S23014 - Mikhael Valentino Gultom
// 12S23040 - Diana Hevila Manurung

// Main program
#include <stdio.h>
#include "repository.h"

int main() {
    struct repository_t repo;
    init_repository(&repo);
    load_initial_data_from_file(&repo, "dorm-repository.txt", "student-repository.txt");

    // Command handling
    char command[50];
    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        if (strcmp(command, "dorm-print-all-detail\n") == 0) {
            print_dorms(repo);
        } else if (strcmp(command, "student-print-all-detail\n") == 0) {
            print_students(repo);
        } else if (strcmp(command, "exit\n") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
