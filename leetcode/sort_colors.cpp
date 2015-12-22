#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(int A[], int n);
};


void print_array(int *store, int size){
    for(int i = 0; i < size; i++){
        std::cout << store[i] << " ";
    }
    std::cout << std::endl;
}


void Solution::sortColors(int A[], int n) {
    int i = 0, last_0 = -1, first_2 = n - 1;
    while(i < n) {
      if(A[i] == 0 && i - last_0 > 1) {
        A[i] = A[last_0 + 1];
        A[last_0 + 1] = 0;
        last_0++;
      }
      else if(A[i] == 2 && i < first_2) {
        A[i] = A[first_2];
        A[first_2] = 2;
        first_2--;
      }
      else {
        i++;
      }
    }
}


int main() {
    Solution *sol = new Solution();
    int num[] = {0, 0, 2, 1};

    sol->sortColors(num, sizeof(num) / sizeof(int));
    print_array(num, sizeof(num) / sizeof(int));
}