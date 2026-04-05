#include <stdio.h>
#include <stdlib.h>

// Khai bao cau truc cua mot don thuc
typedef struct DonThuc {
    float heSo;
    int bac;
    struct DonThuc* next;
} DonThuc;

// Ham tao mot don thuc
DonThuc* taoDonThuc(float heSo, int bac) {
    DonThuc* newNode = (DonThuc*)malloc(sizeof(DonThuc));
    newNode->heSo = heSo;
    newNode->bac = bac;
    newNode->next = NULL;
    return newNode;
}

// Ham chen don thuc vao dau danh sach
void chenDonThuc(DonThuc** head, float heSo, int bac) {
    DonThuc* newNode = taoDonThuc(heSo, bac);
    newNode->next = *head;
    *head = newNode;
}

// Ham tim bac cao nhat trong da thuc
int timBacCaoNhat(DonThuc* head) {
    int maxBac = 0;
    while (head != NULL) {
        if (head->bac > maxBac) {
            maxBac = head->bac;
        }
        head = head->next;
    }
    return maxBac;
}

// Ham tinh gia tri cua mot don thuc tai gia tri x cho truoc
float tinhGiaTriDonThuc(DonThuc* donThuc, float x) {
    float ketQua = donThuc->heSo;
    int i;
    for (i = 0; i < donThuc->bac; i++) {
        ketQua *= x;
    }
    return ketQua;
}

// Ham tinh gia tri cua da thuc tai gia tri x cho truoc
float tinhGiaTriDaThuc(DonThuc* head, float x) {
    float ketQua = 0;
    while (head != NULL) {
        ketQua += tinhGiaTriDonThuc(head, x);
        head = head->next;
    }
    return ketQua;
}

// Ham hien thi da thuc
void hienThiDaThuc(DonThuc* head) {
    while (head != NULL) {
        if (head->bac == 0) {
            printf("%.2f", head->heSo);
        } else if (head->bac == 1) {
            printf("%.2fx", head->heSo);
        } else {
            printf("%.2fx^%d", head->heSo, head->bac);
        }
        if (head->next != NULL) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    DonThuc* daThuc = NULL;
    int n, i;
    float heSo, x;
    int bac;

    // Nhap so luong don thuc
    printf("Nhap so luong don thuc: ");
    scanf("%d", &n);

    // Nhap thong tin cac don thuc
    for (i = 0; i < n; i++) {
        printf("Nhap he so va bac cua don thuc thu %d: ", i + 1);
        scanf("%f %d", &heSo, &bac);
        chenDonThuc(&daThuc, heSo, bac);
    }

    // Hien thi da thuc
    printf("\nDa thuc vua nhap: ");
    hienThiDaThuc(daThuc);

    // Tim bac cao nhat trong da thuc
    int maxBac = timBacCaoNhat(daThuc);
    printf("Bac cao nhat trong da thuc: %d\n", maxBac);

    // Tinh gia tri cua da thuc tai x cho truoc
    printf("Nhap gia tri x: ");
    scanf("%f", &x);
    float ketQua = tinhGiaTriDaThuc(daThuc, x);
    printf("Gia tri cua da thuc tai x = %.2f la: %.2f\n", x, ketQua);

    return 0;
}

