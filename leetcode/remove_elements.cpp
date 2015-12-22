#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem);
};

int Solution::removeElement(int A[], int n, int elem) {
    int last = n - 1, i = 0;
    while(i <= last) {
        if(A[i] == elem) {
            A[i] = A[last];
            last--;
        }
        else{
            i++;
        }
    }
    return last + 1;
}

int main() {
    Solution *sol = new Solution();
    int arr[] = {1, 3, 1};
    int key = 1;
    int num = sol->removeElement(arr, sizeof(arr)/sizeof(int), key);
    std::cout << num << std::endl;
}
    
    