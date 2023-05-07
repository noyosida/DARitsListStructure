#include <stdio.h>
#include <stdlib.h>

struct vertex{
    int name;
    int key;
    struct vertex *next;
};

//リストの内容を出力
void print(struct vertex *top){

    struct vertex *p;
    
    p = top;

    while (p != NULL){
        printf("name = %d, key = %d\n", p->name, p->key);
        p = p->next;
    }
}

//リストの要素を作成
struct vertex *create(int name, int key){
    struct vertex *p = (struct vertex*) malloc(sizeof(struct vertex));
    p->name = name;
    p->key = key;
    p->next = NULL;

    return p;
}

int main(void){

    struct vertex *top, *p;
        
    p  = create (1, 7);
    top = p;

    printf("挿入前\n");
    print(top);
    printf("\n");

    p  = create (2, 11);
    p->next = top;
    top = p;

    printf("挿入後\n");

    print(top);

}

