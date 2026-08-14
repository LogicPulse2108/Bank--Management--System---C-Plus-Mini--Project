#include <stdio.h>

struct Book {
    int id;
    char name[30];
    int issued;
};

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("Thank you!\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}

void addBook() {
    FILE *fp;
    struct Book b;

    fp = fopen("books.dat", "ab");

    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Name: ");
    scanf(" %29[^\n]", b.name);

    b.issued = 0;

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("Book added successfully!\n");
}

void displayBooks() {
    FILE *fp;
    struct Book b;

    fp = fopen("books.dat", "rb");

    if(fp == NULL) {
        printf("No books available.\n");
        return;
    }

    printf("\nID\tBook Name\tStatus\n");
    printf("--------------------------------\n");

    while(fread(&b, sizeof(b), 1, fp)) {
        printf("%d\t%-15s\t%s\n",
               b.id,
               b.name,
               b.issued ? "Issued" : "Available");
    }

    fclose(fp);
}

void searchBook() {
    FILE *fp;
    struct Book b;
    int id, found = 0;

    fp = fopen("books.dat", "rb");

    if(fp == NULL) {
        printf("No books available.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    while(fread(&b, sizeof(b), 1, fp)) {
        if(b.id == id) {
            printf("Book Found: %s\n", b.name);
            printf("Status: %s\n",
                   b.issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Book not found.\n");

    fclose(fp);
}

void issueBook() {
    FILE *fp;
    struct Book b;
    int id, found = 0;

    fp = fopen("books.dat", "rb+");

    if(fp == NULL) {
        printf("No books available.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    while(fread(&b, sizeof(b), 1, fp)) {
        if(b.id == id) {
            found = 1;

            if(b.issued) {
                printf("Book is already issued.\n");
            } else {
                b.issued = 1;
                fseek(fp, -sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Book issued successfully!\n");
            }
            break;
        }
    }

    if(!found)
        printf("Book not found.\n");

    fclose(fp);
}

void returnBook() {
    FILE *fp;
    struct Book b;
    int id, found = 0;

    fp = fopen("books.dat", "rb+");

    if(fp == NULL) {
        printf("No books available.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    while(fread(&b, sizeof(b), 1, fp)) {
        if(b.id == id) {
            found = 1;

            if(!b.issued) {
                printf("Book is already available.\n");
            } else {
                b.issued = 0;
                fseek(fp, -sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                printf("Book returned successfully!\n");
            }
            break;
        }
    }

    if(!found)
        printf("Book not found.\n");

    fclose(fp);
}
