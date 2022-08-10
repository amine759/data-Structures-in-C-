#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) ;
int get_Length(Node *head);

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

void insert_atTail(Node *node, int data){
    Node *new_node = createNode(data);
    if (new_node ==NULL){
        printf("\n*** no enough memory ***\n");
    }
    while(node->next != NULL){
        node = node->next;   
    }
    node->next = new_node ;
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

void insert_given_Index(Node *node, int index, int data){
    int i = 0 ;
    Node *new_node = createNode(data);
    int len = get_Length(node);
    if (index > len){
        printf("chosen index out of range ");
        return ;
    } 
    while (node != NULL){
        i++ ;
        if(i == index){
            new_node->next = node->next ; 
            node->next = new_node ;
            break;
        }
        node = node->next ; 
    }
}

void insert_given_Value(Node *node, int value, int data){
    Node *new_node = createNode(data);
    while (node != NULL){
        if(node->data == value){
            new_node->next = node->next ; 
            node->next = new_node ;
            break;
        }
        node = node->next ; 
    }
}

void delete_given_Value(Node *node, int value){

    while (node->next != NULL){
        if(node->next->data == value ){
            Node *temp ;     
            temp = node->next ; 
            node->next = node->next->next ;
            free(temp);
            break;
        }
        node = node->next;
    }

}
void delete_head(Node **head){
    Node *temp ;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_given_index(Node *node,int index){
    int i = 1 ;
    int len = get_Length(node);

    if (index > len){
        printf("chosen index out of range ");
        return ;
    }
    while (node != NULL){
        i++ ;
        if(i == index){
            Node *temp ;
            temp = node->next ;
            node->next = node->next->next ;
            free(temp);
            break;
        }
        node = node->next;
    }   
}   

int get_Length(Node *head){ 
    int count=0 ; 
    while( head != NULL ){
        head = head->next ; 
        count++ ; 
    }
    return count;
}


int main(int argc, char const *argv[])
{
    Node *head = createNode(111);

    // insert node at head 
    insert_atHead(&head, 777);
    insert_atHead(&head, 5);
    insert_atHead(&head, 1);

    //insert node at tail
    insert_atTail(head,8888);
    insert_atTail(head,99999);

    // insert node given index where to do so 
    insert_given_Index(head,2,66);    
    // insert node after a pre existing value in linked list 
    insert_given_Value(head, 8888, 69);

    printLinkedlist(head);
    // delete node given index
    delete_given_index(head, 8);
    printLinkedlist(head);
    // delete node given pre existing value  
    delete_given_Value(head, 111);
    // delete head of linked list 
    delete_head(&head);

    printLinkedlist(head);

    free(head);
    return 0;
}

