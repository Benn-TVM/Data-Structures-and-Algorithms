#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dinh nghia cau truc sinh vien
typedef struct {
    char maSV[10];
    char hoTen[50];
    float diemTB;
} SinhVien;

// Dinh nghia cau truc nut trong danh sach lien ket don
typedef struct Node {
    SinhVien data;
    struct Node* next;
} Node;

// Ham tao sinh vien moi
SinhVien taoSinhVien(char* maSV, char* hoTen, float diemTB) {
    SinhVien sv;
    strcpy(sv.maSV, maSV);
    strcpy(sv.hoTen, hoTen);
    sv.diemTB = diemTB;
    return sv;
}

// Ham tao nut moi
Node* taoNode(SinhVien data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Ham them nut vao cuoi danh sach lien ket
void themCuoi(Node** head, SinhVien data) {
    Node* newNode = taoNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Ham xuat danh sach lien ket
void xuatDanhSach(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Ma SV: %s, Ho ten: %s, Diem TB: %.2f\n", temp->data.maSV, temp->data.hoTen, temp->data.diemTB);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    int n;
    char maSV[10];
    char hoTen[50];
    float diemTB;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); // Xoa ky tu '\n' con lai trong bo dem

    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ma SV: ");
        fgets(maSV, sizeof(maSV), stdin);
        maSV[strcspn(maSV, "\n")] = '\0'; // Loai bo ky tu '\n'

        printf("Ho ten: ");
        fgets(hoTen, sizeof(hoTen), stdin);
        hoTen[strcspn(hoTen, "\n")] = '\0';

        printf("Diem TB: ");
        scanf("%f", &diemTB);
        getchar();

        SinhVien sv = taoSinhVien(maSV, hoTen, diemTB);
        themCuoi(&head, sv);
    }

    printf("\nDanh sach sinh vien:\n");
    xuatDanhSach(head);

    return 0;
}

