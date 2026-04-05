#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

// Ham hoan doi gia tri cua hai bien
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ham sap xep noi bot
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

// Ham sap xep chon
void selectionSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(&a[min_idx], &a[i]);
    }
}

// Ham sap xep chen
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Ham sap xep doi cho
void interchangeSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

// Ham phan hoach cho Quick Sort
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j <= high-1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

// Ham sap xep nhanh (Quick Sort)
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

// Ham sinh mang ngau nhien
void mangrandom(int a[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

// Ham in mang
void xuatmang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Ham hien thi menu
void hienThiMenu() {
    printf("Chon phuong phap sap xep:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Interchange Sort\n");
    printf("5. Quick Sort\n");
}

// Ham dem thoi gian chay cho cac ham sap xep khong co tham so high
double demThoiGian(void (*sortFunc)(int[], int), int a[], int n) {
    clock_t start, end;
    start = clock();
    sortFunc(a, n);
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// Ham dem thoi gian chay cho ham quickSort
double demThoiGianQuickSort(void (*sortFunc)(int[], int, int), int a[], int low, int high) {
    clock_t start, end;
    start = clock();
    sortFunc(a, low, high);
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main() {
    int a[MAX];
    int n, choice;
    double thoiGianChay;

    // Nhap so luong phan tu cua mang
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    // Sinh mang ngau nhien
    mangrandom(a, n);

    // In mang ngau nhien
    printf("Mang ngau nhien: \n");
    xuatmang(a, n);

    // Hien thi menu
    hienThiMenu();
    scanf("%d", &choice);

    // Thuc hien sap xep va do thoi gian chay
    switch(choice) {
        case 1:
            thoiGianChay = demThoiGian(bubbleSort, a, n);
            break;
        case 2:
            thoiGianChay = demThoiGian(selectionSort, a, n);
            break;
        case 3:
            thoiGianChay = demThoiGian(insertionSort, a, n);
            break;
        case 4:
            thoiGianChay = demThoiGian(interchangeSort, a, n);
            break;
        case 5:
            thoiGianChay = demThoiGianQuickSort(quickSort, a, 0, n-1);
            break;
        default:
            printf("Lua chon khong hop le.\n");
            return 1;
    }

    // In mang sau khi sap xep
    printf("Mang sau khi sap xep: \n");
    xuatmang(a, n);
    
    // In thoi gian chay
    printf("Thoi gian chay: %f giay\n", thoiGianChay);

    return 0;
}

