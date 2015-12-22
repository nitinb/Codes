#include <iostream>
#include <cmath>

using namespace std;

void remove_duplicates(int *arr, int n){
    int val;

    for(int i = 0; i < n; i++){
        val = abs(arr[i]);
        if(arr[val - 1] > 0){
            arr[val - 1] = -1 * arr[val - 1];
        }
        else{
            arr[i] = -(n+1);
        }
    }
}

void print_array(int *arr, int n){
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){

   int N;
   std::cin >> N;

   int arr[N];
   for(int i = 0; i < N; i++){
       std::cin >> arr[i];
   }

   remove_duplicates(arr, N);
   print_array(arr, N);
}
