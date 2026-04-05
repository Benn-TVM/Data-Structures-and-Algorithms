#include <stdio.h>

#define MAX 100

// Dinh nghia cau truc danh sach lien ket
typedef struct tList {
    int num;            // So luong phan tu hien tai trong danh sach
    int nodes[MAX];     // Mang luu tru cac phan tu cua danh sach
} LIST;

// Ham khoi tao danh sach, dat so luong phan tu ve 0
void Init(LIST &plist) {
    plist.num = 0;
}

// Ham nhap du lieu cho danh sach tu nguoi dung
void InputList(LIST &plist) {
    int i;
    do {
        printf("Nhap so luong nut: "); // Nhap so luong nut tu nguoi dung
        scanf("%d", &plist.num);
    } while (plist.num <= 0 || plist.num > MAX); // Kiem tra so luong nut hop le

    for (i = 0; i < plist.num; i++) {
        printf("Nhap nut thu %d: ", i); // Nhap tung nut mot
        scanf("%d", &plist.nodes[i]);
    }
}

// Ham kiem tra danh sach rong
int IsEmpty(LIST plist) {
    return (plist.num == 0); // Tra ve 1 neu danh sach rong, nguoc lai tra ve 0
}

// Ham kiem tra danh sach day
int IsFull(LIST plist) {
    return (plist.num == MAX); // Tra ve 1 neu danh sach day, nguoc lai tra ve 0
}

// Ham lay kich thuoc danh sach
int ListSize(LIST plist) {
    return plist.num; // Tra ve so luong phan tu trong danh sach
}

// Ham truy xuat gia tri tu danh sach dua tren vi tri
int Retrieve(LIST plist, int pos, int &x) {
    if (IsEmpty(plist)) {
        printf("Danh sach bi rong.");
        return 0; // Khong thanh cong
    }

    if (pos < 0 || pos >= ListSize(plist)) {
        printf("Vi tri %d khong hop le.", pos);
        return 0; // Khong thanh cong
    }

    x = plist.nodes[pos];
    return 1; // Truy xuat thanh cong
}

// Ham chen mot phan tu moi vao danh sach tai vi tri chi dinh
int Insert(LIST &plist, int pos, int x) {
    int i;
    if (IsFull(plist)) {
        printf("Danh Sach bi day.");
        return 0; // Khong thanh cong
    }

    if (pos < 0 || pos > ListSize(plist)) {
        printf("Vi tri %d khong hop le.", pos);
        return 0; // Khong thanh cong
    }

    for (i = ListSize(plist) - 1; i >= pos; i--)
        plist.nodes[i + 1] = plist.nodes[i]; // Dich chuyen cac phan tu phia sau vi tri chen sang phai
    plist.nodes[pos] = x; // Chen phan tu moi vao vi tri
    plist.num++;
    return 1; // Chen thanh cong
}

// Ham xoa mot phan tu tai vi tri chi dinh trong danh sach
int Remove(LIST &plist, int pos, int &x) {
    int i;
    if (IsEmpty(plist)) {
        printf("Danh sach rong.");
        return 0; // Khong thanh cong
    }

    if (pos < 0 || pos >= ListSize(plist)) {
        printf("Vi tri %d khong hop le.", pos);
        return 0; // Khong thanh cong
    }

    x = plist.nodes[pos]; // Luu lai gia tri cua phan tu bi xoa
    for (i = pos; i < ListSize(plist) - 1; i++)
        plist.nodes[i] = plist.nodes[i + 1]; // Dich chuyen cac phan tu phia sau vi tri xoa sang trai
    plist.num--;
    return 1; // Xoa thanh cong
}

// Ham tim kiem mot phan tu trong danh sach
int Search(LIST plist, int x) {
    int i;
    for (i = 0; i < plist.num; i++)
        if (plist.nodes[i] == x)
            return i; // Tra ve vi tri cua phan tu tim thay
    return -1; // Khong tim thay phan tu
}

// Ham duyet va in ra cac phan tu trong danh sach
void ShowList(LIST plist) {
    int i;
    if (plist.num == 0) {
        printf("Danh sach rong.");
        return;
    }
    for (i = 0; i < plist.num; i++)
        printf("%d ", plist.nodes[i]); // In ra tung phan tu trong danh sach
    printf("\n");
}

int main() {
    LIST myList;
    Init(myList);          // Khoi tao danh sach
    InputList(myList);     // Nhap du lieu cho danh sach
    ShowList(myList);      // In ra danh sach
    int x, pos;
    if (Retrieve(myList, 1, x)) { // Truy xuat gia tri tai vi tri 1
        printf("Gia tri tai vi tri 1: %d\n", x);
    }
    if (Insert(myList, 2, 99)) { // Chen gia tri 99 vao vi tri 2
        printf("Da chen 99 vao vi tri 2.\n");
    }
    ShowList(myList); // In lai danh sach sau khi chen
    if (Remove(myList, 3, x)) { // Xoa gia tri tai vi tri 3
        printf("Da xoa phan tu tai vi tri 3: %d\n", x);
    }
    ShowList(myList); // In lai danh sach sau khi xoa
    pos = Search(myList, 99);
    if (pos != -1) { // Tim gia tri 99 trong danh sach
        printf("Tim thay 99 tai vi tri %d\n", pos);
    } else {
        printf("Khong tim thay 99 trong danh sach.\n");
    }
    return 0;
}

