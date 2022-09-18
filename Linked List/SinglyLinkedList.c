#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void create(node *newNode);
void traverse(node *head);
node * find (node *head, int data);
node * insert_list(node *head);
node *delete_list(node *head);

int main()
{
    node *head = (node *) malloc(sizeof(node));
    create(head);
    traverse(head);
    head = insert_list(head);
    traverse(head);
    head = delete_list(head);
    traverse(head);
    print_loc(head);

    printf("\nCount: %d", count(head));
} 

void create(node *newNode) {
    printf("Enter list element (-1111 to stop):\n");
    scanf("%d", &newNode->data); 
    if (newNode->data == -1111) {
        newNode->next = NULL;
    } else {
        newNode -> next = (node *)malloc(sizeof(node));
        create(newNode -> next);
    }
}

void traverse(node *head) {
    if(head->next!=NULL) {
        printf("%d --> ", head->data);
        traverse(head->next);
    } 
}

void print_loc(node * head) {
    if(head->next!=NULL) {
        printf("%d --> ", head->next);
        print_loc(head->next);
    } 
}

int count(node *head) {
    if(head->next == NULL) {
        return 0;
    } else {
        return (1 + count(head->next));
    }
}

node * find (node *head, int data) {
    if (head->next->data == data) {
        return head;
    }
    if (head -> next->next == NULL) {
        return NULL;
    } else
        find(head->next, data);
}

node * insert_list(node *head) {
    node *n, *f;
    int key, element;
    printf("\nenter value of new element: ");
    scanf("%d", &element);
    printf("\nenter value of key element: ");
    scanf("%d",&key); 
    if(head->data == key) {
        n=(node*)malloc(sizeof(node));
        n->data = element;
        n->next = head;
        head=n;
    } else {
        f = find(head, key);
        if (f == NULL) {
            printf("\nKey is not found\n");
        } else{
            n=(node*)malloc(sizeof(node));
            n->data=element;
            n->next=f->next;
            f->next=n; 
        }
    }
    return head;
}

node *delete_list(node *head) {
    int key; node * f, * temp;
    printf("\n enter the value of element to be deleted \n");
    scanf("%d", &key);
    if(head->data == key) {
        temp = head->next;
        free(head);
        head=temp;
    } else {
        f = find(head,key);
        if(f==NULL)
            printf("\n key not found\n");
        else {
            temp = f->next->next;
            free(f->next);
            f->next=temp;
        }
    }
    return(head);
}

