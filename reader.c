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
*/
typedef struct node
{
    struct node** value; //Aponta para a posição do elemento no array
    struct node* next; //Aponta para o próximo elemento da lista
} PointerNode;

typedef struct int_node
{
    /* data */
    unsigned int value;
    struct int_node* next;

} IntNode;

char** readMatrix(unsigned long v_number);

IntNode** read_list_int(unsigned long v_number);
void print_list_int(IntNode* p);


int main (int argc,char** argv ){
    unsigned long v_number;
    scanf("%lu", &v_number);
    printf("%lu\n",v_number);
    //char** matrix = readMatrix(v_number);
    /*
    for (int i= 0;  i< v_number; i++){
        for(int j = (i+1); j< v_number;j++ ){ 
            printf("linha %d coluna %d %i \n",i,j,Matrix(i,j));}
    } 
    */
    IntNode** list = read_list_int(v_number);
    IntNode* p;
    printf("[ \n");
    for(int i = 0; i<v_number; i++){
       printf("%d - > ",i);
       print_list_int(list[i]);
    }
    printf("] ");
    
    return 0;
}

char** readMatrix(unsigned long v_number){
    //aloca Espaço para matriz
    char** p;
    if((p = (char** )calloc(v_number, sizeof(char* [v_number]))) == NULL){
        printf("Fatal Error");
        exit(1);
    }

    for(int i = 1; i<=(v_number) ; i++){
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

void print_list_int(IntNode* p){
    printf("Lista ->  ");
    while (p!= NULL){
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");

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
    p = (IntNode **) calloc(v_number,sizeof(IntNode *)*v_number);
    IntNode** pointer;
    unsigned int a,b;
    while((fscanf(stdin,"%d %d",&a,&b)) != EOF){
        printf("Fazendo a %d  e b %d \n",a,b);
        p[a] = put_inode(p[a],b);
        p[b] = put_inode(p[b],a);
        printf("Index %d ",a);
        print_list_int(p[a]);
        printf("Index %d ",b);
        print_list_int(p[b]);
        //printf("Atualmente p[a] : %u e p[b]: %u \n", p[a]->value,p[b]->value);        
    }
    
    return p;
}
/*
PointerNode** read_list_pointer(unsigned long v_number){
    
}
*/
