#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    std::vector<int> grayCode(int n);
};

std::vector<int> Solution::grayCode(int n) {
    int _size, k = 0;
    std::vector<int> retval;

    retval.push_back(0);
    if(n == 0) { return retval; }

    if(n >= 1) {
        retval.push_back(1);
        k++;
    }

    while(k < n) {
        _size = retval.size();
        for(int i = _size - 1; i >= 0; i--) {
            retval.push_back(retval[i] + pow(2, k));
        }
        k++;
    }
    return retval;
}

void print(std::vector<int> tri) {
    for(int i = 0; i < tri.size(); i++) {
        std::cout << tri[i] << ",";
    }
    std::cout << std::endl;
}

int main() {
    Solution *sol = new Solution();
    int x = 3;

    std::vector<int> num = sol->grayCode(x);
    print(num);
}