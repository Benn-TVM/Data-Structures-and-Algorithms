#include <stdio.h>
#include <string.h>

#define MAX 100

// Khai bao thong tin
typedef struct {
    char maSo[20];
    char hoTen[50];
    float diemTB;
} SinhVien;

// Ham nhap danh sach sinh vien
void nhapDanhSach(SinhVien sv[], int *n) {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", n);
    getchar(); // Xoa ky tu xuong dong con lai trong bo dem

    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ma so sinh vien: ");
        fgets(sv[i].maSo, sizeof(sv[i].maSo), stdin);
        sv[i].maSo[strcspn(sv[i].maSo, "\n")] = 0; // Xoa ky tu xuong dong

        printf("Ho ten: ");
        fgets(sv[i].hoTen, sizeof(sv[i].hoTen), stdin);
        sv[i].hoTen[strcspn(sv[i].hoTen, "\n")] = 0; // Xoa ky tu xuong dong

        printf("Diem trung binh: ");
        scanf("%f", &sv[i].diemTB);
        getchar(); // Xoa ky tu xuong dong con lai trong bo dem
    }
}

// Ham hien thi danh sach sinh vien
void hienThiDanhSach(SinhVien sv[], int n) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("Ma so: %s, Ho ten: %s, Diem TB: %.2f\n", sv[i].maSo, sv[i].hoTen, sv[i].diemTB);
    }
}

// Ham sap xep danh sach tang dan theo ho ten
void sapXepTheoHoTen(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(sv[i].hoTen, sv[j].hoTen) > 0) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

// Ham sap xep danh sach giam dan theo diem trung binh
void sapXepTheoDiemTB(SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diemTB < sv[j].diemTB) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

int main() {
    SinhVien sv[MAX];
    int n;

    nhapDanhSach(sv, &n);

    printf("\nDanh sach ban dau:");
    hienThiDanhSach(sv, n);

    sapXepTheoHoTen(sv, n);
    printf("\nDanh sach sap xep tang dan theo ho ten:");
    hienThiDanhSach(sv, n);

    sapXepTheoDiemTB(sv, n);
    printf("\nDanh sach sap xep giam dan theo diem trung binh:");
    hienThiDanhSach(sv, n);

    return 0;
}

