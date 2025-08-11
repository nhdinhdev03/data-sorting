#include <stdio.h>
#include <string.h>
#include <ctype.h> // isdigit()

int containsDigit(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit((unsigned char)str[i])) {
            return 1; // Có ch?a s?
        }
    }
    return 0; // Không có s?
}

void sortStrings(char arr[][100], int n) {
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main() {
    int n;
    printf("Nhap so chuoi: ");
    scanf("%d", &n);
    getchar(); // Xóa ký t? xu?ng dòng trong b? d?m

    char arr[n][100];

    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Nhap chuoi thu %d: ", i + 1);
            fgets(arr[i], sizeof(arr[i]), stdin);
            arr[i][strcspn(arr[i], "\n")] = '\0'; // Xóa ký t? xu?ng dòng

            if (containsDigit(arr[i])) {
                printf("Loi: Khong duoc nhap chuoi co chua so! Vui long nhap lai.\n");
            } else if (strlen(arr[i]) == 0) {
                printf("Loi: Chuoi khong duoc de trong! Vui long nhap lai.\n");
            } else {
                break; // D? li?u h?p l?
            }
        }
    }

    sortStrings(arr, n);

    printf("\nDanh sach sau khi sap xep (A -> Z):\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}

