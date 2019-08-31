#include <stdio.h>
#include <stdlib.h>
#define Matrix(i,j) matrix[i][j-i-1]

/*
int
main (){
    unsigned int a = 1000000000;
    size_t b;
    long long c;
    printf("%d\n",a);
    printf("int %ld\n",sizeof(a));
    printf("size_t %ld\n", sizeof(b));
    printf("long %ld\n", sizeof(c));
}
typedef struct node
{
    struct node** value; //Aponta para a posição do elemento no array
    struct node* next; //Aponta para o próximo elemento da lista
} PointerNode;
*/
unsigned long v_number_global;


typedef struct int_node
{
    /* data */
    unsigned int value;
    struct int_node* next;

} IntNode;

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
        new_pointer->value = v.value;
        new_pointer->next = NULL;
        last->next = new_pointer;
        return new_pointer;
    }
    
}

char** readMatrix(unsigned long v_number);

IntNode** read_list_int(unsigned long v_number);
void print_list_int(IntNode** p);
void print_matrix(char** matrix);



int main (int argc,char** argv ){
    
    scanf("%lu", &v_number_global);
    printf("%lu\n",v_number_global);
    int c;
    char** matrix;
    IntNode** list;
    while(--argc>0 && (*++argv)[0] == '-'){
        while (c = *++argv[0]){
            switch (c)
            {
            case 'm':
                matrix= readMatrix(v_number_global);
                print_matrix(matrix);
                break;
            case 'l':
                list = read_list_int(v_number_global);
                print_list_int(list);
                break;
            default:
                printf("Eroor data structure not privided");
                break;
            }
        }
    }
    
    
    return 0;
}


void print_matrix(char** matrix){
    for (unsigned i= 0;  i< v_number_global; i++){
        for(unsigned j = (i+1); j< v_number_global;j++ ){ 
            printf("linha %d coluna %d %i \n",i,j,Matrix(i,j));}
    } 
}

char** readMatrix(unsigned long v_number){
    //aloca Espaço para matriz
    char** p;
    if((p = (char** )calloc(v_number, sizeof(char* [v_number]))) == NULL){
        printf("Fatal Error");
        exit(1);
    }

    for(unsigned i = 1; i<=(v_number) ; i++){
        p[i-1] = (char *) calloc((v_number-i), sizeof(char));
        //printf("Flag %d \n" ,p[i][1]);
    }
    int a,b;
    while((fscanf(stdin,"%d %d",&a,&b)) != EOF){
       // printf("a= %d b = %d\n",a,b);
        (a<=b) ? (p[a][b-a-1] =1 ) : (p[b][a-b-1]=1); 
            
    }
    return p;

}



void print_list_int(IntNode** list){
    IntNode* index;
    unsigned int i;
    printf("Lista ->[\n");
    for (i =0; i<v_number_global; i++ ){
        printf("Index %d ->  ",i);
        index = list[i];
        while (index!= NULL){
            printf("%d ", index->value);
            index = index->next;
        }
        printf("\n");
    }
    printf("] \n");

}

// Lembrar ponteiros são passados por valor 
//Bota o ponteiro na lista
IntNode* put_inode(IntNode* p ,unsigned int value){
    IntNode* new_pointer;
    if (new_pointer = (IntNode *) malloc(sizeof(IntNode))){
        new_pointer->value = value;
        new_pointer->next = p;
        ///printf("Ponteiro antes p :%p\n",p);
        ///printf("Ponteiro depois p :%p\n",p);
        ///printf("O que eu estou botando %u %p \n",new_pointer->value, new_pointer);
        return new_pointer;
    }
    exit(1);
     
}

IntNode** read_list_int(unsigned long v_number){
    IntNode** p;
    p = (IntNode **) calloc(v_number,sizeof(IntNode *));
    IntNode** pointer;
    unsigned int a,b;
    while((fscanf(stdin,"%d %d",&a,&b)) != EOF){
        //printf("Fazendo a %d  e b %d \n",a,b);
        p[a] = put_inode(p[a],b);
        p[b] = put_inode(p[b],a);
        //printf("Index %d ",a);
        //print_list_int(p[a]);
        //printf("Index %d ",b);
        //print_list_int(p[b]);
        //printf("Atualmente p[a] : %u e p[b]: %u \n", p[a]->value,p[b]->value);        
    }
    
    return p;
}

