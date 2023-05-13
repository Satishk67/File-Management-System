#include <stdio.h>
#include <stdlib.h>

void create_file() {
    char filename[50];
    printf("Enter the name of the file you want to create: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to create file.\n");
    } else {
        printf("File created successfully.\n");
        fclose(fp);
    }
}

void delete_file() {
    char filename[50];
    printf("Enter the name of the file you want to delete: ");
    scanf("%s", filename);
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error: Unable to delete file.\n");
    }
}

void modify_file() {
    char filename[50];
    printf("Enter the name of the file you want to modify: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
    } else {
        printf("File opened successfully.\n");
        char new_text[1000];
        printf("Enter the new text for the file: ");
        scanf(" %[^\n]s", new_text);
        fp = fopen(filename, "w");
        fputs(new_text, fp);
        fclose(fp);
        printf("File modified successfully.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nFile Management System\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Modify file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                modify_file();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
