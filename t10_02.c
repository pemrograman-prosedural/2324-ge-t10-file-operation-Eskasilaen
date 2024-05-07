// 12S23010 - Tiffani Rumiris Br Butar - Butar
// 12S23024 - Eska Natasia Silaen

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

#define MAX_STUDENTS 100
#define MAX_DORMS 100

typedef struct {
    char id[10];
    char name[50];
    int year;
    char gender[10];
    char status[20];
} Student;

typedef struct {
    char name[50];
    int capacity;
    char gender[10];
    int occupancy;
} Dorm;

void saveStudentData(Student* students, int studentCount) {
    FILE* file = fopen("./storage/student-repository.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open student repository file for writing.\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < studentCount; i++) {
        fprintf(file, "%s|%s|%d|%s|%s\n", students[i].id, students[i].name, students[i].year, students[i].gender, students[i].status);
    }

    fclose(file);
}

void saveDormData(Dorm* dorms, int dormCount) {
    FILE* file = fopen("./storage/dorm-repository.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open dorm repository file for writing.\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < dormCount; i++) {
        fprintf(file, "%s|%d|%s|%d\n", dorms[i].name, dorms[i].capacity, dorms[i].gender, dorms[i].occupancy);
    }

    fclose(file);
}

int main() {
    Student students[MAX_STUDENTS];
    Dorm dorms[MAX_DORMS];
    int studentCount = 0;
    int dormCount = 0;

    saveStudentData(students, studentCount);
    saveDormData(dorms, dormCount);

    return 0;
}