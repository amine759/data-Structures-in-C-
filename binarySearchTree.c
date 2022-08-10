#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data ;
    struct Node* left ; 
    struct Node* right ;
} Node ;

Node* createNode(int data);
void printInorder_rec(struct Node* root); 
Node* insert_Rec(Node* root,int data);

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

Node* insert_Rec(Node* root,int data){
    if(root == NULL){
        root = createNode(data);
        root->left = root->right = NULL ; 
        return root ;
    } 
    if(data == root->data){
        printf("value already exist in root");
    }

    else if(data < root->data) root->left = insert_Rec(root->left, data);

    else if(data > root->data) root->right = insert_Rec(root->right, data);
    
    return root;
}

void printInorder_rec(struct Node* root)
{
    if(root == NULL) return;

    printInorder_rec(root->left);
    printf("\n%d\n", root->data);
    printInorder_rec(root->right);
}

int main(int argc, char const *argv[])
{
    Node* root = createNode(111);
    root = insert_Rec(root, 15);
    root = insert_Rec(root, 10);
    root = insert_Rec(root, 25);
    root = insert_Rec(root, 7);
    printInorder_rec(root);

    free(root);    
    return 0;
}







