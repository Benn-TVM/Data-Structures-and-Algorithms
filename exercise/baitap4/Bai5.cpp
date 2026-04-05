#include <stdio.h>
#include <stdbool.h>

// Ham nhap mang tu ban phim
void nhapMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Ham xuat mang ra man hinh
void xuatMang(int arr[], int n) {
    printf("Cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham kiem tra mang tang dan hay khong
bool kiemTraMangTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Ham tim kiem tuyen tinh
int timKiemTuyenTinh(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Ham tim kiem nhi phan
int timKiemNhiPhan(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Ham chinh de thuc hien tim kiem
void thucHienTimKiem(int arr[], int n, int x) {
    int result;
    if (kiemTraMangTangDan(arr, n)) {
        printf("Mang da duoc sap xep tang dan.\n");
        result = timKiemNhiPhan(arr, n, x);
    } else {
        printf("Mang chua duoc sap xep tang dan.\n");
        result = timKiemTuyenTinh(arr, n, x);
    }

    // Xuat ket qua tim kiem
    if (result != -1) {
        printf("Tim thay gia tri %d tai vi tri %d.\n", x, result);
    } else {
        printf("Khong tim thay gia tri %d trong mang.\n", x);
    }
}

int main() {
    int n, x;
    
    // Nhap so luong phan tu cua mang
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    
    // Nhap cac phan tu cua mang
    nhapMang(arr, n);
    
    // Xuat cac phan tu cua mang
    xuatMang(arr, n);

    // Nhap gia tri can tim
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    // Thuc hien tim kiem
    thucHienTimKiem(arr, n, x);

    return 0;
}

