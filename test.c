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

IntNode* head = NULL;

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

IntNode* merge(IntNode* start1,IntNode* start2,IntNode* end1,IntNode* end2){
    IntNode* start = start1;
    IntNode* current = start;
    IntNode*end = end2;
    unsigned temp;
    IntNode* last_p,* temp_s2;
    IntNode* teste = head;
    last_p = start;
    if(start1->value > start2->value ){
            printf("FLAG do temp");
            temp = start1->value;
            start1->value = start2->value;
            start2->value = temp;
            printf("start 1 v: %u start 2 v:%u",start1->value,start2->value);
    }
    start1 = start1->next;
    while (start1 && start2)
    {
        
       // printf("Ponteiros start1:%p start2:%p end1:%p end2:%p\n",start1,start2,end1,end2->next);
        if(start1->value > start2->value){
            last_p = start2;
            start2 = start2->next;
        }else{
            last_p = start1;
            start1 = start1->next;
        }
        
        /*
        printf("\nstart 1 %u end 1 %u start2 %u end2 %u\n", start1->value,end1->value,start2->value,end2->value);
        
        temo_s1 = start1->next;
        temp_s2 = start2->next;
        start1 = temo_s1;
        start2= temp_s2; 
        
        temp_p = start2->next;
        start2->next = start1->next;
        start1->next = start2;
        start1 = start2;
        start2 = temp_p;
        */
        
    }
    
    while(teste != NULL){
        printf("Valor teste v:%u \n", teste->value);
        teste = teste->next;
    }
    return next_elment;
}

void msort(IntNode* v){
    int exp;
    IntNode* start1, *start2, *end1,*end2;
    IntNode* p = v;
    int count =0;
    unsigned temp;
    while(p->next){
            //printf("p : %p e p->nex %p",p,p->next);
            printf("FLAG 3 \n");
            if(p->value > p->next->value){
                temp = p->value;
                p->value = p->next->value;
                p->next->value = temp;
            }
            count+= 2;
            if(p->next->next)
                p = p->next->next;
            else 
                break;
    }
    
    printf("count %d",count);
    int dis;
    IntNode* pointer;
    for (exp =2;exp <count;exp <<= 1){
        pointer=v;
        printf("Flag 1 v %u: \n",v->value);
        while(pointer != NULL) {
            printf("Flag 2\n");
            start1 = pointer;
            for(dis = exp; (dis>1) && (pointer->next);dis--){
                pointer = pointer->next;
            }
            end1 = pointer;
            pointer = pointer->next;
            if(!pointer){
                break;
            }
            start2 = pointer;
            for(dis = exp; (dis>1) && (pointer->next);dis--){
                pointer = pointer->next;
            }
            end2 = pointer;
            printf("Mandando pro merge s1 %u s2 %u e1 %u e2 %u exp %d\n",start1->value,start2->value,end1->value,end2->value,exp);
            pointer = merge(start1,start2,end1,end2);
            
                        
        }
    }
}


IntNode* insert_list(unsigned value){
    IntNode * new_node;
    new_node = (IntNode *) malloc(sizeof(IntNode));
    new_node->value = value;
    (head)? (new_node->next = head) :(new_node->next = NULL);
    head = new_node;
    return new_node;

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
    /*
    IntNode v1 = {
        3,
        NULL
    };
    IntNode v2 = {
        1,
        &v1
    };
    IntNode v3 = {
        7,
        &v2
    };
    IntNode v4 = {
        20,
        &v3
    };
    IntNode v5 = {
        15,
        &v4
    };
    IntNode v6 = {
        36,
        &v5
    };
    IntNode v7 = {
        39,
        &v6
    };
    msort(&v7);
    IntNode*p;
    head = &v7;
    for(p = head; p!=NULL;p = p->next){
        printf("Valor %u  ",p->value);
    }

   */int a;
    for(int i =0; i< 100;i++){
        a= rand()%100;
        insert_list(a);
    }
    IntNode* p;
    printf("OLha a head crl %u",head->value);
    for(p = head; p!=NULL;p = p->next){
        printf("Valor %u  ",p->value);
    }
    msort(head);
    for(p = head; p!=NULL;p = p->next){
        printf("Valor %u  ",p->value);
    }
   
    printf("\n");
    return 0;
}





