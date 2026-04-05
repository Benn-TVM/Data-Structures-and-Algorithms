#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    if ((q->front == 0 && q->rear == MAX - 1) || (q->front == q->rear + 1)) {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Hang doi day.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
        printf("Da them phan tu %d vao hang doi.\n", value);
    }
}

int dequeue(Queue *q) {
    int value;
    if (isEmpty(q)) {
        printf("Hang doi rong.\n");
        return -1;
    } else {
        value = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        printf("Da lay phan tu %d ra khoi hang doi.\n", value);
        return value;
    }
}

void display(Queue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Hang doi rong.\n");
    } else {
        printf("Cac phan tu trong hang doi: ");
        for (i = q->front; i != q->rear; i = (i + 1) % MAX) {
            printf("%d ", q->items[i]);
        }
        printf("%d\n", q->items[i]);
    }
}

int main() {
    Queue q;
    int choice, value;

    initQueue(&q);

    do {
        printf("\nMenu:\n");
        printf("1. Them phan tu vao hang doi\n");
        printf("2. Lay phan tu ra khoi hang doi\n");
        printf("3. Hien thi hang doi\n");
        printf("4. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap phan tu can them: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 4);

    return 0;
}

