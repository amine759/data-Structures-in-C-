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
Node* delete_Node(Node* root, int value);

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
    printf("%d\n", root->data);
    printInorder_rec(root->right);
}


Node* iter_Search(int n, Node* root){
    while (root != root)
    {
        if(root->data == n) return root ;
        else if(n<root->data) root = root->left;
        else root = root->right;
    } 
    return NULL ;
}

Node* rec_Search(int n, Node* root){

    if(root->data == n) return root ;

    else if(n<root->data){
        if (root->left != NULL) return rec_Search(n,root->left);
        else printf("value not found") ;

    } else {
        if (root->right!=NULL) return rec_Search(n,root->right);   
        else printf("value not found") ;
    }

    return root;
}

Node* minValue(Node* root){
    Node* current = root ; 
    while(current && current->left != NULL) current = current->left;
    return current ; 
}

Node* delete_Node(Node* root, int value){

    if (root == NULL) return root;

    if (value < root->data) root->left = delete_Node(root->left, value);

    else if (value > root->data) root->right = delete_Node(root->right, value);

    else{
        if (root->left==NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL)
        {
            Node* temp = root->left;
            free(root);  
            return temp;
       }
    Node* temp = minValue(root->right);
    root->data = temp->data;
  
    root->right = delete_Node(root->right, temp->data); 
    }
    return root ;
}
    


int main(int argc, char const *argv[])
{
    Node* root = createNode(111);
    root = insert_Rec(root,15);
    root = insert_Rec(root,10);
    root = insert_Rec(root,25);
    root = insert_Rec(root,7);
    root = insert_Rec(root,23);

    printInorder_rec(root);
    
    printf("\n**** recursive search *****\n");
    Node* rec_search = rec_Search(12,root);
    printf("\n%d found\n",rec_search->data);
    printf("\n**** iterative search *****\n");
    Node* iter_search = rec_Search(111,root);
    printf("\n%d found\n",iter_search->data); 

    printf("\n*** deletion ***\n");
    root = delete_Node(root, 10);
    printInorder_rec(root);
    printf("\n");
    root = delete_Node(root, 23);
    printInorder_rec(root);
    free(root);
    return 0;
}