#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    std::vector<std::vector<int> > generate(int num_rows);
};

std::vector<std::vector<int> > Solution::generate(int num_rows) {
    std::vector<std::vector<int> > tri;
    if(num_rows >= 1) {
        std::vector<int> row;
        row.push_back(1);
        tri.push_back(row);
    }

    for(int i = 1; i < num_rows; i++) {
        std::vector<int> row;
        row.push_back(1);
        for(int j = 1; j < i; j++) {
           row.push_back(tri[i-1][j-1] + tri[i-1][j]);
        }
        row.push_back(1);
        tri.push_back(row);
    }
    return tri;
}

void print(std::vector<std::vector<int> > tri) {
    for(int i = 0; i < tri.size(); i++) {
        std::cout << "[";
        for(int j = 0; j < tri[i].size(); j++) {
            std::cout << tri[i][j] << ",";
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    Solution *sol = new Solution();
    int num_rows = 10;
    std::vector<std::vector<int> > tri = sol->generate(num_rows);
    print(tri);
}
    
    