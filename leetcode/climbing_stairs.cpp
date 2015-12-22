#include <iostream>

using namespace std;

class Solution {
public:
   int climbStairs(int n);
};

int Solution::climbStairs(int n) {
    int arr[n+1];
    arr[0] = 0, arr[1] = 1;
    if(n < 2) { return arr[n]; }

    arr[2] = 2;
    for(int i = 3; i <= n; i++) {
        arr[i] = arr[i-2] + arr[i-1];
    }
    return arr[n];
}

int main() {
    Solution *sol = new Solution();
    int key = 4;
    int num = sol->climbStairs(key);
    std::cout << num << std::endl;
}
    
    