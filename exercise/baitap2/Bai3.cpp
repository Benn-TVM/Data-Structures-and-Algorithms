#include <stdio.h>
#include <stdlib.h>

// Cau truc nut
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Cau truc danh sach lien ket
typedef struct {
    Node* head;
} List;

// Khoi tao danh sach
void khoiTaoDanhSach(List* list) {
    list->head = NULL;
}

// Them chu so vao danh sach
void themChuSo(List* list, int digit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = digit;
    newNode->next = list->head;
    list->head = newNode;
}

// Hien thi so lon
void hienThiSoLon(List list) {
    Node* current = list.head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

// Thuc hien phep cong hai so lon
List congSoLon(List num1, List num2) {
    List result;
    khoiTaoDanhSach(&result);
    Node *n1 = num1.head, *n2 = num2.head;
    int carry = 0;

    while (n1 != NULL || n2 != NULL || carry > 0) {
        int sum = carry;
        if (n1 != NULL) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != NULL) {
            sum += n2->data;
            n2 = n2->next;
        }
        themChuSo(&result, sum % 10);
        carry = sum / 10;
    }
    return result;
}

// Thuc hien phep tru hai so lon (gia su num1 >= num2)
List truSoLon(List num1, List num2) {
    List result;
    khoiTaoDanhSach(&result);
    Node *n1 = num1.head, *n2 = num2.head;
    int borrow = 0;

    while (n1 != NULL) {
        int diff = n1->data - borrow;
        if (n2 != NULL) {
            diff -= n2->data;
            n2 = n2->next;
        }
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        themChuSo(&result, diff);
        n1 = n1->next;
    }
    return result;
}

int main() {
    List num1, num2, result;
    khoiTaoDanhSach(&num1);
    khoiTaoDanhSach(&num2);

    // Them cac chu so vao so lon
    themChuSo(&num1, 5);
    themChuSo(&num1, 4);
    themChuSo(&num1, 3);

    themChuSo(&num2, 2);
    themChuSo(&num2, 1);

    printf("So lon thu nhat: ");
    hienThiSoLon(num1);

    printf("So lon thu hai: ");
    hienThiSoLon(num2);

    result = congSoLon(num1, num2);
    printf("Ket qua phep cong: ");
    hienThiSoLon(result);

    result = truSoLon(num1, num2);
    printf("Ket qua phep tru: ");
    hienThiSoLon(result);

    return 0;
}
