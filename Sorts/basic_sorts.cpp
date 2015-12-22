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

void selection_sort(int *arr, int n){
    int temp, index; 
     
    for(int i=0; i<n; i++){
        temp = arr[i];
        index = i;    
        for(int j=i; j<n; j++){
            if(arr[j] < temp){
                temp = arr[j];
                index = j;
            }
        }
        swap(arr, i, index);
    }     
}

void bubble_sort(int *arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
}

void merge(int *arr, int start1, int end1, int start2, int end2, int *aux){
    int p1 = start1, p2 = start2;
    int last_pos = start1;
    
    while(p1 <= end1 && p2 <= end2){
        if(arr[p1] <= arr[p2]){
            aux[last_pos++] = arr[p1++];
        }
        else{
            aux[last_pos++] = arr[p2++];   
        }
    }
    
     while(p2 <= end2){
         aux[last_pos++] = arr[p2++];
     }
    
     while(p1 <= end1){
         aux[last_pos++] = arr[p1++];
     }
     
     int num = end2 - start1 + 1;
     for(int j=0; j<num; j++, end2--){
         arr[end2] = aux[end2];
     }
}

void merge_sort(int *arr, int start_index, int last_index, int *aux){
    if(last_index <= start_index){
        return;
    }
    
    merge_sort(arr, start_index, (start_index+last_index) / 2, aux);
    merge_sort(arr, (start_index+last_index) / 2 + 1, last_index, aux);
    
    merge(arr, start_index, (start_index+last_index) / 2, (start_index+last_index) / 2 + 1, last_index, aux);
}

void counting_sort(int *arr, int n, int *output){
    int max_value = 0; 
    for(int i=0; i<n; i++){
        if(max_value < arr[i]){
            max_value = arr[i];
        }
    }
    max_value++;
     
    int count[max_value];
    for(int i=0; i<max_value; i++){
        count[i] = 0;
    }
    
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }
    
    int index = 0;
    for(int i=0; i<max_value; i++){
        while(count[i] > 0){
            output[index++] = i;      
            count[i]--;
        }
        
        if(index == n){
            break;
        }
    }
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

void quick_sort(int *arr, int start_index, int end_index){
    if(end_index <= start_index){
        return;
    }

    int pivot_index = (start_index + end_index) / 2;
    int pivot_new_index = partition(arr, start_index, end_index, pivot_index);

    quick_sort(arr, start_index, pivot_new_index - 1);
    quick_sort(arr, pivot_new_index + 1, end_index);
}

int main(){
    int arr[] = {9, 2, 3, 4, 7, 6, 5, 8, 1, 0};
    int n = sizeof(arr) / sizeof(int);
    int aux[n];
   
    merge_sort(arr, 0, n, aux);
    print_array(aux, n);
    std::cout << "merge sort done" << std::endl;
    
    swap(arr, 0, n-1);
    selection_sort(arr, n);
    print_array(arr, n);
    std::cout << "selection sort done" << std::endl;
    
    swap(arr, 0, n-1);
    bubble_sort(arr, n);
    print_array(arr, n);
    std::cout << "bubble sort done" << std::endl;
            
    int input[] = {1, 2, 3, 2, 9, 9, 4, 4, 6, 5, 1, 2};
    n = sizeof(input) / sizeof(int);
    int output[n];
    counting_sort(input, n, output);
    print_array(output, n);
    std::cout << "counting sort done" << std::endl;
    
    quick_sort(input, 0, n);
    print_array(input, n);
    std::cout << "quick sort done" << std::endl;
        
    while(1){
        getchar();
    }
}
