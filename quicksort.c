#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int swap=0;

int QuickSort(int *array, int low, int high)

{

    int pivot, i, j, temp;

    if (low < high)

    {
        pivot = low;
        i = low;
        j = high;

        while (i < j) 
        {
            while (array[i] <= array[pivot] && i <= high){
                i++;
            }

            while (array[j] > array[pivot] && j >= low){
                j--;
            }
            if (i < j){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }

        }
        temp = array[j];
        array[j] = array[pivot];
        array[pivot] = temp;
        QuickSort(array, low, j - 1);
        QuickSort(array, j + 1, high);
    }

    swap++;
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
    QuickSort(x,0,n-1);
    end = clock();

    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;

     printf("\n\nSorted Elements:\n", swap);
    for(i=0; i<n; i++){
        printf("%d\t",x[i]);
    }

    
    printf("\n\nSwap number = %d\n", swap);
    printf("\n Time is %lf Seconds \n", cpu_time_used);

    return 0;
}