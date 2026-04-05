#include <stdio.h>
#include <stdlib.h>

// Cau truc ngan xep (stack)
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Ham tao ngan xep co dung luong xac dinh
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Ham kiem tra ngan xep co rong khong
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Ham them phan tu vao ngan xep
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Ham lay phan tu ra khoi ngan xep
int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Ham di chuyen dia giua hai coc
void moveDisk(int from, int to, int disk) {
    printf("Chuyen dia %d tu cot %d sang cot %d\n", disk, from, to);
}

// Ham di chuyen dia giua hai ngan xep
void moveDisksBetweenTwoPoles(struct Stack* src, struct Stack* dest, int s, int d) {
    int pole1TopDisk = isEmpty(src) ? -1 : pop(src);
    int pole2TopDisk = isEmpty(dest) ? -1 : pop(dest);

    // Dieu kien de xac dinh cach di chuyen dia
    if (pole1TopDisk == -1) {
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    } else if (pole2TopDisk == -1) {
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    } else if (pole1TopDisk > pole2TopDisk) {
        push(src, pole1TopDisk);
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    } else {
        push(dest, pole2TopDisk);
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
}

// Ham giai quyet bai toan Thap Ha Noi
void towerOfHanoi(int num_of_disks, struct Stack* src, struct Stack* aux, struct Stack* dest) {
    int total_num_of_moves;
    int s = 1, d = 3, a = 2;

    if (num_of_disks % 2 == 0) {
        int temp = d;
        d = a;
        a = temp;
    }
    total_num_of_moves = (1 << num_of_disks) - 1;

    for (int i = num_of_disks; i >= 1; i--)
        push(src, i);

    for (int i = 1; i <= total_num_of_moves; i++) {
        if (i % 3 == 1)
            moveDisksBetweenTwoPoles(src, dest, s, d);
        else if (i % 3 == 2)
            moveDisksBetweenTwoPoles(src, aux, s, a);
        else if (i % 3 == 0)
            moveDisksBetweenTwoPoles(aux, dest, a, d);
    }
}

// Ham chinh
int main() {
    unsigned num_of_disks;

    //printf("Nhap so luong dia: ");
    scanf("%u", &num_of_disks);

    struct Stack* src = createStack(num_of_disks);
    struct Stack* aux = createStack(num_of_disks);
    struct Stack* dest = createStack(num_of_disks);

    towerOfHanoi(num_of_disks, src, aux, dest);

    return 0;
}

