#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *front, *rear;

void add(int item);
int delete() ;
void display();
void reverse();

void main() {
    int item, choice;

    front = NULL;

    while(1) {
        printf("Choose option\n 1. Add\n 2. Delete\n 3. Display\n 4. Reverse\n Press other key to exit \n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter new item: ");
                scanf("%d", &item);
                add(item);
                break;
            case 2:
                item = delete();
                printf("\n%d", item);
                break;
            case 3:
                display();
                break;
            case 4:
                reverse();
                break;
            default:
                goto end;
                break;

        }   
    }
    end:
    return;
}

void add(int value) {
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;
    if(front == NULL) {
        front = rear = temp;

    } else {
        rear -> next = temp;
        rear = temp;
    }
}

int delete() {
    if (front == NULL) {
        printf("\nQueue is empty.");
        return;
    }
    int data = front -> data;
    front = front -> next;

    if (front == NULL)
        front = rear = NULL;

    return data;
}

void display() {
    node *temp = front;
    while(1) {
        if (temp == NULL) {
            printf("\n End of queue \n");
            break;
        }
        printf("\n %d", temp ->data);
        temp = temp->next;
    }
}

void reverse() {
    if (front == NULL) {
        return;
    }
    int element = delete();
    reverse();
    add(element);
}
