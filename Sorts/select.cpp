#include <iostream>
#include <cmath>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
#define min(a,b) a < b ? a : b;
#define max(a,b) a > b ? a : b;

void print_array(int *arr, int n){
    std::cout << "array: ";
    for(int i=0; i<n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int *arr, int i, int j){
    if(i == j){
       return;
    }
     
    arr[j] = arr[i] + arr[j];
    arr[i] = arr[j] - arr[i];
    arr[j] = arr[j] - arr[i];
    return;
}

int partition(int *arr, int start, int end, int pivot){
    swap(arr, end, pivot);
    
    int store_index = start;
    for(int i=start; i<end; i++){
        if(arr[i] < arr[end]){
            swap(arr, store_index, i);
            store_index++;
        }
    }
    swap(arr, end, store_index);
    return store_index;
}

int quick_sort_select(int *arr, int start_index, int end_index, int k){
    if(end_index <= start_index){
        return arr[start_index];
    }

    int pivot_index = (start_index + end_index) / 2;
    int pivot_new_index = partition(arr, start_index, end_index, pivot_index);
    int relative_index = pivot_new_index - start_index + 1;

    if(relative_index == k){
        return arr[pivot_new_index];
    }
    
    if(relative_index > k){
        return quick_sort_select(arr, start_index, pivot_new_index - 1, k);
    }
    else{
        return quick_sort_select(arr, pivot_new_index + 1, end_index, k - relative_index);
    }
}

void quick_sort_firstk(int *arr, int start_index, int end_index, int k){
    if(end_index <= start_index){
        return;
    }

    int pivot_index = (start_index + end_index) / 2;
    int pivot_new_index = partition(arr, start_index, end_index, pivot_index);
    quick_sort_firstk(arr, start_index, pivot_new_index - 1, k);
    if(pivot_new_index - start_index + 1 < k){
        quick_sort_firstk(arr, pivot_new_index + 1, end_index, k - pivot_new_index + start_index - 1);
    } 
}


int main(){
    int arr[] = {9, 2, 3, 4, 7, 6, 5, 8, 1, 0};
    int n = sizeof(arr) / sizeof(int);
    
    print_array(arr, n);
    std::cout << quick_sort_select(arr, 0, n, 4) << std::endl;
    std::cout << quick_sort_select(arr, 0, n, 8) << std::endl;
    std::cout << quick_sort_select(arr, 0, n, 2) << std::endl;

    swap(arr, 2, 4);
    swap(arr, 6, n-1);
    print_array(arr, n);
    quick_sort_firstk(arr, 0, n, 6);
    print_array(arr, n);
    while(1){
        getchar();
    }
}
