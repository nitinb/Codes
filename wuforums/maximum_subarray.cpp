#include<iostream>

using namespace std;

int main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(int);
    int maximum_sum[3] = {0, -1, -1};
    int current_sum[3] = {0, 0, -1};

    for(int i = 0; i < size; i++){
        if(current_sum[0] < 0){
            current_sum[0] = 0;
            current_sum[1] = i;
            current_sum[2] = -1;
        }
        current_sum[0] += arr[i];
        if(current_sum[0] > maximum_sum[0]){
            maximum_sum[0] = current_sum[0];
            maximum_sum[1] = current_sum[1];
            maximum_sum[2] = i;
        }
    }

    std::cout << maximum_sum[0] << " start: " << maximum_sum[1] << " end: " << maximum_sum[2] << std::endl;
}
