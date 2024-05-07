// 12S23010 - Tiffani Rumiris Br Butar - Butar
// 12S23024 - Eska Natasia Silaen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[20];
    char name[50];
    int year;
    char gender[10];
    char status[20];
} Student;

typedef struct {
    char name[50];
    int capacity;
    char gender[10];
    int current;
} Dorm;

void read_data(Dorm dorms[], Student students[]) {
 
}

void print_dorms(Dorm dorms[]) {
 
}

void print_students(Student students[]) {

}

void save_students(Student students[]) {
    FILE *file = fopen("./storage/student-repository.txt", "w");
    int i = 0;
    while (students[i].name[0] != '\0') {
        fprintf(file, "%s|%s|%d|%s|%s\n", students[i].id, students[i].name, students[i].year, students[i].gender, students[i].status);
        i++;
    }
    fclose(file);
}

void save_dorms(Dorm dorms[]) {
    FILE *file = fopen("./storage/dorm-repository.txt", "w");
    int i = 0;
    while (dorms[i].name[0] != '\0') {
        fprintf(file, "%s|%d|%s|%d\n", dorms[i].name, dorms[i].capacity, dorms[i].gender, dorms[i].current);
        i++;
    }
    fclose(file);
}

int main() {
    Dorm dorms[100] = {0};
    Student students[100] = {0};

    read_data(dorms, students);

    char command[50];
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "dorm-print-all-detail") == 0) {
            print_dorms(dorms);
        } else if (strcmp(command, "student-print-all-detail") == 0) {
            print_students(students);
        } else if (strcmp(command, "---") == 0) {
            save_students(students);
            save_dorms(dorms);
            break;
        }
    }

    return 0;
}