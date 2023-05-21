/* 右のサイトのソースコードを改変しました．https://www.codereading.com/algo_and_ds/algo/source/bubble_sort.c */
/* ライセンスについては，右のサイトに従います． https://www.codereading.com/copyright.html */

#include <stdio.h>

#define NUM_ITEMS 6

void bubbleSort(int numbers[], int array_size);

void printArray(int numbers[], int array_size);


int main()
{
  int numbers[NUM_ITEMS] = {21,99,38,22,15,6};

  printf("以下の配列のソートを行います．\n");
  printArray(numbers, NUM_ITEMS);
  printf("\n");

  //perform bubble sort on array
  bubbleSort(numbers, NUM_ITEMS);

  printf("ソート完了\n");
  printArray(numbers, NUM_ITEMS);
  printf("\n");

  return 0;
}


void bubbleSort(int numbers[], int array_size)
{
  int i, j, temp, count;

  count = 0;

  for (i = 0; i < (array_size - 1) ; i++) {
    for (j = 0; j < array_size - 1 - i; j++) {
      count++;
      printf("比較%d回目: %d and %d\n", count, numbers[j], numbers[j+1]);
      if (numbers[j+1] < numbers[j]) {
        temp = numbers[j+1];
        numbers[j+1] = numbers[j];
        numbers[j] = temp;

        printf("\t入れ替え発生: ");
        printArray(numbers, array_size);
        printf("\n");
      }
    }
    printArray(numbers, array_size);
    printf("\n");
  }
}

/* 数列出力用関数*/
void printArray(int numbers[], int array_size)
{
    int x;
    for (x = 0; x < array_size; x++) {
        printf("%d ", numbers[x]);
    }
}