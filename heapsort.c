/* https://algorithmtutor.com/Data-Structures/Tree/Binary-Heaps/ を参考にしました．*/

#include <stdio.h>
#define MAX_SIZE 15

/* 親を返す*/
int parent(int i) {
    return (i - 1) / 2;
}

/* 左子を返す*/
int left_child(int i) {
    return 2*i + 1;
}

/* 右子を返す*/
int right_child(int i) {
    return 2*i + 2;
}

/* 値の入れ替えを行う*/
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* ヒープに値を挿入*/
void insert(int a[], int data, int *n) {
    if (*n >= MAX_SIZE) {
        printf("%s\n", "The heap is full. Cannot insert");
        return;
    }
    // first insert the time at the last position of the array 
    // and move it up
    a[*n] = data;
    *n = *n + 1;


    // move up until the heap property satisfies
    int i = *n - 1;
    while (i != 0 && a[parent(i)] > a[i]) {
        swap(&a[parent(i)], &a[i]);
        i = parent(i);
    }
}


/* ヒープの再構成を行う*/
void heapify(int a[], int i, int n){

    int left = left_child(i);
    int right = right_child(i);
    int min = i;

    if (left <= n && a[left] < a[min]) {
        min = left;
    }

    if (right <= n && a[right] < a[min]) {
        min = right;
    }

    if (min != i) {
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        heapify(a, min, n);
    }

}

/* ヒープ中の最小要素を除去する */
int delete_min(int a[], int *n) {
    int min_item = a[0];

    a[0] = a[*n - 1];
    *n = *n - 1;

    heapify(a, 0, *n);
    return min_item;
}

int main() {
    int n = 0;
    int a[MAX_SIZE];

    insert(a, 55, &n);
    insert(a, 56, &n);
    insert(a, 57, &n);
    insert(a, 58, &n);
    insert(a, 100, &n);
    
    printf("%d\n", delete_min(a, &n));
    printf("%d\n", delete_min(a, &n));
    printf("%d\n", delete_min(a, &n));
    printf("%d\n", delete_min(a, &n));
    printf("%d\n", delete_min(a, &n));
 
    return 0;
}