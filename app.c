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

void updatePatient(int id, const char *name, int age, const char *gender, const char *diagnosis) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            strcpy(patients[i].name, name);
            patients[i].age = age;
            strcpy(patients[i].gender, gender);
            strcpy(patients[i].diagnosis, diagnosis);
            printf("Patient ID %d updated.\n", id);
            return;
        }
    }
    printf("Patient ID %d not found.\n", id);
}

void deletePatient(int id) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            printf("Patient ID %d deleted.\n", id);
            return;
        }
    }
    printf("Patient ID %d not found.\n", id);
}

void viewPatientDetails(int id) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("Patient ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %s\n", patients[i].gender);
            printf("Diagnosis: %s\n\n", patients[i].diagnosis);
            return;
        }
    }
    printf("Patient ID %d not found.\n", id);
}

void listAllPatients() {
    printf("Listing all patients:\n");
    for (int i = 0; i < patientCount; i++) {
        printf("Patient ID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Gender: %s\n", patients[i].gender);
        printf("Diagnosis: %s\n\n", patients[i].diagnosis);
    }
}

int main() {
    int choice, id, age;
    char name[50], gender[10], diagnosis[100];
    
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Update Patient\n");
        printf("3. Delete Patient\n");
        printf("4. View Patient Details\n");
        printf("5. List All Patients\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%d", &id);
                printf("Enter Patient Name: ");
                scanf("%s", name);
                printf("Enter Patient Age: ");
                scanf("%d", &age);
                printf("Enter Patient Gender: ");
                scanf("%s", gender);
                printf("Enter Patient Diagnosis: ");
                scanf("%s", diagnosis);
                addPatient(id, name, age, gender, diagnosis);
                break;
            case 2:
                printf("Enter Patient ID: ");
                scanf("%d", &id);
                printf("Enter Patient Name: ");
                scanf("%s", name);
                printf("Enter Patient Age: ");
                scanf("%d", &age);
                printf("Enter Patient Gender: ");
                scanf("%s", gender);
                printf("Enter Patient Diagnosis: ");
                scanf("%s", diagnosis);
                updatePatient(id, name, age, gender, diagnosis);
                break;
            case 3:
                printf("Enter Patient ID to delete: ");
                scanf("%d", &id);
                deletePatient(id);
                break;
            case 4:
                printf("Enter Patient ID to view details: ");
                scanf("%d", &id);
                viewPatientDetails(id);
                break;
            case 5:
                listAllPatients();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
