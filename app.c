#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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

bool isIdValid(int id) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            return false;
        }
    }
    return true;
}

void addPatient(int id, const char *name, int age, const char *gender, const char *diagnosis) {
    if (patientCount >= MAX_PATIENTS) {
        printf("Maximum patient limit reached.\n");
        return;
    }

    if (!isIdValid(id)) {
        printf("Patient ID %d already exists.\n", id);
        return;
    }

    patients[patientCount].id = id;
    strcpy(patients[patientCount].name, name);
    patients[patientCount].age = age;
    strcpy(patients[patientCount].gender, gender);
    strcpy(patients[patientCount].diagnosis, diagnosis);
    patientCount++;
    printf("Patient ID %d added successfully.\n", id);
}

void updatePatient(int id, const char *name, int age, const char *gender, const char *diagnosis) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            strcpy(patients[i].name, name);
            patients[i].age = age;
            strcpy(patients[i].gender, gender);
            strcpy(patients[i].diagnosis, diagnosis);
            printf("Patient ID %d updated successfully.\n", id);
            return;
        }
    }
    printf("Patient ID %d not found.\n", id);
}

void deletePatient(int id) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            char confirm;
            printf("Are you sure you want to delete Patient ID %d? (y/n): ", id);
            scanf(" %c", &confirm);
            if (confirm == 'y' || confirm == 'Y') {
                for (int j = i; j < patientCount - 1; j++) {
                    patients[j] = patients[j + 1];
                }
                patientCount--;
                printf("Patient ID %d deleted successfully.\n", id);
            } else {
                printf("Deletion cancelled.\n");
            }
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
    if (patientCount == 0) {
        printf("No patients to list.\n");
        return;
    }

    printf("Listing all patients:\n");
    for (int i = 0; i < patientCount; i++) {
        printf("Patient ID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Gender: %s\n", patients[i].gender);
        printf("Diagnosis: %s\n\n", patients[i].diagnosis);
    }
}

void searchPatientByName(const char *name) {
    printf("Search results for \"%s\":\n", name);
    bool found = false;
    for (int i = 0; i < patientCount; i++) {
        if (strstr(patients[i].name, name) != NULL) {
            printf("Patient ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %s\n", patients[i].gender);
            printf("Diagnosis: %s\n\n", patients[i].diagnosis);
            found = true;
        }
    }
    if (!found) {
        printf("No patients found with name \"%s\".\n", name);
    }
}

void displayStatistics() {
    if (patientCount == 0) {
        printf("No patients to display statistics.\n");
        return;
    }

    int totalAge = 0;
    for (int i = 0; i < patientCount; i++) {
        totalAge += patients[i].age;
    }
    printf("Total number of patients: %d\n", patientCount);
    printf("Average age of patients: %.2f\n", (float)totalAge / patientCount);
}

void clearInputBuffer() {
    while (getchar() != '\n');
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
        printf("6. Search Patient by Name\n");
        printf("7. Display Statistics\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter Patient ID: ");
                if (scanf("%d", &id) != 1 || id <= 0) {
                    printf("Invalid ID. Please enter a positive number.\n");
                    clearInputBuffer();
                    break;
                }
                if (!isIdValid(id)) {
                    printf("Patient ID %d already exists.\n", id);
                    break;
                }
                clearInputBuffer();
                printf("Enter Patient Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter Patient Age: ");
                if (scanf("%d", &age) != 1 || age <= 0) {
                    printf("Invalid age. Please enter a positive number.\n");
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                printf("Enter Patient Gender: ");
                fgets(gender, sizeof(gender), stdin);
                gender[strcspn(gender, "\n")] = 0;
                printf("Enter Patient Diagnosis: ");
                fgets(diagnosis, sizeof(diagnosis), stdin);
                diagnosis[strcspn(diagnosis, "\n")] = 0;
                addPatient(id, name, age, gender, diagnosis);
                break;
            case 2:
                printf("Enter Patient ID: ");
                if (scanf("%d", &id) != 1 || id <= 0) {
                    printf("Invalid ID. Please enter a positive number.\n");
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                printf("Enter Patient Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter Patient Age: ");
                if (scanf("%d", &age) != 1 || age <= 0) {
                    printf("Invalid age. Please enter a positive number.\n");
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                printf("Enter Patient Gender: ");
                fgets(gender, sizeof(gender), stdin);
                gender[strcspn(gender, "\n")] = 0;
                printf("Enter Patient Diagnosis: ");
                fgets(diagnosis, sizeof(diagnosis), stdin);
                diagnosis[strcspn(diagnosis, "\n")] = 0;
                updatePatient(id, name, age, gender, diagnosis);
                break;
            case 3:
                printf("Enter Patient ID to delete: ");
                if (scanf("%d", &id) != 1 || id <= 0) {
                    printf("Invalid ID. Please enter a positive number.\n");
                    clearInputBuffer();
                    break;
                }
                deletePatient(id);
                break;
            case 4:
                printf("Enter Patient ID to view details: ");
                if (scanf("%d", &id) != 1 || id <= 0) {
                    printf("Invalid ID. Please enter a positive number.\n");
                    clearInputBuffer();
                    break;
                }
                viewPatientDetails(id);
                break;
            case 5:
                listAllPatients();
                break;
            case 6:
                clearInputBuffer();
                printf("Enter Patient Name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                searchPatientByName(name);
                break;
            case 7:
                displayStatistics();
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
