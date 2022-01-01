#include <math.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int swap=0;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;

            swap++;
        }
        arr[j + 1] = key;
    }
}
 

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 

int main()
{
    int i, x[20000],n;

    clock_t start,end;
    double cpu_time_used;

	printf("Enter the number of Elements:");
    scanf("%d",&n);

    for(i=0; i<n; i++){
        x[i] = rand();
        printf("%d\t",x[i]);
    }

    start = clock();
    insertionSort(x, n);
    end = clock();

    printf("\n\nSorted Elements:\n", swap);
    for(i=0; i<n; i++){
        printf("%d\t",x[i]);
    }

    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("\n\nSwap number = %d\n", swap);
    printf("\nTime is %lf Seconds \n", cpu_time_used);
 
    return 0;
}