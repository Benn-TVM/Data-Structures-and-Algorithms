#include <stdio.h>
#include <string.h>

typedef struct {
	char mssv[11];
    char ten[50];
    int tuoi;
    char lop[7];
} SinhVien;

void nhapSinhVien(SinhVien &sv) {
	printf("Nhap MSSV: ");
	scanf("%s", sv.mssv);
    printf("Nhap ten sinh vien: ");
	scanf("%s", sv.ten);
    getchar();
    printf("Nhap tuoi: ");
    scanf("%d", &sv.tuoi);
    printf("Lop: ");
    scanf("%s", &sv.lop);
    printf("\n");
}

void xuatSinhVien(SinhVien sv) {
	printf("\nNhap MSSV: %s\n", sv.mssv);
    printf("Thong tin sinh vien: %s\n", sv.ten);
    printf("Ten: %s\n", sv.ten);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("Lop: %s\n", sv.lop);
}
void nhap1sv (int n) {
	SinhVien sv;
	for (int i = 1; i <= n; i ++) {
		nhapSinhVien(sv);
	}
}

void xuat1sv (int n) {
	SinhVien sv;
	for (int i = 1; i <= n; i ++) {
		xuatSinhVien(sv);
	}
}

int main() {
	int n;
	printf("Nhap so sinh vien: ");
	scanf("%d", &n);
    SinhVien sv;
    nhap1sv (n);
    xuat1sv (n);
    return 0;
}

