#include <stdio.h>

// Ham dem so phep so sanh va phep gan
void countOperations(int a[], int n, int *phepss, int *phepgan) {
    *phepss = 0;
    *phepgan = 0;
}

// Bubble Sort
void bubbleSort(int a[], int n, int *phepss, int *phepgan) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            (*phepss)++;
            if (a[j] > a[j+1]) {
                // Hoan doi
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                (*phepgan)++;
            }
        }
    }
}

// Selection Sort
void selectionSort(int a[], int n, int *phepss, int *phepgan) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            (*phepss)++;
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            // Hoan doi
            int temp = a[i];
            a[i] = a[minIdx];
            a[minIdx] = temp;
            (*phepgan)++;
        }
    }
}

// Insertion Sort
void insertionSort(int a[], int n, int *phepss, int *phepgan) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            (*phepss)++;
            a[j + 1] = a[j];
            j--;
            (*phepgan)++;
        }
        a[j + 1] = key;
        (*phepgan)++;
    }
}

// Interchange Sort
void interchangeSort(int a[], int n, int *phepss, int *phepgan) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            (*phepss)++;
            if (a[i] > a[j]) {
                // Hoan doi
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                (*phepgan)++;
            }
        }
    }
}

// Quick Sort
int partition(int a[], int low, int high, int *phepss, int *phepgan) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        (*phepss)++;
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            (*phepgan)++;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    (*phepgan)++;
    return i + 1;
}

void quickSort(int a[], int low, int high, int *phepss, int *phepgan) {
    if (low < high) {
        int pi = partition(a, low, high, phepss, phepgan);
        quickSort(a, low, pi - 1, phepss, phepgan);
        quickSort(a, pi + 1, high, phepss, phepgan);
    }
}

// Ham xuat mang
void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    
    int a[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int phepss, phepgan;

    // Bubble Sort
    int a2[n];
    for (int i = 0; i < n; i++) a2[i] = a[i];
    countOperations(a2, n, &phepss, &phepgan);
    bubbleSort(a2, n, &phepss, &phepgan);
    printf("Bubble Sort:\n");
    xuatMang(a2, n);
    printf("So phep so sanh: %d, So phep gan: %d\n\n", phepss, phepgan);

    // Selection Sort
    int a3[n];
    for (int i = 0; i < n; i++) a3[i] = a[i];
    countOperations(a3, n, &phepss, &phepgan);
    selectionSort(a3, n, &phepss, &phepgan);
    printf("Selection Sort:\n");
    xuatMang(a3, n);
    printf("So phep so sanh: %d, So phep gan: %d\n\n", phepss, phepgan);

    // Insertion Sort
    int a4[n];
    for (int i = 0; i < n; i++) a4[i] = a[i];
    countOperations(a4, n, &phepss, &phepgan);
    insertionSort(a4, n, &phepss, &phepgan);
    printf("Insertion Sort:\n");
    xuatMang(a4, n);
    printf("So phep so sanh: %d, So phep gan: %d\n\n", phepss, phepgan);

    // Interchange Sort
    int a5[n];
    for (int i = 0; i < n; i++) a5[i] = a[i];
    countOperations(a5, n, &phepss, &phepgan);
    interchangeSort(a5, n, &phepss, &phepgan);
    printf("Interchange Sort:\n");
    xuatMang(a5, n);
    printf("So phep so sanh: %d, So phep gan: %d\n\n", phepss, phepgan);

    // Quick Sort
    int a6[n];
    for (int i = 0; i < n; i++) a6[i] = a[i];
    countOperations(a6, n, &phepss, &phepgan);
    quickSort(a6, 0, n-1, &phepss, &phepgan);
    printf("Quick Sort:\n");
    xuatMang(a6, n);
    printf("So phep so sanh: %d, So phep gan: %d\n", phepss, phepgan);

    return 0;
}

