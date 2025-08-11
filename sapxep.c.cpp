#include <stdio.h>

// ===== Cac ham sap xep =====
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

// ===== Ham in mang =====
void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ===== Ham nhap so nguyen an toan =====
int nhapSoNguyen() {
    int x;
    while (1) {
        if (scanf("%d", &x) == 1) {
            return x;
        } else {
            printf("Gia tri khong hop le! Vui long nhap so nguyen: ");
            while (getchar() != '\n'); // xoa bo dem
        }
    }
}

// ===== Main =====
int main() {
    int n, luaChon;

    printf("Nhap so phan tu: ");
    n = nhapSoNguyen();

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        arr[i] = nhapSoNguyen();
    }

    printf("\nChon thuat toan sap xep:\n");
    printf("1. Bubble Sort (Noi bot)\n");
    printf("2. Selection Sort (Chon truc tiep)\n");
    printf("3. Insertion Sort (Chen)\n");
    printf("4. Quick Sort (Nhanh)\n");
    printf("Lua chon: ");
    luaChon = nhapSoNguyen();

    switch (luaChon) {
        case 1: bubbleSort(arr, n); break;
        case 2: selectionSort(arr, n); break;
        case 3: insertionSort(arr, n); break;
        case 4: quickSort(arr, 0, n - 1); break;
        default: 
            printf("Lua chon khong hop le!\n");
            return 0;
    }

    printf("\nMang sau khi sap xep: ");
    inMang(arr, n);

    return 0;
}

