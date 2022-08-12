#include<stdio.h>
#include<stdlib.h>

// stacks in C (LIFO : Last In First Out)


typedef struct Element
{
    int data;
    struct Element *next;
} Element;

typedef struct Stack
{
    Element *head;
    int size;
} Stack;


Stack* init() ; 
Element* createElement(int data);



Stack* init()
{
    Stack *stack = malloc(sizeof(Stack)); // stack variable of type pointer points to a Stack
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

Element* createElement(int data)
{
    Element *new_element = (Element*)malloc(sizeof(Element));

    new_element->data = data;
    new_element->next = NULL;
    return new_element;
}

void addElement(Stack *stack, int data)
{
    Element *new_element = createElement(data);
    if (new_element == NULL){
        printf("\n*** no enough memory ***\n");
    }

    new_element->next = stack->head;
    stack->head = new_element;
    stack->size++;
}

void deleteElement(Stack *stack)
{
    Element *del_element;

    if (stack->size == 0) printf("*** Stack is empty ***");

    del_element = stack->head;
    int data = del_element->data;
    stack->head = stack->head->next ;
    stack->size--;
    printf("\n****Element %d deleted ****\n", data);
    free(del_element);
}

void printStack(Stack *stack)
{
    Element *current;
    current = stack->head;
    for (int i = 0; i < stack->size; i++)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main(int argc, char const *argv[])
{
    Stack *stack = init();
    
    addElement(stack, 11);
    addElement(stack, 22);
    addElement(stack, 33);
    addElement(stack, 44);

    printStack(stack);
    deleteElement(stack);
    printStack(stack);
    
    printf("\nstack of size %d and head %d\n",stack->size,stack->head->data);
    free(stack);
    return 0;
}
