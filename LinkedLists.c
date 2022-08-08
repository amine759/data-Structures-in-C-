#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) ;
void insert_atHead(Node **head, int data);
void insert_atTail(Node *head, int data);
Node* init() ; 

Node* init(){
    Node *head = (Node*)malloc(sizeof(struct Node)) ;
    head->data = 111 ;
    head->next = NULL ;
    return head ;
}

Node* createNode(int data){
    Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next= NULL ;
    return node;
}

void insert_atHead(Node **head, int data){
    Node *new_node = createNode(data);
    if (new_node ==NULL){
        printf("\n*** no enough memory ***\n");
    }
    new_node->next = *head;
    *head = new_node ;
}

void insert_atTail(Node *head, int data){
    Node *new_node = createNode(data);
    if (new_node ==NULL){
        printf("\n*** no enough memory ***\n");
    }
    while(head->next != NULL){
        head = head->next;   
    }
    head->next = new_node ;
    new_node->next = NULL ;
}

void printLinkedlist(Node *head){
    Node *current_Node ; 
    current_Node = head;
    while (current_Node !=NULL)
    {
        printf("%d -> ",current_Node->data);
        current_Node = current_Node->next ;
    }
    printf("\n");
    }

void insert_given_Position(Node *head, int index){
    
}
    

int main(int argc, char const *argv[])
{
    Node *head = init();
    insert_atHead(&head, 777);
    insert_atHead(&head, 66);
    insert_atHead(&head, 5);
    insert_atTail(head,8888);
    insert_atTail(head,99999);
    
    printLinkedlist(head);
    return 0;
}

