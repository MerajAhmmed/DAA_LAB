#include<stdio.h>
#define INFINITY 999
#define MAX 100


void Dijkastra(int Graph[MAX][MAX], int n, int start);

void Dijkastra(int Graph[MAX][MAX], int n, int start){
    int Cost[MAX][MAX],Visited[MAX],Distance[MAX],Pre[MAX],count,nextnode,mindistance, i, j;


    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(Graph[i][j]  == 0){
            Cost[i][j] = INFINITY;
            }
            else{
                Cost[i][j] = Graph[i][j];
            }
        }
    }
    for(i = 0; i < n; i++){
        Distance[i] = Cost[start][i];
        Pre[i] = start;
        Visited[i] = 0;
    }
    Distance[start] = 0;
    Visited[start] = 1;
    count = 1;
    while(count < n - 1){
        mindistance = INFINITY;

        for(i = 0; i < n; i++){
            if(Distance[i] < mindistance && !Visited){
                mindistance = Distance[i];
                nextnode = i;
            }
        }
        Visited[nextnode] = i;
        for(i = 0; i < n; i++){
            if(!Visited){
                if(mindistance + Cost[nextnode][i] < Distance[i]){
                    Distance[i] = Cost[nextnode][i] + mindistance;
                    Pre[i] = nextnode;
                }
            }
        }
        
    }
    count++;
    for(i = 0; i < n; i++)
    {
        if(i != start){
        printf("\nDistance from source%d: %d", i, Distance[i]);
        }
    }



}


int main()
{
    int Graph[MAX][MAX];
    int u, n, i, j;
     printf("Enter The Nummber of node: ");
     scanf("%d", &n);
     printf("\nEnter The adajacncy matrix: \n ");
     for(i = 0; i < n; i++){
         for(j = 0; j < n; j++){
            scanf("%d",&Graph[i][j]);
         }
     }
     u = 0;
     Dijkastra(Graph, u, n);

     return 0;
}
