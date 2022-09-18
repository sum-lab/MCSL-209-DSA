/* Representation of Polynomial using Linked List */
# include <stdio.h>
# include <malloc.h>

struct term
{
    char sign;
    int coef;
    int expo;
    struct term *next;
};

typedef struct term term;
void append(term *);
void create_poly(term *);
int count_poly(term *);
void display(term *); 

void main(){ 
    term *head = (term *) malloc(sizeof(term));
    create_poly(head);
    printf("\n Total nodes = %d \n", count_poly(head));
    append(head);
    display(head); 
} 

void create_poly(term *start) {
    char ch;
    static int i;
    printf("\n Enter n to stop");
    ch = getchar();
    if(ch != 'n') {
        printf("\n Term %d: Input the sign: ", i+1);
        scanf("%c", &start->sign);
        printf("\n Term %d: Input the coefficient value:  ", i+1);
        scanf("%d", &start->coef);
        printf("\n Term %d:Input the exponent value: ", i+1);
        scanf("%d", &start->expo);
        fflush(stdin);
        i++;
        start->next = (term *) malloc(sizeof(term));
        create_poly(start->next);
    } else
        start->next=NULL;
}

void display(term * start) {
    if (start -> next != NULL) {
        printf("%c", start -> sign);
        printf("%d", start->coef);
        printf("X^%d", start->expo);
        display(start->next);
    }
}

int count_poly(term *start) {
    if(start->next == NULL)
        return 0;
    else
        return(1+count_poly(start->next));
} 

void append(term *start) {
    term *temp = start;
    int i = 0;
    while(temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    
    printf("\n Term %d: Input the sign: ", i+1);
    scanf(" %c", &temp->sign);
    printf("\n Term %d: Input the coefficient value:  ", i+1);
    scanf("%d", &temp->coef);
    printf("\n Term %d:Input the exponent value: ", i+1);
    scanf("%d", &temp->expo);
    fflush(stdin);
    temp->next = (term *) malloc(sizeof(term));
    temp->next->next = NULL;
}
