#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target);
};

int binary_search(int arr[], int start, int end, int key) {
    if(end < start) return -1;

    if(key <= arr[start]) return start;
    if(key == arr[end]) return end;
    if(key > arr[end]) return end+1;
    if(end - start == 1) return start+1;

    int mid = (start + end) / 2;
    if(key < arr[mid]) {
        return binary_search(arr, start, mid, key);
    }
    else if(key > arr[mid]){
        return binary_search(arr, mid, end, key);
    }
    else {
        return mid;
    }
}

int Solution::searchInsert(int A[], int n, int target) {
    return binary_search(A, 0, n-1, target);
}

int main() {
    Solution *sol = new Solution();
    int arr[] = {1, 3, 5};
    int key = 4;
    int num = sol->searchInsert(arr, sizeof(arr)/sizeof(int), key);
    std::cout << num << std::endl;
}
    
    