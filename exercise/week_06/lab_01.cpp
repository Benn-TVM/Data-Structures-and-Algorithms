#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dinh nghia cau truc sinh vien
typedef struct SinhVien {
    char maSV[10];
    char tenSV[40];
    float diemTB;
    struct SinhVien* next;
} SinhVien;

// Ham tao sinh vien moi
SinhVien* taoSinhVien(char* maSV, char* tenSV, float diemTB) {
    SinhVien* sv = (SinhVien*) malloc(sizeof(SinhVien));
    strcpy(sv->maSV, maSV);
    strcpy(sv->tenSV, tenSV);
    sv->diemTB = diemTB;
    sv->next = NULL;
    return sv;
}

// Ham them sinh vien vao cuoi danh sach
void themSinhVien(SinhVien** head, char* maSV, char* tenSV, float diemTB) {
    SinhVien* sv = taoSinhVien(maSV, tenSV, diemTB);
    if (*head == NULL) {
        *head = sv;
        return;
    }
    SinhVien* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = sv;
}

// Ham tinh trung binh cong diem cua sinh vien co diem trung binh > 7
float tinhTBCDiemLonHon7(SinhVien* head) {
    int count = 0;
    float sum = 0.0;
    SinhVien* temp = head;
    while (temp != NULL) {
        if (temp->diemTB > 7.0) {
            sum += temp->diemTB;
            count++;
        }
        temp = temp->next;
    }
    return (count == 0) ? 0 : sum / count;
}

// Ham tim sinh vien co diem trung binh lon nhat
SinhVien* timSVCoDiemTBLonNhat(SinhVien* head) {
    if (head == NULL) return NULL;
    SinhVien* maxSV = head;
    SinhVien* temp = head;
    while (temp != NULL) {
        if (temp->diemTB > maxSV->diemTB) {
            maxSV = temp;
        }
        temp = temp->next;
    }
    return maxSV;
}

// Ham sap xep danh sach sinh vien tang dan theo diem trung binh
void sapXepTangDanTheoDiemTB(SinhVien* head) {
    if (head == NULL) return;
    SinhVien* i;
    SinhVien* j;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->diemTB > j->diemTB) {
                // Hoan doi
                char maSVTmp[10], tenSVTmp[40];
                float diemTBTmp;
                strcpy(maSVTmp, i->maSV);
                strcpy(tenSVTmp, i->tenSV);
                diemTBTmp = i->diemTB;

                strcpy(i->maSV, j->maSV);
                strcpy(i->tenSV, j->tenSV);
                i->diemTB = j->diemTB;

                strcpy(j->maSV, maSVTmp);
                strcpy(j->tenSV, tenSVTmp);
                j->diemTB = diemTBTmp;
            }
        }
    }
}

// Ham sap xep danh sach sinh vien tang dan theo ten
void sapXepTangDanTheoTen(SinhVien* head) {
    if (head == NULL) return;
    SinhVien* i;
    SinhVien* j;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->tenSV, j->tenSV) > 0) {
                // Hoan doi
                char maSVTmp[10], tenSVTmp[40];
                float diemTBTmp;
                strcpy(maSVTmp, i->maSV);
                strcpy(tenSVTmp, i->tenSV);
                diemTBTmp = i->diemTB;

                strcpy(i->maSV, j->maSV);
                strcpy(i->tenSV, j->tenSV);
                i->diemTB = j->diemTB;

                strcpy(j->maSV, maSVTmp);
                strcpy(j->tenSV, tenSVTmp);
                j->diemTB = diemTBTmp;
            }
        }
    }
}

// Ham in danh sach sinh vien
void inDanhSach(SinhVien* head) {
    SinhVien* temp = head;
    while (temp != NULL) {
        printf("Ma SV: %s, Ten SV: %s, Diem TB: %.2f\n", temp->maSV, temp->tenSV, temp->diemTB);
        temp = temp->next;
    }
}

int main() {
    SinhVien* danhSach = NULL;

    // Them sinh vien vao danh sach
    themSinhVien(&danhSach, "SV01", "Nguyen Van A", 8.0);
    themSinhVien(&danhSach, "SV02", "Tran Thi B", 6.5);
    themSinhVien(&danhSach, "SV03", "Le Van C", 7.5);

    // In danh sach sinh vien
    printf("Danh sach sinh vien:\n");
    inDanhSach(danhSach);

    // Tinh trung binh cong diem cua sinh vien co diem trung binh > 7
    float tbc = tinhTBCDiemLonHon7(danhSach);
    printf("\nTrung binh cong diem cua SV co diem TB > 7: %.2f\n", tbc);

    // Tim sinh vien co diem trung binh lon nhat
    SinhVien* maxSV = timSVCoDiemTBLonNhat(danhSach);
    printf("\nSinh vien co diem TB lon nhat: %s - %s - %.2f\n", maxSV->maSV, maxSV->tenSV, maxSV->diemTB);

    // Sap xep danh sach sinh vien tang dan theo diem trung binh
    sapXepTangDanTheoDiemTB(danhSach);
    printf("\nDanh sach sinh vien sap xep tang dan theo diem TB:\n");
    inDanhSach(danhSach);

    // Sap xep danh sach sinh vien tang dan theo ten
    sapXepTangDanTheoTen(danhSach);
    printf("\nDanh sach sinh vien sap xep tang dan theo ten:\n");
    inDanhSach(danhSach);

    return 0;
}

