// Array implementation of list

#include <stdio.h>

typedef struct
{
 int items[20];
 int count;
} list; 

// prototypes of functions
void create(list *); 
void traverse(list *);
void insert(list *, int, int);
void delete(list *, int);

void main() {
    list myList;
    create(&myList);

    int pos, newItem;
    printf("Enter positon of new element: ");
    scanf("%d", &pos);
    printf("Enter new element: ");
    scanf("%d", &newItem);

    insert(&myList, pos, newItem);

    printf("Enter positon of element to delete: ");
    scanf("%d", &pos);

    delete(&myList, pos);

    traverse(&myList);
}

void create(list *myList) {
    int i = 0;
    while(1) {
        fflush(stdin);
        int n;
        printf("Enter integer (-1111 to stop): ");
        scanf("%d", &n);
        if (n == -1111) 
            break;
        myList ->items[i] = n;
        i++;
    }
    myList ->count = i;
}

void traverse(list *myList) {
    for(int i = 0; i < myList -> count; i++) {
        printf("Item %d: %d\n", i, myList -> items[i]);
    }
}

void insert(list *myList, int position, int element) {
    int currentPos = myList -> count;

    while (currentPos >= position) {
        myList -> items[currentPos + 1] = myList -> items[currentPos];
        currentPos--;
    }

    myList -> items[position] = element;
    myList -> count++;
}

void delete(list *myList, int position) {
    int temp = position;
    printf("Element which will be deleted: %d\n", myList -> items[position]);

    while(temp <= myList -> count -1) {
        myList -> items[temp] = myList -> items[temp+1];
        temp++;
    }
    myList -> count --;

}


