/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * This program demonstrates the use of the selection sort algorithm.  For
 * more information about this and other sorting algorithms, see
 * http://linux.wku.edu/~lamonml/kb.html
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_ITEMS 6

void selectionSort(int numbers[], int array_size);
void printArray(int numbers[], int array_size);

int numbers[NUM_ITEMS] = {21, 99, 38, 22, 15, 6};

int main()
{
    int i;

    printf("初期状態\n");
    printArray(numbers, NUM_ITEMS);

    // perform selection sort on array
    selectionSort(numbers, NUM_ITEMS);

    printf("ソート完了\n");
    printArray(numbers, NUM_ITEMS);

    return 0;
}

void selectionSort(int numbers[], int array_size)
{
    int i; // 配列の先頭を指すインデックス
    int j; // 残りの要素を指すインデックス
    int min; // 最小値を持つ要素のインデックス
    int temp; // 交換用の一時変数
    int count = 0; //比較回数のカウンタ

    for (i = 0; i < array_size-1; i++) {
        min = i; // 配列の先頭を最小値の要素とする
        for (j = i + 1; j < array_size; j++) { // 比較のループ
            count++;
            printf("比較%d回目：%dと%d\n", count, numbers[j], numbers[min]);
            printArray(numbers, NUM_ITEMS);

            if (numbers[j] < numbers[min]) {
                min = j; // 最小値を持つ要素を更新
            }
        }

        if (min != i){
            printf("最小値%dと%d番目の要素%dを入れ替え\n", numbers[min], i, numbers[i]);
            printArray(numbers, NUM_ITEMS);

            // 最小値を持つ要素を先頭の要素と交換
            temp = numbers[i];
            numbers[i] = numbers[min];
            numbers[min] = temp;
        }
        else{
            printf("%d番目の要素%dが既に最小値であるため入れ替えなし\n", i, numbers[min]);
        }
    }
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