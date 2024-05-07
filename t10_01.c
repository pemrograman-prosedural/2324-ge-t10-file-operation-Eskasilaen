// 12S23010 - Tiffani Rumiris Br Butar - Butar
// 12S23024 - Eska Natasia Silaen

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

#define MAX_DORMS 100
#define MAX_STUDENTS 1000

int main() {
    Dorm dorms[MAX_DORMS];
    int num_dorms = 0;
    load_dorms(dorms, &num_dorms, "/storage/dorm-repository.txt");

    Student students[MAX_STUDENTS];
    int num_students = 0;
    load_students(students, &num_students, "/storage/student-repository.txt");

    char command[50];
    scanf("%s", command);

    if (strcmp(command, "dorm-print-all-detail") == 0) {
        dorm_print_all_detail(dorms, num_dorms);
    } else if (strcmp(command, "student-print-all-detail") == 0) {
        student_print_all_detail(students, num_students);
    }

    return 0;  
}