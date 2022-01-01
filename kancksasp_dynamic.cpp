 #include<bits/stdc++.h>
#include<conio.h>

using namespace std;

int knapsack(int weight[], int val[], int maxWeight, int totalObjects){
    int i , j, a;
    int K[totalObjects+1][maxWeight+1]; //value table having totalObjects+1 rows and maxWeight+1 columns

    for(i=0;i<=totalObjects; i++){
        for(j=0; j<=maxWeight; j++){
            if(i == 0 || j == 0){
                K[i][j] = 0;
            }
            else if(weight[i] <= j){                //j means actually the capacity of the knapsack check if the weight is smaller than the capacity of the bag
                K[i][j] = max(val[i] + K[i-1][j-weight[i]], K[i-1][j]);
            }
            else{
                K[i][j] = K[i-1][j];
            }
            a = K[i][j];
        }
    }

    return a;

}

int main(){ 
    int val[] = {1,3,4,5,8}; 
    int weight[] = {2,3,1,4,5}, max_weight;

    cout << "Enter maximum size of the knapsack: ";
    cin >> max_weight;
    
    int no_of_objects = sizeof(val)/sizeof(val[0]);
    
    int max_profit = knapsack(weight, val, max_weight, no_of_objects);

    cout<<"\nMaximum value : " << max_profit<< endl;

    getch();
    
    
}