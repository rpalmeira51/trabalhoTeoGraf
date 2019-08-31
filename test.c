/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  28/08/2019 00:25:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>


typedef struct int_node
{
    /* data */
    unsigned int value;
    struct int_node* next;

} IntNode;

typedef struct stack 
{
    IntNode* top;
}Stack;


IntNode stack_pop(Stack* stack){ 
    IntNode* v_p;
    IntNode v;
    v_p = stack->top;
    stack->top = v_p->next;
    v = *(v_p);
    free(v_p);
    return v;

}

void stack_push(Stack* stack, IntNode v){
    IntNode* top = stack->top;
    IntNode* new_pointer;
    if (new_pointer = (IntNode *) malloc(sizeof(IntNode))){
        new_pointer->value = v.value;
        new_pointer->next = top;
        stack->top = new_pointer;
    }
    else
    {
        printf("Fatal error Out of memory");
        exit(1);
    }
    
}
void print_stack(Stack* stack){
    IntNode v;
    while((stack->top) != NULL){
        v = stack_pop(stack);
        printf("%d \n",v.value);
    }
}

typedef struct queue
{
    IntNode* rear;
    IntNode* top;
} Queue;

// Dá pop na pilha
IntNode queue_pop(Queue* q){
    IntNode* p_v;
    IntNode vertice;
    p_v = q->top;
    q->top = p_v->next;
    vertice = *(p_v);
    free(p_v);
    return (vertice);
}

void queue_push(Queue* q, IntNode v){
    IntNode* last = q->rear;
    IntNode* new_pointer;
    if (new_pointer = (IntNode *) malloc(sizeof(IntNode))){
        if(q->top){
            new_pointer->value = v.value;
            new_pointer->next = NULL;
            last->next = new_pointer;
            q->rear = new_pointer;
        }else {
            new_pointer->value = v.value;
            new_pointer->next = NULL;
            q->rear = new_pointer;
            q->top = new_pointer;
        }
        //return new_pointer;
    }else
    {
        printf("Fatal error Out of memory");
        exit(1);
    }
    
    
}
void print_queue(Queue* q){
    IntNode v;
    while((q->top) != NULL){
        v = queue_pop(q);
        printf("%d \n",v.value);
    };

}
int main (){
    Stack q;
    IntNode v = {
        3,
        NULL
    };
    stack_push(&q, v);
    v.value = 4;
    stack_push(&q, v);
    v.value = 5;
    stack_push(&q, v);
    v.value = 6;
    stack_push(&q, v);
    v.value = 7;
    stack_push(&q, v);
    v.value = 8;
    stack_push(&q, v);
    stack_pop(&q);
    v.value = 9;
    stack_push(&q, v);
    print_stack(&q);
    return 0;
}





