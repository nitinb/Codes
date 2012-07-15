#include <iostream>

using namespace std;

int find_sequence(int *arr, int initial, int size, int sum){
    if(sum == 0){
        return 1;
    }

    if(initial == size || sum < 0){
        return 0;
    }

    int count1 = find_sequence(arr, initial + 1, size, sum);

    int count2 = 0;
    if(arr[initial] <= sum){
        count2 = find_sequence(arr, initial + 1, size, sum - arr[initial]);
    }

    return count1 + count2;
}

int main(){
    int arr[] = {10, 2, 3, 5};
    int size = sizeof(arr)/sizeof(int);
    int sum = 15;

    int num = find_sequence(arr, 0, size, sum);
    std::cout << num << std::endl;
}
