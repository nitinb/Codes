#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n);
};

int Solution::removeDuplicates(int A[], int n) {
    if (n == 0) { return 0; }
    int i = 0, back = 0;
    while(i < n) {
        if(A[back] != A[i]) {
            back++;
            A[back] = A[i];
        }
        i++;
    }
    return back+1;
}

int main() {
    Solution *sol = new Solution();
    int arr[] = {};

    int num = sol->removeDuplicates(arr, sizeof(arr)/sizeof(int));
    std::cout << num << std::endl;
}
    
    