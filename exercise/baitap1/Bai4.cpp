#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc ngan xep
typedef struct {
    int top;
    unsigned capacity;
    int* array;
} Stack;

// Ham tao ngan xep voi dung luong da cho
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Ham kiem tra ngan xep rong
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Ham them phan tu vao ngan xep
void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Ham lay phan tu ra khoi ngan xep
int pop(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

// Ham chuyen doi tu thap phan sang he bat ky
void decToBase(int num, int base) {
    Stack* stack = createStack(100);
    char digits[] = "0123456789ABCDEF";
    while (num > 0) {
        push(stack, num % base);
        num /= base;
    }
    while (!isEmpty(stack)) {
        printf("%c", digits[pop(stack)]);
    }
    printf("\n");
}

// Ham tinh tong bang de quy
int tinhTongDeQuy(int n) {
    if (n == 1)
        return 1;
    return n + tinhTongDeQuy(n - 1);
}

// Ham tinh tong bang phuong phap khu de quy su dung ngan xep
int tinhTongKhuduDeQuy(int n) {
    Stack* stack = createStack(100);
    int tong = 0;

    // Dua cac gia tri vao ngan xep
    while (n > 0) {
        push(stack, n);
        n--;
    }

    // Lay cac gia tri tu ngan xep ra va tinh tong
    while (!isEmpty(stack)) {
        tong += pop(stack);
    }

    return tong;
}

int main() {
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);

    int tongDeQuy = tinhTongDeQuy(n);
    printf("Tong S = 1 + 2 + 3 + ... + %d = %d (De Quy)\n", n, tongDeQuy);

    int tongKhuduDeQuy = tinhTongKhuduDeQuy(n);
    printf("Tong S = 1 + 2 + 3 + ... + %d = %d (Khu De Quy)\n", n, tongKhuduDeQuy);

    return 0;
}

