#include <stdio.h>
#include<stdlib.h>
#include<time.h>  

int swap;

void selection(int arr[], int n)  
{  
    int i, j, small;  
        
    for (i = 0; i < n-1; i++)   
    {  
        small = i; 
            
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[small]){
               small = j; 

               swap++; 
            }  
        }  
         

        int temp = arr[small];  
        arr[small] = arr[i];  
        arr[i] = temp;  
        swap++;
    }  
}  
    
    
int main()  
{  int i, x[20000],n;

    clock_t start,end;
    double cpu_time_used;

    printf("Enter the number of Elements:");
    scanf("%d",&n);

    for(i=0; i<n; i++){
        x[i] = rand();
        printf("%d\t",x[i]);
    }

    start = clock();
    selection(x, n);
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