#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Dinh nghia cau truc cua mot nut
typedef struct Node {
    int he_so;
    int so_mu;
    struct Node* next;
} Node;

// Ham tao nut moi
Node* taoNode(int he_so, int so_mu) {
    Node* New_Node = (Node*)malloc(sizeof(Node));
    New_Node->he_so = he_so;
    New_Node->so_mu = so_mu;
    New_Node->next = NULL;
    return New_Node;
}

// Ham khoi tao da thuc (danh sach rong)
Node* khoiTaoDaThuc() {
    return NULL;
}

// Ham them hang tu vao da thuc
void themHangTu(Node** dau, int he_so, int so_mu) {
    Node* New_Node = taoNode(he_so, so_mu);
    if (*dau == NULL || (*dau)->so_mu < so_mu) {
        New_Node->next = *dau;
        *dau = New_Node;
    } else {
        Node* hien_tai = *dau;
        while (hien_tai->next != NULL && hien_tai->next->so_mu > so_mu) {
            hien_tai = hien_tai->next;
        }
        New_Node->next = hien_tai->next;
        hien_tai->next = New_Node;
    }
}

// Ham hien thi da thuc
void hienThiDaThuc(Node* dau) {
    Node* hien_tai = dau;
    while (hien_tai != NULL) {
        printf("%dx^%d", hien_tai->he_so, hien_tai->so_mu);
        if (hien_tai->next != NULL)
            printf(" + ");
        hien_tai = hien_tai->next;
    }
    printf("\n");
}

// Ham tinh gia tri da thuc tai gia tri x cho truoc
int tinhGiaTriDaThuc(Node* dau, int x) {
    int gia_tri = 0;
    Node* hien_tai = dau;
    while (hien_tai != NULL) {
        gia_tri += hien_tai->he_so * pow(x, hien_tai->so_mu);
        hien_tai = hien_tai->next;
    }
    return gia_tri;
}

int main() {
    Node* da_thuc = khoiTaoDaThuc();
    
    // Them cac hang tu vao da thuc
    themHangTu(&da_thuc, 5, 2);
    themHangTu(&da_thuc, 3, 1);
    themHangTu(&da_thuc, 2, 0);
    
    // Hien thi da thuc
    printf("Da thuc: ");
    hienThiDaThuc(da_thuc);
    
    // Tinh gia tri da thuc tai x = 2
    int x = 2;
    int gia_tri = tinhGiaTriDaThuc(da_thuc, x);
    printf("Gia tri cua da thuc tai x = %d la: %d\n", x, gia_tri);
    
    return 0;
}

