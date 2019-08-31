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
    Queue q;
    IntNode v = {
        3,
        NULL
    };
    queue_push(&q, v);
    v.value = 4;
    queue_push(&q, v);
    v.value = 5;
    queue_push(&q, v);
    v.value = 6;
    queue_push(&q, v);
    v.value = 7;
    queue_push(&q, v);
    v.value = 8;
    queue_push(&q, v);
    queue_pop(&q);
    v.value = 9;
    queue_push(&q, v);
    print_queue(&q);
    return 0;
}





