#include <stdio.h>
#include <string.h>

typedef struct {
    char book_id[20];
    char book_name[50];
    char author[50];
    float price;
    char category[30];
} Book;

void input_books(Book books[], int *n) {
    printf("Nhap so luong sach: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin cho sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", books[i].book_id);
        printf("Ten sach: ");
        getchar();
        fgets(books[i].book_name, sizeof(books[i].book_name), stdin);
        books[i].book_name[strcspn(books[i].book_name, "\n")] = 0;
        printf("Tac gia: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;
        printf("Gia tien: ");
        scanf("%f", &books[i].price);
        printf("The loai: ");
        getchar();
        fgets(books[i].category, sizeof(books[i].category), stdin);
        books[i].category[strcspn(books[i].category, "\n")] = 0;
    }
}

void display_books(Book books[], int n) {
    printf("\n%-10s %-30s %-20s %-10s %-20s\n", "Ma sach", "Ten sach", "Tac gia", "Gia", "The loai");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-30s %-20s %-10.2f %-20s\n", books[i].book_id, books[i].book_name, books[i].author, books[i].price, books[i].category);
    }
}

void add_book(Book books[], int *n, int position) {
    if (position < 0 || position > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = *n; i > position; i--) {
        books[i] = books[i - 1];
    }
    printf("\nNhap thong tin cho sach moi:\n");
    printf("Ma sach: ");
    scanf("%s", books[position].book_id);
    printf("Ten sach: ");
    getchar();
    fgets(books[position].book_name, sizeof(books[position].book_name), stdin);
    books[position].book_name[strcspn(books[position].book_name, "\n")] = 0;
    printf("Tac gia: ");
    fgets(books[position].author, sizeof(books[position].author), stdin);
    books[position].author[strcspn(books[position].author, "\n")] = 0;
    printf("Gia tien: ");
    scanf("%f", &books[position].price);
    printf("The loai: ");
    getchar();
    fgets(books[position].category, sizeof(books[position].category), stdin);
    books[position].category[strcspn(books[position].category, "\n")] = 0;
    (*n)++;
}

void delete_book(Book books[], int *n, char book_id[]) {
    int found = -1;
    for (int i = 0; i < *n; i++) {
        if (strcmp(books[i].book_id, book_id) == 0) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Khong tim thay sach co ma %s.\n", book_id);
        return;
    }
    for (int i = found; i < *n - 1; i++) {
        books[i] = books[i + 1];
    }
    (*n)--;
    printf("Da xoa sach co ma %s thanh cong.\n", book_id);
}

void update_book(Book books[], int n, char book_id[]) {
    int found = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].book_id, book_id) == 0) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Khong tim thay sach co ma %s.\n", book_id);
        return;
    }
    printf("\nCap nhat thong tin cho sach co ma %s:\n", book_id);
    printf("Ten sach: ");
    getchar();
    fgets(books[found].book_name, sizeof(books[found].book_name), stdin);
    books[found].book_name[strcspn(books[found].book_name, "\n")] = 0;
    printf("Tac gia: ");
    fgets(books[found].author, sizeof(books[found].author), stdin);
    books[found].author[strcspn(books[found].author, "\n")] = 0;
    printf("Gia tien: ");
    scanf("%f", &books[found].price);
    printf("The loai: ");
    getchar();
    fgets(books[found].category, sizeof(books[found].category), stdin);
    books[found].category[strcspn(books[found].category, "\n")] = 0;
    printf("Cap nhat thanh cong.\n");
}

void sort_books(Book books[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && books[i].price > books[j].price) || (!ascending && books[i].price < books[j].price)) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong.\n");
}

void search_book(Book books[], int n, char book_name[]) {
    printf("\nKet qua tim kiem cho ten sach '%s':\n", book_name);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(books[i].book_name, book_name)) {
            printf("%-10s %-30s %-20s %-10.2f %-20s\n", books[i].book_id, books[i].book_name, books[i].author, books[i].price, books[i].category);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sach voi ten '%s'.\n", book_name);
    }
}

int main() {
    Book books[100];
    int n = 0;
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma\n");
        printf("5. Cap nhat thong tin sach theo ma\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_books(books, &n);
                break;
            case 2:
                display_books(books, n);
                break;
            case 3: {
                int position;
                printf("Nhap vi tri de them sach (0 den %d): ", n);
                scanf("%d", &position);
                add_book(books, &n, position);
                break;
            }
            case 4: {
                char book_id[20];
                printf("Nhap ma sach de xoa: ");
                scanf("%s", book_id);
                delete_book(books, &n, book_id);
                break;
            }
            case 5: {
                char book_id[20];
                printf("Nhap ma sach de cap nhat: ");
                scanf("%s", book_id);
                update_book(books, n, book_id);
                break;
            }
            case 6: {
                int order;
                printf("Nhap 1 de sap xep tang, 0 de sap xep giam: ");
                scanf("%d", &order);
                sort_books(books, n, order);
                break;
            }
            case 7: {
                char book_name[50];
                printf("Nhap ten sach de tim kiem: ");
                getchar();
                fgets(book_name, sizeof(book_name), stdin);
                book_name[strcspn(book_name, "\n")] = 0;
                search_book(books, n, book_name);
                break;
            }
            case 8:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 8);

    return 0;
}

