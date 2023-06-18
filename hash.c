/* https://daeudaeu.com/hash-chain/ のプログラムを参考にしました*/

#include <stdio.h>
#include <stdlib.h>

/* ハッシュテーブルのサイズ */
#define NUM_BUCKET 5

/* ノードを表現する構造体 */
struct NODE {
    int data; /* 管理するデータ */
    struct NODE *next; /* 次のノード */
};


/* ハッシュテーブル（各要素はリストの先頭を指すポインタ） */
static struct NODE *hash_table[NUM_BUCKET];


/******************************
 * リストにノードを追加する関数
 * number：追加するノードの番号
 * name：追加するノードの名
 * 返却値：0（成功時）
 *      ：-1（失敗時）
 ******************************/ 
int add(struct NODE **head, int data){
    struct NODE *new; /* 追加するノードのアドレス */
    struct NODE *node; /* 今注目しているノードのアドレス */
    struct NODE *prev; /* nodeの前のノードのアドレス */

    /* ノードを新規追加 */
    new = (struct NODE*)malloc(sizeof(struct NODE));
    if (new == NULL) {
        return -1;
    }

    new->data = data;

    /* リストの先頭のノードに注目 */
    node = *head;

    /* ノードを追加する位置を決める */
    while (node != NULL) {
        
        /* nodeを前のノードとして覚えておく */
        prev = node;

        /* 次のノードを辿る */
        node = node->next;
    }

    if (node == *head) {
        /* 追加する位置がリストの先頭の場合 */

        /* 元々先頭だったノードをnewの次のノードにする */
        new->next = *head; /* リストが空の場合はheadはNULL */

        /* リストの先頭をnewとする */
        *head = new;

    } else {
        /* 追加する位置がリストの先頭以外の場合 */

        /* prevとnodeの間にnewを追加 */
        prev->next = new;
        new->next = node; /* 追加する位置が末尾の場合ははnodeはNULLになっている */
    }

    return 0;
}

/******************************
 * リストからノードを削除する関数
 * targetr：削除するノードの番号
 * 返却値：0（成功時）
 *      ：-1（失敗時）
 ******************************/ 
int delete(struct NODE **head,int target){
    struct NODE *node; /* 今注目しているノードのアドレス */
    struct NODE *prev; /* nodeの前のノードのアドレス */

    if (*head == NULL) {
        /* リストが空なら何もしない */

        return -1;
    }

    /* リストの先頭のノードに注目 */
    node = *head;

    if (node->data == target) {
        /* 削除対象がリストの先頭のノードの場合 */

        /* リストの先頭をnodeの次のノードにしてnodeを削除 */
        *head = node->next;
        free(node);

        return 0;
    }

    while (node != NULL) {

        if (node->data == target) {
            /* 削除対象のノードが見つかった */

            /* prevの次のノードをnodeの次のノードに設定 */
            prev->next = node->next;

            /* 削除対象のノードを削除して終了 */
            free(node);

            return 0;
        }

        /* nodeを前のノードとして覚えておく */
        prev = node;

        /* 次のノードを辿る */
        node = node->next;

    }

    /* targetを持つノードが見つからなかった */
    return -1;
}

/******************************
 * リストからノードを探索する関数
 * target：探索するノードの番号
 * 返却値：見つかったノードのアドレス（成功時）
 *      ：NULL（失敗時）
 ******************************/ 
struct NODE * search(struct NODE *head, int target){
    struct NODE *node; /* 今注目しているノードのアドレス */

    /* リストの先頭のノードに注目 */
    node = head;

    while (node != NULL) {

        if (node->data == target) {
            /* 探索したいノードが見つかった */

            return node;
        }

        /* 次のノードを辿る */
        node = node->next;

    }

    /* targetを持つノードが見つからなかった */
    return NULL;
}

/******************************
 * ハッシュ値を算出する関数
 * data：ハッシュ値の元になるデータ
 * 返却値：算出したハッシュ値
 ******************************/ 
unsigned int hash(int data) {
    unsigned int u_data = data;

    return u_data % NUM_BUCKET;    
}

/******************************
 * ハッシュテーブルを初期化する関数
 ******************************/ 
void hash_initialize(void) {
    int i;

    for (i = 0; i < NUM_BUCKET; i++) {
        hash_table[i] = NULL;
    }
}

/******************************
 * ハッシュテーブルの終了処理を行う関数
 ******************************/ 
void hash_finalize(void) {
    int i;

    for (i = 0; i < NUM_BUCKET; i++) {
        
        /* 各バケットが空になるまでノードの削除を繰り返す */    
        while (hash_table[i] != NULL) {
            
            delete(&hash_table[i], hash_table[i]->data);
        }
    }
}


/******************************
 * リスト構造の表示を行う関数
 ******************************/ 
void print_hashtable(void) {
    int i;
    struct NODE *node;

    printf("リスト構造の内容\n");

    for (i = 0; i < NUM_BUCKET; i++) {

        printf("%d: ", i);

        node = hash_table[i];
        /* 各バケットが空になるまでノードの削除を繰り返す */    
        do{
            printf("%d ", node->data);
            node = node -> next;
        }while (node != NULL);
        printf("\n");
    }
    
    printf("\n");

}

/******************************
 * ハッシュテーブルにデータを追加する関数
 * data：追加したいデータ
 * 返却値：0（成功時）
 *      ：-1（失敗時）
 ******************************/ 
int hash_insert(int data) {
    unsigned int i;

    /* ハッシュ値の算出 */
    i = hash(data);

    if (i >= NUM_BUCKET) {
        return -1;
    }

    /* ハッシュ値の位置のバケットのリストにデータ格納 */
    return add(&hash_table[i], data);

}

/******************************
 * ハッシュテーブルからデータを探索する関数
 * data：探索したいデータ
 * 返却値：見つかった位置のアドレス（成功時）
 *      ：NULL（失敗時）
 ******************************/ 
struct NODE* hash_member(int data) {
    
    unsigned int i;
    
    /* ハッシュ値の算出 */
    i = hash(data);

    if (i >= NUM_BUCKET) {
        return NULL;
    }

    /* ハッシュ値の位置のバケットのリストから探索 */
    return search(hash_table[i], data);

}

/******************************
 * ハッシュテーブルからデータを削除する関数
 * data：削除したいデータ
 * 返却値：0（成功時）
 *      ：-1（失敗時）
 ******************************/ 
int hash_delete(int data) {
    
    unsigned int i;
    
    /* ハッシュ値の算出 */
    i = hash(data);

    if (i >= NUM_BUCKET) {
        return -1;
    }

    /* ハッシュ値の位置のバケットのリストから削除 */
    return delete(&hash_table[i], data);
}

int main(void) {
    unsigned int data[9] = {
        21, 99, 55, 38, 30,
        22, 14, 6, 47
    };
    int i;

    hash_initialize();

    /* データの格納 */
    for (i = 0; i < 9; i++) {
        if (!hash_insert(data[i])) {
            printf("%d is INSERTED\n", data[i]);
        }
    }

    printf("\n");

    print_hashtable();

    if (!hash_insert(33)) {
        printf("%d is INSERTED\n", 33);
    }

    if (!hash_delete(22)) {
        printf("%d is DELETED\n", 22);
    }

    if (hash_member(33)) {
        printf("%d is FOUND\n", 33);
    }

    printf("\n");

    print_hashtable();
    hash_finalize();

    return 0;
}
