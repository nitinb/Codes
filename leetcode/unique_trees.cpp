#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int numTrees(int n);
};

int Solution::numTrees(int n) {
    long long unsigned int num = 1, den = 1;
    for(int i = n+2; i <= 2*n; i++) {
        num *= i;
    }

    for(int i = 1; i <= n; i++) {
        den *= i;
    }

    return num / den;
}


// 2n!/ (n+1)! n!
int main() {
    Solution *sol = new Solution();
    int x = 17;

    int num = sol->numTrees(x);
    std::cout << num << std::endl;
}