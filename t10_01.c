// 12S23010 - Tiffani Rumiris Br Butar - Butar
// 12S23024 - Eska Natasia Silaen

#include <stdio.h>
#include <stdlib.h>

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
    FILE *dorm_file = fopen("./storage/dorm-repository.txt", "r");
    FILE *student_file = fopen("./storage/student-repository.txt", "r");
    int i = 0;

    while (fscanf(dorm_file, "%[^#]#%d#%[^#]#%d\n", dorms[i].name, &dorms[i].capacity, dorms[i].gender, &dorms[i].current) != EOF) {
        i++;
    }

    i = 0;
    while (fscanf(student_file, "%[^#]#%[^#]#%d#%[^#]#%[^#]\n", students[i].id, students[i].name, &students[i].year, students[i].gender, students[i].status) != EOF) {
        i++;
    }

    fclose(dorm_file);
    fclose(student_file);
}

void print_all(Dorm dorms[], Student students[]) {
    int i = 0;
    while (dorms[i].name[0] != '\0') {
        printf("%s|%d|%s|%d\n", dorms[i].name, dorms[i].capacity, dorms[i].gender, dorms[i].current);
        i++;
    }

    i = 0;
    while (students[i].name[0] != '\0') {
        printf("%s|%s|%d|%s|%s\n", students[i].id, students[i].name, students[i].year, students[i].gender, students[i].status);
        i++;
    }
}

int main() {
    Dorm dorms[100] = {0};
    Student students[100] = {0};

    read_data(dorms, students);
    print_all(dorms, students);

    return 0;
}