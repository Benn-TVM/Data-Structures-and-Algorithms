#include <stdio.h>

// Ham nhap mang tu ban phim
void nhapMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}
/*Bai4:Ham dem so phep so sanh khi thuc hien tim kiem tuyen tinh 
hoac tim kiem nhi phan tren mot day so da sap xep tang cho truoc*/
// Ham tim kiem tuyen tinh
int timKiemTuyenTinh(int arr[], int n, int x, int *soSanh) {
    for (int i = 0; i < n; i++) {
        (*soSanh)++;
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Ham tim kiem nhi phan
int timKiemNhiPhan(int arr[], int n, int x, int *soSanh) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*soSanh)++;
        if (arr[mid] == x) {
            return mid;
        }
        (*soSanh)++;
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Ham xuat ket qua tim kiem
void xuatKetQua(char* kieuTimKiem, int result, int soSanh) {
    if (result != -1) {
        printf("Tim thay gia tri tai vi tri %d (%s)\n", result, kieuTimKiem);
    } else {
        printf("Khong tim thay gia tri trong mang (%s)\n", kieuTimKiem);
    }
    printf("So phep so sanh (%s): %d\n", kieuTimKiem, soSanh);
}

int main() {
    int n, x, soSanh = 0;

    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhap cac phan tu cua mang (da sap xep tang dan): ");
    nhapMang(arr, n);

    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    // Kiem tra tim kiem tuyen tinh
    soSanh = 0;
    int result = timKiemTuyenTinh(arr, n, x, &soSanh);
    xuatKetQua("Tuyen tinh", result, soSanh);

    // Kiem tra tim kiem nhi phan
    soSanh = 0;
    result = timKiemNhiPhan(arr, n, x, &soSanh);
    xuatKetQua("Nhi phan", result, soSanh);

    return 0;
}

