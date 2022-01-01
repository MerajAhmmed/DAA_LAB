#include <stdio.h>


int max(int a, int b) 
{
    return (a > b) ? a : b; 
}


int knapSack(int W, int wt[], int val[], int n)
{

    if (n == 0 || W == 0)
        return 0;


    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
      
       else
        return max(
                   val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
                   knapSack(W, wt, val, n - 1)
                  );
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50,i;
    int n = sizeof(val) / sizeof(val[0]);
    printf("S/N\tWeight\tProfit\n");
    for(i=0;i<n;i++)
    printf("%d\t%d\t%d\n",i+1,wt[i],val[i]);
    printf("The total profit = %d", knapSack(W, wt, val, n));
    return 0;
}