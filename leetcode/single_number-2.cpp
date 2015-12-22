#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n);
    int singleNumber2(int A[], int n);
};

// TODO
int Solution::singleNumber2(int arr[], int n) {
    int bit_sum[64] = {0};
    for(int i = 0; i < n; i++) {
        int x = arr[i];
        for(int bit_num = 0; bit_num < 64; bit_num++) {
            if(x & 1) {
                bit_sum[bit_num]++;
            }
            x >>= 1;
        }
    }

    int retval = 0;
    for(int i = 0; i < 64; i++) {
        retval = retval | (bit_sum[i] % 3 << i);
    }
    return retval;
}

int Solution::singleNumber(int arr[], int n) {
    int bit_sum[64] = {0};
    for(int i = 0; i < n; i++) {
        int x = arr[i];
        for(int bit_num = 0; bit_num < 64; bit_num++) {
            if((x >> bit_num) & 1) {
                bit_sum[bit_num]++;
            }
        }
    }

    int retval = 0;
    for(int i = 0; i < 64; i++) {
        retval = retval | (bit_sum[i] % 3 << i);
    }
    return retval;
}

int main() {
    Solution *sol = new Solution();
    int arr[] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
    int num = sol->singleNumber(arr, sizeof(arr)/sizeof(int));
    std::cout << num << std::endl;
}
    
    