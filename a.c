#include <stdio.h>
#include <string.h>

// Define a structure to hold user information
struct User {
    char name[50];
    int age;
    char email[50];
    char address[100];
};

int main() {
    // Declare a variable of type User
    struct User user;

    // Prompt the user to enter information
    printf("Enter your name: ");
    scanf("%s", user.name);

    printf("Enter your age: ");
    scanf("%d", &user.age);

    printf("Enter your email: ");
    scanf("%s", user.email);

    printf("Enter your address: ");
    scanf("%s", user.address);

    // Display the information
    printf("\nUser Information:\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Email: %s\n", user.email);
    printf("Address: %s\n", user.address);

    return 0;
}