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

void queue_push(Queue* q, unsigned v){
    IntNode* last = q->rear;
    printf("%p", (void *) last);
    IntNode* new_pointer;
    if (new_pointer = (IntNode *) malloc(sizeof(IntNode))){
        if((q->top)){
            new_pointer->value = v;
            new_pointer->next = NULL;
            //last->next = new_pointer;
            //q->rear = new_pointer;
        }else {
            new_pointer->value = v;
            new_pointer->next = (NULL);
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
unsigned v_number_global;
unsigned max_array(unsigned* array){
    unsigned* p ;
    unsigned max = 0;
    for(p = array; p< (array + v_number_global); p++) 
        max = (*p>max) ? *p :max;
    return max;
}
//Código do R&K C_Programming segunda edição modificado
int cmpfunc (const void * a, const void * b){
        unsigned ai = *( unsigned* )a;
        unsigned bi = *( unsigned* )b;
        int r;
        r = (ai<bi) ? -1 :  1;
        return r;
        
}

int main (){
    /*
    Queue q = {
        NULL,
        NULL
    };
    v_number_global = 10;
    unsigned array[10] = {1,2,4,5,6,8,20,90,44};
    unsigned m = max_array(array);
    printf(" olha o max %d \n",m);*/
    unsigned array[100];
    for(int i =0; i< 100; i++){
        array[i] = rand()%100;
    }

    int cmpfunc (const void * a, const void * b);

    qsort(array,100,sizeof(unsigned),cmpfunc);
    printf("[ ");
    for (int i =0; i<100;i++)
        printf("%u, ", array[i]);
    printf("]\n");
    /*
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
    unsigned v =3;
    queue_push(&q, 3);
    
    unsigned v=3;
    v = 4;
    queue_push(&q, v);
    
    v= 5;
    queue_push(&q, v);
    v = 6;
    queue_push(&q, v);
    v = 7;
    queue_push(&q, v);
    v = 8;
    queue_push(&q, v);
    queue_pop(&q);
    v = 9;
    queue_push(&q, v);
    print_queue(&q);
    */
    return 0;
}





