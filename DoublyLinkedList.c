#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node; 

void delete_head(Node **head);
Node* createNode(int data) ;
int get_Length(Node *head);


Node* createNode(int data){
    Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next= NULL ;
    node->prev = NULL ;
    return node;
}

int get_Length(Node *head){ 
    int count=0 ; 
    while( head != NULL ){
        head = head->next ; 
        count++ ; 
    }
    return count;
}


void insert_atHead(Node **head, int data){
    Node *new_node = createNode(data);
    if (new_node ==NULL){
        printf("\n*** no enough memory ***\n");
    }
    (*head)->prev = new_node; 
    new_node->next = *head;
    *head = new_node ;
    
}

void insert_atTail(Node *node, int data){
    Node *new_node = createNode(data);
    if (new_node ==NULL){
        printf("\n*** no enough memory ***\n");
    }
    while(node->next != NULL){
        node = node->next;   
    }
    node->next = new_node ;
    new_node->prev = node;
    new_node->next = NULL ;
    }

void insert_given_Value(Node *node, int value, int data){
    Node *new_node = createNode(data);
    while (node != NULL)
    {
        if (node->data == value){
            node->prev->next = new_node ; 
            new_node->prev = node->prev ; 
            new_node->next = node ; 
            node->prev = new_node ;
            break; 
        }
        node = node->next ; 
    }
}

void insert_given_Index(Node *node, int index, int data){
    Node *new_node = createNode(data);
    int i = 0 ;
    int len = get_Length(node);
    if (index > len){
        printf("chosen index out of range ");
        return ;
    }
    while (node != NULL)
    {
        i++;
        if (i == index){
            node->prev->next = new_node ; 
            new_node->prev = node->prev ; 
            new_node->next = node ; 
            node->prev = new_node ;
            break; 
        }
        node = node->next ;
    }
}
void printLinkedlist(Node *head){
    Node *current_Node ; 
    current_Node = head;
    while (current_Node !=NULL)
    {
        printf("%d <-> ",current_Node->data);
        current_Node = current_Node->next ;
    }
    printf("\n");
    }

void delete_head(Node **head){
    if ((*head)->next != NULL && (*head)->prev == NULL){
        (*head)->next->prev = NULL;
        *head = (*head)->next;
    } else {
        printf("linked list is empty");
    }
}

void delete_given_index(Node *node,int index){
    int i = 0 ;
    int len = get_Length(node);

    if (index > len){
        printf("chosen index out of range ");
        return ;
    }
    while (node != NULL){
        i++ ;
        if(i == index){
            node->prev->next = node->next ; 
            node->next->prev = node->prev ; 
            node->next = NULL ; 
            node->prev = NULL ;
        }
        node = node->next;
    }   
}  

void delete_given_Value(Node *node, int value){
    
    if(node->data == value){
        delete_head(&node);
        return ;
    }
    while (node->next != NULL){
        if(node->data == value ){
            node->prev->next = node->next ; 
            node->next->prev = node->prev ; 
            node->next = NULL ; 
            node->prev = NULL ;

            break;
        }
        node = node->next;
    }
}


int main(int argc, char const *argv[])
{
    Node *head = createNode(111);
    // insert node at head 
    insert_atHead(&head, 2);
    insert_atHead(&head, 5);
    insert_atTail(head,69);
    insert_atTail(head,96);

    insert_given_Value(head,111,56);
    insert_given_Value(head,56,7);
    insert_given_Index(head,3,4);
    insert_given_Index(head,4,17);
    
    printLinkedlist(head);
    
    delete_given_Value(head,2);
    delete_given_index(head,5); 
    delete_head(&head);

    printLinkedlist(head);
    free(head);
    return 0;

}