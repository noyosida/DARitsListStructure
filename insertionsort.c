/* 右のサイトのソースコードを改変しました．https://www.codereading.com/algo_and_ds/algo/source/bubble_sort.c */
/* ライセンスについては，右のサイトに従います． https://www.codereading.com/copyright.html */


#include <stdio.h>

#define NUM_ITEMS 6

void insertionSort(int numbers[], int array_size);
void printArray(int numbers[], int array_size);

void swap(int *p_from, int *p_to);

int numbers[NUM_ITEMS];


int main()
{
    int i;

    int numbers[NUM_ITEMS] = {21, 99, 38, 22, 15, 6};

    printf("初期状態:\n");
    printArray(numbers, NUM_ITEMS);

    //perform insertion sort on array
    insertionSort(numbers, NUM_ITEMS);

    printf("ソート完了\n");
    printArray(numbers, NUM_ITEMS);

    return 0;
}


void insertionSort(int numbers[], int array_size)
{
    int i, j, count = 0;

    for (i=1; i < array_size; i++) {
        j = i;

        while ((j > 0) && (numbers[j-1] < numbers[j])) {
            count++;
            printf("比較%d回目：%dと%d\n", count, numbers[j-1], numbers[j]);

            swap(&numbers[j-1], &numbers[j]);
            j--;
        }
        if (j > 0){
            count++;
            printf("比較%d回目：%dと%d\n", count, numbers[j-1], numbers[j]);
        }
    }
}

/* 入れ替え用関数*/
void swap(int *p_from, int *p_to) {
    int tmp;
    tmp = *p_from;
    *p_from = *p_to;
    *p_to = tmp;
}

/* 数列出力用関数*/
void printArray(int numbers[], int array_size)
{
    int x;
    for (x = 0; x < array_size; x++) {
        printf("%d ", numbers[x]);
    }
    printf("\n");
}