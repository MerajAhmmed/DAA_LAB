#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int swap;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];



	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;

            swap++;
		}
		else {
			arr[k] = R[j];
			j++;

            swap++;
		}
		k++;
	}

	
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;

        swap++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;

        swap++;
	}

}


void mergeSort(int arr[], int l, int r)
{
	if (l < r) {

		int m = l + (r - l) / 2;

    
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
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


	int arr_size = n / sizeof(x[0]);

	printf("Given array is \n");
    for(i=0; i<n; i++){
        printf("%d\t",x[i]);
    }

	
    start = clock();
    mergeSort(x, 0, n - 1);
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
