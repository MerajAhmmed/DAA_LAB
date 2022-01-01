#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
int swap=0;

void BubbleSort(int *a, int n) {

    int i = 0, j = 0, tmp;
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) { 
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;

                swap++;
            }
        }
    }


    
}


int main()
{
    int x[20000];
    int n,i;
    clock_t start,end;
    double cpu_time_used;
    printf("enter the array input: \n");
    scanf("%d", &n);
    printf("array element are: \n");
    for(i = 0; i < n; i++)
    {
        x[i] = rand();
        printf("%d",x[i]);
    }
    start = clock();
    BubbleSort(x, n);
    end = clock();
    printf("Shorted array are:  ");
    for(i = 0; i < n; i++)
    {
        printf("%d\t",x[i]);
    }
    cpu_time_used = ((double)(end - start)/CLOCKS_PER_SEC);
    printf("\n Count of swap is : ", swap);
    printf("\nNedded time is : ",cpu_time_used);
    return 0;
}