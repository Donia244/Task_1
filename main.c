#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 30

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount < MAX_USERS) {
        User newUser;

        printf("Enter your username (up to %d characters): ", MAX_USERNAME_LENGTH);
        scanf("%s", newUser.username);

        printf("Enter your password (up to %d characters): ", MAX_PASSWORD_LENGTH);
        scanf("%s", newUser.password);

        users[userCount] = newUser;
        userCount++;
        printf("Registration successful!\n");
    } else {
        printf(" Cannot register\n");
    }
}

int loginUser() {
    char inputUsername[MAX_USERNAME_LENGTH];
    char inputPassword[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", inputUsername);

    printf("Enter your password: ");
    scanf("%s", inputPassword);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(inputUsername, users[i].username) == 0 && strcmp(inputPassword, users[i].password) == 0) {
            printf("Login successful!\n");
            return 1;
        }
    }
    
    printf("Invalid username or password.\n");
    return 0;
}

int main() {
    int choice;

    while (1) {
        printf("1. Register\n2. Login\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                
                }
                break;
            
                return 0;
            default:
                printf("Please try again\n");
        }
    }

    return 0;
}