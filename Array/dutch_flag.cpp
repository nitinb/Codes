#include <iostream>

using namespace std;

void print_array(int *store, int size){
    for(int i = 0; i < size; i++){
        std::cout << store[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int *input, int a, int b){
    if(a == b){
        return;
    }

    input[a] = input[a] + input[b];
    input[b] = input[a] - input[b];
    input[a] = input[a] - input[b];
}

void arrange(int *input, int size){
    int ptr0 = 0, ptr1 = 0, ptr2 = size - 1;

    // input[0..ptr0-1]=0, input[ptr0...ptr1-1]=1, input[ptr2+1...size]=2
    // input[ptr1..ptr2] part not processed
    while(ptr2 > ptr1){
        if(input[ptr2] == 2){
            ptr2--;
        }

        switch(input[ptr1]){
            case 0:
                swap(input, ptr1, ptr0);
                ptr0++;
                ptr1++;
                break;
            case 1:
                ptr1++;
                break;
            case 2:
                swap(input, ptr1, ptr2);
                ptr2--;
                break;
        }
    }
}

int main(){
    int size;
    std::cout << "Size of array: ";
    std::cin >> size;

    int input[size];
    for(int i = 0; i < size; i++){
        std::cin >> input[i];
    }
    print_array(input, size);

    arrange(input, size);
    print_array(input, size);
}
