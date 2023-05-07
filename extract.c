#include <stdio.h>
#include <stdlib.h>

struct vertex{
    int name;
    int key;
    struct vertex *next;
};
struct vertex *top1, *top2;

// リストの内容を出力
void print(struct vertex *top){

    struct vertex *p;
    
    p = top;

    while (p != NULL){
        printf("name = %d, key = %d\n", p->name, p->key);
        p = p->next;
    }
}

// リストの要素を作成
struct vertex *create(int name, int key){
    struct vertex *p = (struct vertex*) malloc(sizeof(struct vertex));
    p->name = name;
    p->key = key;
    p->next = NULL;

    return p;
}

// 初期状態を作成
struct vertex *init(void){

    struct vertex *p, *cut;

    top1 = NULL;
    top2 = NULL;
        
    p  = create (1, 7);
    top1 = p;

    p  = create (2, 11);
    p->next = top1;
    top1 = p;

    p  = create (3, 15);
    p->next = top1;
    top1 = p;

    p  = create (4, 19);
    p->next = top1;
    top1 = p;
    cut = p;

    p  = create (5, 23);
    p->next = top1;
    top1 = p;

    return cut;
}

int main(void){

    struct vertex *p;
    
    p = init();

    printf("切り取り前\n");
    printf("L1:\n");
    print(top1);

    printf("L2:\n");
    print(top2);
    printf("\n");

    top2 = top1;
    top1 = p->next;
    p->next = NULL;

    printf("切り取り後\n");
    printf("L1:\n");
    print(top1);

    printf("L2:\n");
    print(top2);

}

