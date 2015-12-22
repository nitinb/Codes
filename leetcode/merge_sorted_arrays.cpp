#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n);
};

void Solution::merge(int A[], int m, int B[], int n) {
    if(n <= 0) { return; }

    int last = m + n - 1;
    n--; m--;
    while(n >= 0 && m >= 0) {
        if(A[m] >= B[n]) {
            A[last--] = A[m--];
        }
        else{
            A[last--] = B[n--];
        }
    }

    while(m >= 0) {
        A[last--] = A[m--];
    }
    while(n >= 0) {
        A[last--] = B[n--];
    }
}

void print_array(int *store, int size){
    for(int i = 0; i < size; i++){
        std::cout << store[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution *sol = new Solution();
    int A[] = {1, 2, 3, 6, 9, 0, 0};
    int B[] = {};

    sol->merge(A, 5, B, sizeof(B)/sizeof(int));
    print_array(A, sizeof(A)/sizeof(int));
}
