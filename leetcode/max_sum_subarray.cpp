#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n);
};

int Solution::maxSubArray(int arr[], int n) {
    if(n == 0){ return -100000; }

    int sum = arr[0], current_sum = arr[0];
    int end = 0, start = 0, _temp = 0;
    for(int i = 1; i < n; i++) {
        if(current_sum < 0) {
            current_sum = 0;
            _temp = i;
        }
        current_sum += arr[i];

        if(current_sum > sum) {
            sum = current_sum;
            start = _temp;
            end = i;
        }
    }

    return sum;
}

int main() {
    Solution *sol = new Solution();
    int arr[] = {-1, -3, 5};

    int num = sol->maxSubArray(arr, sizeof(arr)/sizeof(int));
    std::cout << num << std::endl;
}
