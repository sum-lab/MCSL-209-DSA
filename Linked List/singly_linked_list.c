#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head;

void createList();
void displayList();
void deleteElement(int data);
void insertElement(int data, int pos);
void sortList();

int main()
{
    int data, pos;

    createList(head);

    displayList(head);

    sortList();
    displayList();

    /*printf("\nElem to delete: ");
    scanf("%d", &data);

    deleteElement(data);
    displayList();

    printf("\nElem to insert: ");
    scanf("%d", &data);
    printf("\nPosition of new Element: ");
    scanf("%d", &pos);
    insertElement(data, pos);
    displayList();*/

    return 0;
}

void createList()
{
    node *temp, *newNode;

    head = (node *)malloc(sizeof(node));
    int data, n;
    printf("\nEnter no. of elements: ");
    scanf("%d", &n);
    printf("\nEnter element 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    temp = head;

    for (int i = 2; i <= n; i++)
    {
        printf("\nEnter element %d: ", i);
        scanf("%d", &data);
        newNode = (node *)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
}

void displayList()
{
    node *temp;
    if (head == NULL)
    {
        printf("\nList is Empty.");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("\nData: %d", temp->data);
            temp = temp->next;
        }
    }
}

void deleteElement(int data)
{
    node *prev, *temp;
    prev = temp = head;

    // for deleting first node
    if (data == head->data)
    {
        head = head->next;
        free(temp);
        return;
    }

    // for deleting middle or last element
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
        if (data == temp->data)
        {
            prev->next = temp->next;
            free(temp);
            return;
        }
    }

    printf("\nElement not found");
}

void insertElement(int data, int pos)
{
    node *temp = head;
    node *newNode = (node *)malloc(sizeof(node));
    // insert in beginning
    if (pos == 0)
    {
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        return;
    }

    // insert in middle or end
    for (int i = 1; i < pos; i++)
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
        }
        else
        {
            printf("\nUnable to insert at given position.");
            return;
        }
    }

    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

void sortList() {
    node *current = head;
    node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        while (next != NULL) {
            if (current->data > next->data) {
                //swap;
                int temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        current = current->next;
    }
    
}
