#include<stdio.h>
#include<stdlib.h>
#define size 5

void empile(int stack[size],int *head, int x){
    if(*head <= size-1){
        (*head)++;
        stack[*head]=x ;
    } else{
        printf("stack is full");
    }
}

void depile(int stack[size],int* head){
    int y ;
    if (*head==-1) printf("empty stack");
    else {
        y = stack[*head] ;
        printf("deleted item %d\n",y);
        (*head)--;
    }
}
void display(int *stack,int* top){
	int i;
 
	printf("items in stack are:\n");
 
	for(i= *top; i>=0; i--) printf("%d\n", stack[i]);

}
int main(int argc, char const *argv[])
{   
    int stack[size] = {} ;
    int head = -1 ;
    empile(stack,&head,2);
    empile(stack,&head,3);
    empile(stack,&head,4);
    empile(stack,&head,69);
    depile(stack,&head);

    display(stack,&head);
    return 0;
}
