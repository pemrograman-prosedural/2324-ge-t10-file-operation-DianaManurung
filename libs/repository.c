#include "repository.h"
#include <stdio.h>
#include <string.h>

// Function to load dorm data from file
void load_dorm_data(const char *filename, struct dorm_t *dorms, int *num_dorms) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Read dorm data from file
    while ((*num_dorms < MAX_DORM) && (fscanf(file, "%19[^|]|%hu|%*[^\n]%*c", dorms[*num_dorms].name, &dorms[*num_dorms].capacity)) == 2) {
        dorms[*num_dorms].residents_num = 0; // Initialize residents number to 0
        dorms[*num_dorms].gender = GENDER_MALE; // Default gender, can be changed later
        (*num_dorms)++;
    }

    fclose(file);
}

// Function to load student data from file
void load_student_data(const char *filename, struct student_t *students, int *num_students, struct dorm_t *dorms, int num_dorms) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Read student data from file
    while ((*num_students < MAX_STUDENT) && (fscanf(file, "%11[^|]|%39[^|]|%4[^|]|%*[^\n]%*c", students[*num_students].id, students[*num_students].name, students[*num_students].year)) == 3) {
        // Set gender
        char gender_str[10];
        fscanf(file, "|%9[^|]|%*[^\n]%*c", gender_str);
        if (strcmp(gender_str, "male") == 0) {
            students[*num_students].gender = GENDER_MALE;
        } else if (strcmp(gender_str, "female") == 0) {
            students[*num_students].gender = GENDER_FEMALE;
        }

        // Set dorm pointer to NULL initially
        students[*num_students].dorm = NULL;

        (*num_students)++;
    }

    fclose(file);
}
