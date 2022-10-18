#include <stdio.h>
#include <stdlib.h>

struct stack
{ 
    int elements[100];
    int top;
} frontstack, rearstack;


void push(struct stack* stack, int value) {
    if (stack->top < 100) {
        stack->top++;
        stack->elements[stack->top] = value;
    } else {
        printf("Overflow");
    }
} 

int pop(struct stack* stack) {
    int value;
    if (stack->top > -1) {
        value = stack->elements[stack->top];
        stack->top--;
    } else {
        printf("Underflow");
    }
    return value;
}

void enqueue(int value) {
    push(&rearstack, value);
}

int dequeue() {
    int value;
    if (frontstack.top == -1 && rearstack.top == -1) {
        printf("Queue is empty.");
    } else if (frontstack.top == -1) {
        value = pop(&rearstack);
        push(&frontstack, value);
    } 
    value = pop(&frontstack);
    return value;
}

void display() {
    if (frontstack.top == -1 && rearstack.top == -1) {
        printf("Queue is empty.");
        return
    }
    int top1 = frontstack.top;
    int top2 = rearstack.top;
    for(int i = 0; i <= top1; i++) {
        printf("%d\n", frontstack.elements[i]);
    }
    for(int i = 0; i <= top2; i++) {
        printf("%d\n", rearstack.elements[i]);
    }
}

int main() {
    frontstack.top = -1;
    rearstack.top = -1;

    int f = 0, a;
    char ch = 'y';
    while (ch == 'y'||ch == 'Y') {
        printf("enter your choice\n1.add to queue\n2.remove from queue\n3.display\n4.exit\n");
        scanf("%d", &f);
        switch(f) {
            case 1 : printf("enter the element to be added to queue\n");
                     scanf("%d", &a);
                     enqueue(a);
                     break;
            case 2 : dequeue();
                     break;
            case 3 : display();
                     break;
            case 4 : exit(1);
                     break;
            default : printf("invalid\n");
                      break;
        }
    }
}