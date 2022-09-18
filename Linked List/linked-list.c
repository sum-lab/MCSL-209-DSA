// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num; // Data for the node.
    struct Node *nextPtr; // Stores address of the next note.
}*stNode;

// Function to create the list
void createNodeList( int n );
void displayList();

int main() {
    
    int n;
    printf("\n\n Linked List : To create and display Singly Linked List :\n");
    
    printf( "Enter the no of nodes: " );
    scanf( "%d", &n );
    
    createNodeList( n );
    
    printf("\n Data entered in the list : \n");
    displayList();

    return 0;
}

// Function to create the list
void createNodeList( int n ) {
    struct Node *fnNode, *temp;
    int num, i;
    
    stNode = ( struct Node * )malloc( sizeof( struct Node ) );
    
    // If stNode is NULL we cannot no memory allocation.
    if(stNode == NULL) {
        printf(" Memory can not be allocated.");
    } else {
        // Take the data for the node.
        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        
        stNode->num = num;      
        stNode->nextPtr = NULL; // links the address field to NULL
        temp = stNode;
        
        // Creating n nodes and adding to linked list
        for( i=2; i<=n; i++) {
            fnNode = (struct Node *)malloc(sizeof(struct Node));
            if(fnNode == NULL) {
                printf(" Memory can not be allocated.");
                break;
            }
            
            printf(" Input data for node %d : ", i);
            scanf(" %d", &num);
            
            // links the num field of fnNode with num
            fnNode->num = num;
            // links the address field of fnNode with NULL
            fnNode->nextPtr = NULL;
            
            temp->nextPtr = fnNode; // links previous node i.e. tmp to the fnNode
            temp = temp->nextPtr; 
        }
    }
}

void displayList() {
    struct Node *temp;
    if (stNode == NULL) {
        printf(" List is empty.");
    } else {
        temp = stNode;
        while (temp != NULL) {
            printf( "Data = %d\n", temp->num );
            temp = temp->nextPtr;
        }
        
    }
    
}