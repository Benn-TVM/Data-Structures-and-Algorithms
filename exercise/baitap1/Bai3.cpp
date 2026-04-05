#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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
    Stack* stack = createStack(MAX);
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

int main() {
    int num;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &num);
    
    printf("Dang nhi phan: ");
    decToBase(num, 2);
    
    printf("Dang bat phan: ");
    decToBase(num, 8);
    
    printf("Dang thap luc phan: ");
    decToBase(num, 16);
    
    return 0;
}

