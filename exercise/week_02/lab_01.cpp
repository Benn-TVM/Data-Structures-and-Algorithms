#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc cho mot nut trong danh sach lien ket don
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Ham tao nut moi
Node* taoNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Ham them nut vao cuoi danh sach lien ket
void themCuoi(Node** head, int data) {
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Ham tinh trung binh cong gia tri cua cac nut trong danh sach lien ket
float tinhTrungBinhCong(Node* head) {
    int sum = 0, count = 0;
    Node* temp = head;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    return (count == 0) ? 0 : (float)sum / count;
}

// Ham dem so luong nut co gia tri chan
int demNutChan(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

// Ham tim nut co gia tri lon nhat
Node* timNutLonNhat(Node* head) {
    if (head == NULL) return NULL;
    Node* maxNode = head;
    Node* temp = head->next;
    while (temp != NULL) {
        if (temp->data > maxNode->data) {
            maxNode = temp;
        }
        temp = temp->next;
    }
    return maxNode;
}

// Ham tach danh sach thanh hai danh sach chan va le
void tachDanhSach(Node* head, Node** list_chan, Node** list_le) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            themCuoi(list_chan, temp->data);
        } else {
            themCuoi(list_le, temp->data);
        }
        temp = temp->next;
    }
}

// Ham ghep hai danh sach tang dan
Node* ghepDanhSach(Node* list1, Node* list2) {
    Node* result = NULL;
    Node** lastPtrRef = &result;

    while (1) {
        if (list1 == NULL) {
            *lastPtrRef = list2;
            break;
        } else if (list2 == NULL) {
            *lastPtrRef = list1;
            break;
        }
        if (list1->data <= list2->data) {
            themCuoi(lastPtrRef, list1->data);
            list1 = list1->next;
        } else {
            themCuoi(lastPtrRef, list2->data);
            list2 = list2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    return result;
}

int main() {
    Node* list = NULL;
    Node* list_chan = NULL;
    Node* list_le = NULL;
    Node* list1 = NULL;
    Node* list2 = NULL;
    int n, value;

    // Nhap danh sach ban dau
    printf("Nhap so luong phan tu danh sach ban dau: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        themCuoi(&list, value);
    }

    // Xuat danh sach ban dau
    printf("Danh sach ban dau: ");
    xuatDanhSach(list);

    // Tinh trung binh cong gia tri cua cac nut trong danh sach
    printf("Trung binh cong gia tri cua cac nut: %.2f\n", tinhTrungBinhCong(list));

    // Dem so luong nut co gia tri chan
    printf("So luong nut co gia tri chan: %d\n", demNutChan(list));

    // Tim nut co gia tri lon nhat
    Node* maxNode = timNutLonNhat(list);
    if (maxNode != NULL) {
        printf("Gia tri lon nhat trong danh sach: %d\n", maxNode->data);
    }

    // Tach danh sach thanh hai danh sach chan va le
    tachDanhSach(list, &list_chan, &list_le);
    printf("Danh sach chan: ");
    xuatDanhSach(list_chan);
    printf("Danh sach le: ");
    xuatDanhSach(list_le);

    // Nhap danh sach 1
    printf("Nhap so luong phan tu danh sach list1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        themCuoi(&list1, value);
    }

    // Nhap danh sach 2
    printf("Nhap so luong phan tu danh sach list2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        themCuoi(&list2, value);
    }

    // Ghep hai danh sach tang dan
    Node* list_merged = ghepDanhSach(list1, list2);
    printf("Danh sach sau khi ghep: ");
    xuatDanhSach(list_merged);

    return 0;
}

