#include <stdio.h>
#define QUEUE_LENGTH 50

struct queue
{ 
    int elements[QUEUE_LENGTH];
    int front, rear;
};


void add(struct queue *q, int value) {
    q->rear++;
    if (q->rear < QUEUE_LENGTH) 
        q->elements[q->rear] = value;
    else 
        printf("Overflow");
}

int delete(struct queue * q) {
    int data;
    q->front++;
    if (q->front > q->rear)
        printf("Queue is empty");
    else 
        data = q->front;
    return data;
}

main() {
    struct queue q;
    q.front = q.rear = -1;

    for (int i = q.front+1; i <= q.rear; i++) {
        printf("%d\n", q.elements[i]);
    }
    delete(&q);
    for (int i = q.front+1; i <= q.rear; i++) {
        printf("\n%d\n", q.elements[i]);
    }

}