#include <stdio.h>
#include <stdlib.h>
//#define Matrix(i,j) matrix[i][j-i-1]
#define Matrix(i,j) (j>i) ? matrix[i][j-i-1] : matrix[j][i-j-1]

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

//Globais pro arquivo
unsigned long v_number_global;

//Globais pro projeto

//Estruturas de dados 
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

//Prototipos de Funções
IntNode queue_pop(Queue* q);
void queue_push(Queue* q, unsigned index);
void print_queue(Queue* q);
char** readMatrix(unsigned long v_number);
IntNode** read_list_int(unsigned long v_number);
void print_list_int(IntNode** p);
void print_matrix(char** matrix);
unsigned**  bfs_list(IntNode** list, unsigned index);
unsigned**  bfs_matrix(char** matrix, unsigned index);
unsigned shortest_path(unsigned v2,unsigned* marking);
unsigned diameter_list(IntNode** list);
unsigned diameter_matrix(char** matrix);

int main (int argc,char** argv ){
    
    scanf("%lu", &v_number_global);
    printf("%lu\n",v_number_global);
    int c;
    char** matrix;
    IntNode** list;
    int index = 2;
    unsigned** bfs_return;
    while(--argc>0 && (*++argv)[0] == '-'){
        while (c = *++argv[0]){
            switch (c)
            {
            case 'm':
                matrix= readMatrix(v_number_global);
                print_matrix(matrix);
                bfs_return = bfs_matrix(matrix,index);
                shortest_path(6,bfs_return[0]);
                diameter_matrix(matrix);
                break;
            case 'l':
                list = read_list_int(v_number_global);
                print_list_int(list);
                bfs_return = bfs_list(list,index);
                shortest_path(1,bfs_return[0]);
                diameter_list(list);
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

void queue_push(Queue* q, unsigned index){
    IntNode* last = q->rear;
    IntNode* new_pointer;
    if (new_pointer = (IntNode *) malloc(sizeof(IntNode))){
        if(q->top){
            new_pointer->value = index;
            new_pointer->next = NULL;
            last->next = new_pointer;
            q->rear = new_pointer;
        }else {
            new_pointer->value =index;
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

//Menor caminho de v1 até v2 pelo vetor de marcaçãp
unsigned shortest_path(unsigned v2,unsigned* marking){
    unsigned d=0;
    unsigned first = ~(0x1);
    unsigned none = ~(0x0);
    while (marking[v2] != first){
        if(marking[v2] == none){
            printf("There is no shortest path\n");
            return 0;
        }
        marking[v2] = marking[marking[v2]];
        d++;
    }
    printf("%u\n",d);
    return d;
}

unsigned max_array(unsigned* array){
    unsigned* p ;
    register unsigned max = 0;
    for(p = array; p< (array + v_number_global); p++) 
        max = (*p>max) ? *p :max;
    return max;
}

unsigned diameter_list(IntNode** list){
    unsigned none = ~(0x0);
    unsigned d = 0;
    unsigned* level;
    unsigned max_graph =0;
    unsigned max =0 ;
    for(unsigned i =0; i< v_number_global; i++){
        level = (bfs_list(list,i))[1];
        max = max_array(level);
        max_graph = (max_graph<max) ? max: max_graph;
    }
    printf("diameter %d\n",max_graph);
    return max_graph;
}

unsigned diameter_matrix(char** matrix){
    unsigned d = 0;
    unsigned* level;
    unsigned max_graph =0;
    unsigned max =0 ;
    for(unsigned i =0; i< v_number_global; i++){
        level = (bfs_matrix(matrix,i))[1];
        max = max_array(level);
        max_graph = (max_graph<max) ? max: max_graph;
    }
    printf("diameter %d\n",max_graph);
    return max_graph;

}

unsigned** bfs_list(IntNode** list, unsigned index){
    //Define NULL como 2^32
    //E marcado como (2^32 -1)
    //tendo em vista que nenhum grafo tem perto de 4 bilhões de vertices, isso não é um problema
    unsigned* marking;
    unsigned* level;
    unsigned none = ~(0x0);
    unsigned explored = ~(0x1);
    if((marking = (unsigned * ) malloc(v_number_global*sizeof(unsigned))) == NULL){
        printf("Out of memory");
        exit(1);
        //return 1;
    } 
    if((level = (unsigned * ) malloc(v_number_global*sizeof(unsigned))) == NULL){
        printf("Out of memory");
        exit(1);
        //return 1;
    } 
    Queue q= {
        NULL,
        NULL
    };
    for (unsigned i =0; i<v_number_global; i++){
        marking[i] = none;
        level[i] = none;
    }
    marking[index] = explored;
    level[index] =0;
    queue_push(&q,index);
    IntNode* linked_list;
    IntNode v,w;
    while ( (q.top) != NULL)
    {
        v = queue_pop(&q);
        linked_list=list[v.value];
        printf("linked_list->value \n");
        while (linked_list!= NULL){
            if((marking[linked_list->value]) == none){
                marking[linked_list->value] = v.value;
                level[linked_list->value] = level[v.value] +1;
                queue_push(&q,linked_list->value);
            }
            printf("Explorando %d ", linked_list->value);
            linked_list = linked_list->next;
        }
    

    }
    
    printf("Vetor de marcação [ \n");
    for(unsigned i =0; i< v_number_global;i++){
        printf("index:%u marcado:%u \n", i, marking[i]);
    }
    printf("]\n");
    printf("Vetor de level [ \n");
    for(unsigned i =0; i< v_number_global;i++){
        printf("index:%u marcado:%u \n", i, level[i]);
    }
    printf("]\n");
    unsigned** array;
    if((array = (unsigned ** ) malloc(v_number_global*sizeof(unsigned)*2)) == NULL){
        printf("Out of memory");
        exit(1);
    } 
    array[0]=  marking; 
    array[1]=  level;
    return array;
    
};

unsigned** bfs_matrix(char** matrix, unsigned index){ 
    //Define NULL como 2^32
    //E marcado como (2^32 -1)
    //tendo em vista que nenhum grafo tem perto de 4 bilhões de vertices, isso não é um problema
    unsigned* marking;
    unsigned* level;
    unsigned none = ~(0x0);
    unsigned explored = ~(0x1);
    if((marking = (unsigned * ) malloc(v_number_global*sizeof(unsigned))) == NULL){
        printf("Out of memory");
        exit(1);
        //return 1;
    } 
    if((level = (unsigned * ) malloc(v_number_global*sizeof(unsigned))) == NULL){
        printf("Out of memory");
        exit(1);
        //return 1;
    } 
    Queue q= {
        NULL,
        NULL
    };
    for (unsigned i =0; i<v_number_global; i++){
        marking[i] = none;
        level[i] = none;
    }
    marking[index] = explored;
    level[index] =0;
    queue_push(&q,index);
    IntNode v,w;
    register unsigned j;
    while ( (q.top) != NULL)
    {
        v = queue_pop(&q);
        j= v.value;
        for(unsigned i =0 ; i< j; i++){
            if((Matrix(i,j)) == 1){
                if(marking[i] == none){
                    marking[i] = j;
                    level[i] = level[j] +1;
                    queue_push(&q,i);
                }
            }
        }
        for(unsigned i =(j+1); i< v_number_global;i++){
            if((Matrix(j,i)) == 1){
                if(marking[i] == none){
                    marking[i] = j;
                    level[i] = level[j] +1;
                    queue_push(&q,i);
                }
            }
        }   
    }
    printf("Vetor de marcação [ \n");
    for(unsigned i =0; i< v_number_global;i++)
        printf("index:%u marcado:%u \n", i, marking[i]);
    printf("]\n");
    printf("Vetor de level [ \n");
    for(unsigned i =0; i< v_number_global;i++)
        printf("index:%u marcado:%u \n", i, level[i]);
    printf("]\n");
    unsigned** array;
    if((array = (unsigned ** ) malloc(v_number_global*sizeof(unsigned)*2)) == NULL){
        printf("Out of memory");
        exit(1);
    } 
    array[0]=  marking; 
    array[1]=  level;
    return array;
    
}