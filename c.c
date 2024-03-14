#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store vehicle information
typedef struct {
    char vehicleNumber[15];
    char parkingTime[10];
} Vehicle;

// Function to add a vehicle entry
void addVehicle() {
    Vehicle v;
    printf("Enter vehicle number: ");
    scanf("%s", v.vehicleNumber);
    printf("Enter parking time: ");
    scanf("%s", v.parkingTime);

    FILE *file = fopen("vehicles.dat", "ab+");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fwrite(&v, sizeof(Vehicle), 1, file);
    fclose(file);
    printf("Vehicle added successfully.\n");
}

// Function to display all parked vehicles
void displayVehicles() {
    Vehicle v;
    FILE *file = fopen("vehicles.dat", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    while (fread(&v, sizeof(Vehicle), 1, file)) {
        printf("Vehicle Number: %s, Parking Time: %s\n", v.vehicleNumber, v.parkingTime);
    }
    fclose(file);
}

// Main function
int main() {
    int choice;
    do {
        printf("\nVehicle Tracking System\n");
        printf("1. Add Vehicle Entry\n");
        printf("2. Display Parked Vehicles\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVehicle();
                break;
            case 2:
                displayVehicles();
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}