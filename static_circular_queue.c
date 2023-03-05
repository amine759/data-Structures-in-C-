#include<stdio.h>
#include<stdlib.h>
#define size 4


int isFull(int head, int tail){
    if ((head == 0)&&(tail == size-1) || head == tail+1){
        return 1 ; 
    }
    return 0;
}

int isFull(int head, int tail);
int isEmpty(int head);

int isEmpty(int head){
    if (head == -1) return 1 ;
}

void enQueue(int queue[size],int* head,int* tail, int data){
   
    if (isFull(*head,*tail)){ 
        printf("\nQueue is full\n");
        return ; 
        }
    else {
        if(*tail<=size-1){

            if (*tail == size-1 && *head>=0){ 
                *head = 0 ;
                queue[*head] = data ;
                return ;
            }
            (*tail)++;
            queue[*tail]=data;

        if(*head==-1) (*head)++ ;
        }
    }
}
void deQueue(int queue[size], int* head, int* tail){
    int y ;
    if(isEmpty(*head)){
        printf("\nQueue is Empty\n");
        return ;
    }
    if (*head>-1){
        y = queue[*head] ;

    if(*head == *tail) *tail = *head = -1 ;
    else {
        if (*head == size-1) *head = 0 ;
        else (*head)++ ; 
    }
    }
}

void display(int queue[size],int* top,int* tail){
	int i;

    if (*top == -1 ){
        printf("Queue is empty \n");
        return ;
    } else {
	    printf("items in queue are:\n");
	    for(i= *top; i<=*tail; i++){
        printf(" | ");
        printf("%d",queue[i]);
    }
        printf("\n");
    }
}


int main(int argc, char const *argv[])
{
    int queue[size] = {} ;
    int head,tail ;
    head = tail = -1 ;
    enQueue(queue,&head,&tail,1);
    enQueue(queue,&head,&tail,21);
    enQueue(queue,&head,&tail,3);
    enQueue(queue,&head,&tail,4);
    display(queue,&head,&tail);

    printf("head : %d, tail : %d\n",head,tail);

    deQueue(queue,&head,&tail);

    display(queue,&head,&tail);
    printf("head : %d, tail : %d\n",head,tail);

    enQueue(queue,&head,&tail,69);

    display(queue,&head,&tail);
    printf("head : %d, tail : %d\n",head,tail);
    
    return 0;
}