#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x);
};

int Solution::reverse(int x) {
    if(x == 0) return 0;
    int sign = x < 0 ? -1 : 1;

    int num = 0, divider = 10, rem;
    while(x != 0) {
        rem = x % divider;
        x = x / divider;
        num = num * 10 + rem;
    }
    return num;
}

int main() {
    Solution *sol = new Solution();
    int x = -100;
    int num = sol->reverse(x);
    std::cout << num << std::endl;
}
    
    