#include<stdio.h>
#include<stdlib.h>

// Queues in C (FIFO : First In First Out)

typedef struct Element
{
    int data;
    struct Element *next;
} Element;

typedef struct Queue {
    struct Element *head ; 
    struct Element *tail ;
    int size ;
} Queue ; 


Element* createElement(int data);

Queue* init() {
    Queue *queue = malloc(sizeof(struct Queue));
    queue->head = NULL ; 
    queue->tail = NULL ;
    return queue ;
}

Element* createElement(int data){
    Element *new_element = (Element*)malloc(sizeof(struct Element));
    new_element->data = data ; 
    new_element->next = NULL ; 
    return new_element ; 
}

void enQueue(Queue *queue, int data){
    Element *new_element = createElement(data);
    if (new_element == NULL){
        printf("\n*** no enough memory ***\n");
    }
    if(queue->size == 0){
        queue->tail = new_element ; 
        queue->head = new_element ;
    }
    else {
        queue->tail->next = new_element ; 
        queue->tail = new_element ; 
    }        
    new_element->next = NULL ; 
    queue->size++ ;
}

void deQueue(Queue *queue){
    Element *del_element;

    if(queue->size == 0) printf("*** Queue is empty ***");
    del_element = queue->head ;
    int data = del_element->data ;
    queue->head = queue->head->next ; 
    queue->size-- ;
    printf("\n****Element %d deleted ****\n", data);    
    free(del_element);
}

void printQueue(Queue *queue){ 
    Element *current;
    current = queue->head;
    for (int i = 0; i < queue->size; i++)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main(int argc, char const *argv[])
{
    Queue *queue = init();
    
    enQueue(queue, 11);
    enQueue(queue, 22);
    enQueue(queue, 33);
    enQueue(queue, 44);
    printQueue(queue);
    deQueue(queue);
    printQueue(queue);
    printf("*** queue of size %d, head %d, tail %d ****\n",queue->size,queue->head->data, queue->tail->data);

    free(queue);
    return 0;
}
