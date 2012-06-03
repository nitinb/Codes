#include<iostream>

using namespace std;

#define max(a, b) a > b ? a : b

int main(){
    int arr[] = {1, 3, 0, 2, -2, 19, 12, 10};
    int size = sizeof(arr) / sizeof(int);

    int maximum_sum = 0, sum1 = 0, sum2 = 0, current_sum = 0;
    sum1 = arr[0] >= 0 ? arr[0] : 0;
    sum2 = arr[1] >= 0 ? arr[1] : 0;

    for(int i = 2; i < size; i++){
        if(arr[i] <= 0){
            sum1 = max(sum1, sum2);
            sum2 = max(sum1, sum2);
            continue;
        }

        current_sum = arr[i] + sum1;
        if(current_sum > maximum_sum){
            maximum_sum = current_sum;
        }

        sum1 = sum2;
        sum2 = current_sum;
    }

    std::cout << maximum_sum << std::endl;
}
