#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc cua mot node
struct Node {
    int data;
    struct Node* next;
};

// Dinh nghia cau truc cua hang doi
struct Queue {
    struct Node *front, *rear;
};

// Ham tao mot node moi
struct Node* newNode(int k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

// Ham tao mot hang doi rong
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Ham them mot phan tu vao hang doi
void enqueue(struct Queue* q, int k) {
    struct Node* temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Ham xoa mot phan tu khoi hang doi
void dequeue(struct Queue* q) {
    if (q->front == NULL)
        return;
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}

int main() {
    struct Queue* q = createQueue();
    int lua_chon, gia_tri;

    while (1) {
        printf("\n1. Them (Enqueue)\n");
        printf("2. Xoa (Dequeue)\n");
        printf("3. Hien thi Dau va Cuoi (Display Front and Rear)\n");
        printf("4. Thoat (Exit)\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &lua_chon );

        switch (lua_chon ) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &gia_tri );
                enqueue(q, gia_tri );
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                if (q->front != NULL)
                    printf("Phan tu dau hang doi (Queue Front): %d\n", q->front->data);
                else
                    printf("Hang doi rong (Queue is empty).\n");
                if (q->rear != NULL)
                    printf("Phan tu cuoi hang doi (Queue Rear): %d\n", q->rear->data);
                else
                    printf("Hang doi rong (Queue is empty).\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Lua chon khong hop le (Invalid choice)! Vui long thu lai (Please try again).\n");
        }
    }

    return 0;
}

