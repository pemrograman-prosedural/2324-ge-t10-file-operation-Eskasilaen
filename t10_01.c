// 12S23010 - Tiffani Rumiris Br Butar - Butar
// 12S23024 - Eska Natasia Silaen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/dorm.h"
#include "student.h"

#define MAX_DORMS 100
#define MAX_STUDENTS 100

int main() {
    // Membuka file asrama dan mahasiswa untuk dibaca
    FILE *dorm_file = fopen("./storage/dorm-repository.txt", "r");
    FILE *student_file = fopen("./storage/student-repository.txt", "r");

    // Memeriksa apakah file berhasil dibuka
    if (dorm_file == NULL || student_file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Inisialisasi array untuk menyimpan data asrama dan mahasiswa
    struct dorm_t dorms[MAX_DORMS];
    struct student_t students[MAX_STUDENTS];
    int num_dorms = 0;
    int num_students = 0;

    // Membaca data asrama dari file
    char line[100];
    while (fgets(line, sizeof(line), dorm_file)) {
        // Mengisi array dorms dengan data dari file
        dorms[num_dorms] = create_dorm_repository(line);
        num_dorms++;
    }

    // Membaca data mahasiswa dari file
    while (fgets(line, sizeof(line), student_file)) {
        // Mengisi array students dengan data dari file
        students[num_students] = create_student_repository(line);
        num_students++;
    }

    // Menutup file setelah selesai membaca
    fclose(dorm_file);
    fclose(student_file);

    return EXIT_SUCCESS;
}