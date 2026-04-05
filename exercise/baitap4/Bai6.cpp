#include <stdio.h>
#include <string.h>

typedef struct {
    char maHang[9];
    char tenHang[41];
    float gia;
} HangHoa;

// Ham nhap thong tin hang hoa
void nhapHangHoa(HangHoa hh[], int *n) {
    printf("Nhap so luong hang hoa: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin hang hoa thu %d:\n", i + 1);
        printf("Ma hang: ");
        scanf("%s", hh[i].maHang);
        printf("Ten hang: ");
        scanf(" %[^\n]", hh[i].tenHang);
        printf("Gia: ");
        scanf("%f", &hh[i].gia);
    }
}

// Ham xuat danh sach hang hoa
void xuatHangHoa(HangHoa hh[], int n) {
    printf("\nDanh sach hang hoa:\n");
    for (int i = 0; i < n; i++) {
        printf("Ma: %s, Ten: %s, Gia: %.2f\n", hh[i].maHang, hh[i].tenHang, hh[i].gia);
    }
}

// Tim kiem tuan tu theo ma hang
int timKiemTuanTu(HangHoa hh[], int n, char ma[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(hh[i].maHang, ma) == 0)
            return i;
    }
    return -1;
}

// Ham sap xep danh sach hang hoa theo ten
void sapXepTheoTen(HangHoa hh[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(hh[i].tenHang, hh[j].tenHang) > 0) {
                HangHoa temp = hh[i];
                hh[i] = hh[j];
                hh[j] = temp;
            }
        }
    }
}

// Tim kiem nhi phan theo ten
int timKiemTen(HangHoa hh[], int n, char ten[]) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(hh[mid].tenHang, ten);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Ham sap xep danh sach hang hoa theo gia
void sapXepTheoGia(HangHoa hh[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (hh[i].gia > hh[j].gia) {
                HangHoa temp = hh[i];
                hh[i] = hh[j];
                hh[j] = temp;
            }
        }
    }
}

// Tim kiem nhi phan theo gia
int timKiemGia(HangHoa hh[], int n, float gia) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (hh[mid].gia == gia)
            return mid;
        else if (hh[mid].gia < gia)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    HangHoa hh[100];
    int n;

    // Nhap va xuat danh sach hang hoa
    nhapHangHoa(hh, &n);
    xuatHangHoa(hh, n);

    // Tim kiem theo ma
    char ma[9];
    printf("Nhap ma hang can tim: ");
    scanf("%s", ma);
    int idx = timKiemTuanTu(hh, n, ma);
    if (idx != -1)
        printf("Tim thay hang hoa co ma %s o vi tri %d.\n", ma, idx + 1);
    else
        printf("Khong tim thay hang hoa co ma %s.\n", ma);

    // Sap xep theo ten de tim kiem nhi phan
    sapXepTheoTen(hh, n);
    printf("\nDanh sach sau khi sap xep theo ten:\n");
    xuatHangHoa(hh, n);

    char ten[41];
    printf("Nhap ten hang can tim: ");
    scanf(" %[^\n]", ten);
    idx = timKiemTen(hh, n, ten);
    if (idx != -1)
        printf("Tim thay hang hoa co ten %s o vi tri %d.\n", ten, idx + 1);
    else
        printf("Khong tim thay hang hoa co ten %s.\n", ten);

    // Sap xep theo gia de tim kiem nhi phan
    sapXepTheoGia(hh, n);
    printf("\nDanh sach sau khi sap xep theo gia:\n");
    xuatHangHoa(hh, n);

    float gia;
    printf("Nhap gia hang can tim: ");
    scanf("%f", &gia);
    idx = timKiemGia(hh, n, gia);
    if (idx != -1)
        printf("Tim thay hang hoa co gia %.2f o vi tri %d.\n", gia, idx + 1);
    else
        printf("Khong tim thay hang hoa co gia %.2f.\n", gia);

    return 0;
}

