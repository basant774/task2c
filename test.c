#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef union {
    int flag;
    char active[2];
} Flag;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    Flag activeFlag;
} User;

User users[MAX_USERS];
int totalUsers = 0;

void registerUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int active;

    printf("Please enter your username: ");
    scanf("%s", username);

    printf("Please enter your password: ");
    scanf("%s", password);

    printf("Please enter 1 for active or 0 for inactive: ");
    scanf("%d", &active);

    if (totalUsers >= MAX_USERS) {
        printf("Cannot register more users.\n");
        return;
    }

    strcpy(users[totalUsers].username, username);
    strcpy(users[totalUsers].password, password);
    users[totalUsers].activeFlag.flag = active;
    totalUsers++;

    printf("User registered successfully.\n");
}

void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Please enter your username: ");
    scanf("%s", username);

    printf("Please enter your password: ");
    scanf("%s", password);

    int loggedIn = 0;

    for (int i = 0; i < totalUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (users[i].activeFlag.flag) {
                printf("Login successful.\n");
                loggedIn = 1;
            } else {
                printf("User is inactive. Please contact the administrator.\n");
            }
            break;
        }
    }

    if (!loggedIn) {
        printf("Login failed.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
