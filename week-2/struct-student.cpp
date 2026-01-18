#include <stdio.h>
#include <string.h>

/* Define structure */
struct Student {
    int id;
    char name[50];
    float gpa;
};

/* Function to display student details */
void displayStudent(struct Student s) {
    printf("ID   : %d\n", s.id);
    printf("Name : %s\n", s.name);
    printf("GPA  : %.2f\n", s.gpa);
    printf("--------------------\n");
}

int main() {
    /* Declare and initialize a structure variable */
    struct Student s1 = {101, "Aye", 3.75};

    /* Display single student */
    printf("First Student Record:\n");
    displayStudent(s1);

    /* Array of structures */
    struct Student students[3];

    /* Input multiple students */
    for (int i = 0; i < 3; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    /* Display all students */
    printf("\nAll Student Records:\n");
    for (int i = 0; i < 3; i++) {
        displayStudent(students[i]);
    }

    /* Pointer to structure */
    struct Student *ptr = &s1;

    printf("Accessing the first student name using pointer:\n");
    printf("Name via pointer: %s\n", ptr->name);

    return 0;
}
