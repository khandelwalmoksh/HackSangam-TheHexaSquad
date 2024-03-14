#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15

// Structure to represent user profile
struct UserProfile {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

// Function to display user profile
void displayProfile(struct UserProfile profile) {
    printf("Name: %s\n", profile.name);
    printf("Email: %s\n", profile.email);
    printf("Phone: %s\n", profile.phone);
}

// Function to update user profile
void updateProfile(struct UserProfile *profile) {
    printf("Enter new name: ");
    fgets(profile->name, sizeof(profile->name), stdin);
    profile->name[strcspn(profile->name, "\n")] = '\0'; // Remove newline character

    printf("Enter new email: ");
    fgets(profile->email, sizeof(profile->email), stdin);
    profile->email[strcspn(profile->email, "\n")] = '\0'; // Remove newline character

    printf("Enter new phone number: ");
    fgets(profile->phone, sizeof(profile->phone), stdin);
    profile->phone[strcspn(profile->phone, "\n")] = '\0'; // Remove newline character
}

int main() {
    struct UserProfile user;
    
    // Initialize profile with default values
    strcpy(user.name, "John Doe");
    strcpy(user.email, "john.doe@example.com");
    strcpy(user.phone, "+1234567890");

    printf("Current Profile:\n");
    displayProfile(user);

    printf("\nDo you want to update your profile? (yes/no): ");
    char choice[5];
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0'; // Remove newline character

    if (strcmp(choice, "yes") == 0) {
        updateProfile(&user);
        printf("\nProfile updated successfully!\n");
    } else {
        printf("\nNo changes made to the profile.\n");
    }

    printf("\nUpdated Profile:\n");
    displayProfile(user);

    return 0;
}