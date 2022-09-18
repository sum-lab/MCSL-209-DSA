#include <stdio.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;

} node;

// Create a new Node
struct node* createNode(int value) {
  node* newNode = (node *)malloc(sizeof(node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void insertNode(node *curr, node *new) {
    if (new->data <= curr->data) {
        // insert left
        if (curr->left != NULL) 
            insertNode(curr->left, new);
        else
            curr -> left = new;
    } else{
        // insert right
        if (curr->right != NULL) 
            insertNode(curr->right, new);
        else
            curr ->right = new;
    }
}

void traverse_inorder(node *curr) {
    if (curr->left != NULL)
        traverse_inorder(curr->left);
    printf("%d\n", curr->data);
    if (curr->right != NULL)
        traverse_inorder(curr->right);
}

void traverse_preorder(node *curr) {
    printf("%d\n", curr->data);
    if (curr->left != NULL)
        traverse_preorder(curr->left);
    if (curr->right != NULL)
        traverse_preorder(curr->right);
}

void traverse_postorder(node *curr) {
    if (curr->left != NULL)
        traverse_postorder(curr->left);
    if (curr->right != NULL)
        traverse_postorder(curr->right);
    printf("%d\n", curr->data);
}

void main() {
    node *root = createNode(4);
    insertNode(root, createNode(2));
    insertNode(root, createNode(1));
    insertNode(root, createNode(3));
    insertNode(root, createNode(5));

    printf("INORDER:\n");
    traverse_inorder(root);
    printf("PREORDER\n");
    traverse_preorder(root);
    printf("POSTORDER:\n");
    traverse_postorder(root);

}