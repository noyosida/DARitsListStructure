#include <stdio.h>
#include <stdlib.h>

struct vertex{
    int name;
    int key;
    struct vertex *next;
};
struct vertex *top1, *top2, *rear1, *rear2;

void print(struct vertex *top){

    struct vertex *p;
    
    p = top;

    while (p != NULL){
        printf("name = %d, key = %d\n", p->name, p->key);
        p = p->next;
    }
}

struct vertex *create(int name, int key){
    struct vertex *p = (struct vertex*) malloc(sizeof(struct vertex));
    p->name = name;
    p->key = key;
    p->next = NULL;

    return p;
}

//struct vertex *insert(struct vertex* prev){


//}

void init(void){

    struct vertex *p, *rear;

    top1 = NULL;
    top2 = NULL;
        
    p  = create (1, 7);
    top1 = p;
    rear1 = p;

    p  = create (2, 11);
    p->next = top1;
    top1 = p;

    p  = create (3, 15);
    p->next = top1;
    top1 = p;

    p  = create (4, 19);
    top2 = p;
    rear2 = p;

    p  = create (5, 23);
    p->next = top2;
    top2 = p;
}

int main(void){

    struct vertex *p;
    
    init();

    printf("合併前\n");
    printf("L1:\n");
    print(top1);

    printf("L2:\n");
    print(top2);
    printf("\n");
   
    rear2->next = top1;
    top1 = top2;
    top2 = NULL;
    rear2 = NULL;

    printf("合併後\n"); 
    printf("L1:\n");
    print(top1);

    printf("L2:\n");
    print(top2);
}

