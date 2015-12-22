#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n);
};

int Solution::uniquePaths(int m, int n) {
    if(m == 0 || n == 0) {
        return 0;
    }

    int arr[m][n];
    for(int i = 0; i < m; i++) {
        arr[i][0] = 1;
    }

    for(int i = 0; i < n; i++) {
        arr[0][i] = 1;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    return arr[m-1][n-1];
}

int main() {
    Solution *sol = new Solution();
    int m = 2, n = 3;

    int num = sol->uniquePaths(m, n);
    std::cout << num << std::endl;
}
    
    