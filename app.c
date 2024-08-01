#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    char diagnosis[100];
} Patient;

Patient patients[MAX_PATIENTS];
int patientCount = 0;

void addPatient(int id, const char *name, int age, const char *gender, const char *diagnosis) {
    if (patientCount < MAX_PATIENTS) {
        patients[patientCount].id = id;
        strcpy(patients[patientCount].name, name);
        patients[patientCount].age = age;
        strcpy(patients[patientCount].gender, gender);
        strcpy(patients[patientCount].diagnosis, diagnosis);
        patientCount++;
    } else {
        printf("Maximum patient limit reached.\n");
    }
}

int main() {
    addPatient(1, "John Doe", 30, "Male", "Flu");
    addPatient(2, "Jane Smith", 25, "Female", "Cold");

    for (int i = 0; i < patientCount; i++) {
        printf("Patient ID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Gender: %s\n", patients[i].gender);
        printf("Diagnosis: %s\n\n", patients[i].diagnosis);
    }

    return 0;
}
