#include <iostream>
using namespace std;

int kadane(int arr[], int n){
    int current_sum = 0;
    int best_sum = 0;

    for(int i = 0; i < n; i++){
        current_sum = current_sum + arr[i];
        if(best_sum < current_sum){
            best_sum = current_sum;
        }

        if(current_sum < 0){
            current_sum = 0;
        }
    }
    return best_sum;
}

int main(){
   int n;
   int arr[100];

   cin >> n;
   for(int i = 0; i < n; i++){
       cin >> arr[i];
   }

   int sum = kadane(arr, n);
   cout << sum << endl;
}