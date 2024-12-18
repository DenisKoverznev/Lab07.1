#include <stdio.h>
#include <string.h>
#include <stdlib.h>  

#define MAX_STUDENTS 5
#define MAX_NAME_LENGTH 100


struct Student {
    char name[MAX_NAME_LENGTH];
    int birth_year;
    int course;
    float gpa;
};


int compareByNameAsc(const void* a, const void* b) {
    return strcmp(((struct Student*)a)->name, ((struct Student*)b)->name);
}


int compareByNameDesc(const void* a, const void* b) {
    return strcmp(((struct Student*)b)->name, ((struct Student*)a)->name);
}


int compareByBirthYearAsc(const void* a, const void* b) {
    return ((struct Student*)a)->birth_year - ((struct Student*)b)->birth_year;
}


int compareByBirthYearDesc(const void* a, const void* b) {
    return ((struct Student*)b)->birth_year - ((struct Student*)a)->birth_year;
}


int compareByCourseAsc(const void* a, const void* b) {
    return ((struct Student*)a)->course - ((struct Student*)b)->course;
}


int compareByCourseDesc(const void* a, const void* b) {
    return ((struct Student*)b)->course - ((struct Student*)a)->course;
}


int compareByGpaAsc(const void* a, const void* b) {
    if (((struct Student*)a)->gpa < ((struct Student*)b)->gpa) return -1;
    if (((struct Student*)a)->gpa > ((struct Student*)b)->gpa) return 1;
    return 0;
}


int compareByGpaDesc(const void* a, const void* b) {
    if (((struct Student*)a)->gpa > ((struct Student*)b)->gpa) return -1;
    if (((struct Student*)a)->gpa < ((struct Student*)b)->gpa) return 1;
    return 0;
}


void displayStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %-15s Year of Birth: %4d Course: %2d GPA: %.2f\n",
            students[i].name, students[i].birth_year, students[i].course, students[i].gpa);
    }
}

int main() {
  
    struct Student students[MAX_STUDENTS] = {
        {"John", 2000, 2, 3.7},
        {"Anna", 1999, 3, 4.0},
        {"Mike", 2001, 1, 3.5},
        {"Lisa", 1998, 4, 3.9},
        {"Eva", 2000, 2, 4.2}
    };

    int n = 5;  

    
    printf("\nSorted by Name (Ascending):\n");
    qsort(students, n, sizeof(struct Student), compareByNameAsc);
    displayStudents(students, n);

   
    printf("\nSorted by Name (Descending):\n");
    qsort(students, n, sizeof(struct Student), compareByNameDesc);
    displayStudents(students, n);

    
    printf("\nSorted by Birth Year (Ascending):\n");
    qsort(students, n, sizeof(struct Student), compareByBirthYearAsc);
    displayStudents(students, n);

    
    printf("\nSorted by Birth Year (Descending):\n");
    qsort(students, n, sizeof(struct Student), compareByBirthYearDesc);
    displayStudents(students, n);

    
    printf("\nSorted by Course (Ascending):\n");
    qsort(students, n, sizeof(struct Student), compareByCourseAsc);
    displayStudents(students, n);

    
    printf("\nSorted by Course (Descending):\n");
    qsort(students, n, sizeof(struct Student), compareByCourseDesc);
    displayStudents(students, n);

   
    printf("\nSorted by GPA (Ascending):\n");
    qsort(students, n, sizeof(struct Student), compareByGpaAsc);
    displayStudents(students, n);

    
    printf("\nSorted by GPA (Descending):\n");
    qsort(students, n, sizeof(struct Student), compareByGpaDesc);
    displayStudents(students, n);

    return 0;
}
