#include <stdio.h>
#include <stdlib.h>

const int arraySize = 30;

struct fullName_t {
    char *name;
    char *surname;
    char *patronymic;
};

struct medData_a {
    float height;
    float weight;
};

struct medData_b {
    float height;
    float weight;
    float vision;
    int bloodgroup;
};

struct studentsData {
    struct fullName_t fullName;
    union {
        struct medData_a a;
        struct medData_b b;
    };
};

int inputData(struct studentsData *students, int nextStudent);
float inputNumericalData();
char *inputStringData();
void printData(struct studentsData *students, int nextStudent, int abSwitch);
void freeAll(struct studentsData *students, int nextStudent);

int main()
{
    struct studentsData *students;
    students = (struct studentsData *) malloc(arraySize * sizeof(struct studentsData));
    char command[arraySize];
    int nextStudent = 0;
    while (1) {
        printf("Enter command:\n");
        printf("    1 - Enter data\n");
        printf("    2 - Print a) data\n");
        printf("    3 - Print b) data\n");
        printf("    4 - Exit\n");
        fgets(command, arraySize, stdin);
        switch (command[0]) {
        case '1':
            nextStudent = inputData(students, nextStudent);
            break;
        case '2':
            printData(students, nextStudent, 0);
            break;
        case '3':
            printData(students, nextStudent, 1);
            break;
        case '4':
            freeAll(students, nextStudent);
            return 0;
        }
    }
    return 0;
}

int inputData(struct studentsData *students, int nextStudent)
{
    printf("Enter first name: ");
    students[nextStudent].fullName.name = inputStringData();
    printf("Enter second name: ");
    students[nextStudent].fullName.surname = inputStringData();
    printf("Enter patronymic: ");
    students[nextStudent].fullName.patronymic = inputStringData();

    printf("Enter height: ");
    students[nextStudent].b.height = inputNumericalData();
    printf("Enter weight: ");
    students[nextStudent].b.weight = inputNumericalData();
    printf("Enter vision: ");
    students[nextStudent].b.vision = inputNumericalData();
    printf("Enter blood group: ");
    students[nextStudent].b.bloodgroup = (int) inputNumericalData();

    return ++nextStudent;
}

float inputNumericalData()
{
    char buffer[arraySize];
    float num;
    do {
        fgets(buffer, arraySize, stdin);
        num = atof(buffer);
        if (num <= 0) {
            printf("Incorrect value. Try again: ");
            continue;
        }
        break;
    } while (1);
    return num;
}

char *inputStringData()
{
    char *buffer;
    buffer = (char *) malloc(arraySize * sizeof(char));
    do {
        fgets(buffer, arraySize, stdin);
        if (buffer[0] == ' ') {
            printf("The name can not start with a space. Try again: ");
            continue;
        }
        if (buffer[0] == '\n') {
            printf("You did not enter a name. Try again: ");
            continue;
        }
        break;
    } while (1);
    return buffer;
}

void printData(struct studentsData *students, int nextStudent, int abSwitch)
{
    printf("\n");
    for (int i = 0; i < nextStudent; i++) {
        printf("#%d:\n", i + 1);
        printf("        Name: %s", students[i].fullName.name);
        printf("     Surname: %s", students[i].fullName.surname);
        printf("  Patronymic: %s", students[i].fullName.patronymic);
        printf("      Height: %.3f\n", students[i].b.height);
        printf("      Weight: %.3f\n", students[i].b.weight);
        if (abSwitch) {
            printf("      Vision: %.3f\n", students[i].b.vision);
            printf(" Blood Group: %d\n", students[i].b.bloodgroup);
        }
    }
    printf("\n");
}

void freeAll(struct studentsData *students, int nextStudent)
{
    for (int i = 0; i < nextStudent; i++) {
        free(students[i].fullName.name);
        free(students[i].fullName.surname);
        free(students[i].fullName.patronymic);
    }
    free(students);
}
