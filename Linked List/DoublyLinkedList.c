# include <stdio.h>
# include <malloc.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node; 

void create(node* );
void traverseForward(node *);
void traverseBackward(node *);

int main() {
    node *head;
    head = (node *) malloc(sizeof(node));
    head -> prev = NULL;
    create(head);
    printf("\n Created doubly linked list is as follows");
    traverseForward(head); 
    printf("\n");
    traverseBackward(head);
}

void create(node *head) {
    printf("Input element(-1111 to stop): \n");
    scanf("%d", &head->data);
    if(head->data != -1111) {
        head->next = (node *)malloc(sizeof(node));
        head->next->prev = head;
        head->next->next = NULL;
        create(head->next);
    } else {
        head->next = NULL;
    }
}

void traverseForward(node *head) {
    do {
         printf(" %d <=> ", head->data);
        head = head->next;
    } while (head->next); 
}

void traverseBackward(node *head) {
    while(head->next) {
        head = head->next;
    }
    head = head->prev;
    do {
         printf(" %d <=> ", head->data);
        head = head->prev;
    } while (head->prev);
    printf(" %d <=> ", head->data); 
}