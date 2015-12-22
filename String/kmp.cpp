
#include <iostream>

using namespace std;

void build_lookup_table(std::string pattern, int *arr){
    if(pattern.length() <= 0){
        return;
    }
    arr[0] = -1;

    if(pattern.length() <= 1){
        return;
    }
    arr[1] = 0;

    for(int i = 2; i < pattern.length(); i++){
        arr[i] = 0;
        if(pattern[arr[i - 1]] == pattern[i - 1]){
            arr[i] = arr[i - 1] + 1;
        }
    }
}

void print_array(int *arr, int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int find_substring(std::string input, std::string pattern, int *arr){
    int index = 0, j = 0;

    while(index + j < input.length()){
        if(input[index + j] == pattern[j]){
            j++;
            if(j == pattern.length()){
                return index;
            }
        }
        else{
            index = index + j - arr[j];
            j = arr[j] == -1 ? 0 : arr[j];
        }
    }

    return input.length();
}

int main(){
    std::string input, pattern;
    std::cin >> input >> pattern;
    int arr[pattern.length()];

    build_lookup_table(pattern, arr);
    print_array(arr, pattern.length());

    int index = find_substring(input, pattern, arr);
    std::cout << "Pos => " << index << std::endl;
}
