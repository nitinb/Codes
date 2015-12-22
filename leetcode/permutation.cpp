#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    std::vector<std::vector<int> > permute(std::vector<int> &num);
};

void print_vector(std::vector<int> gray_codes){
  std::vector<int>::iterator it;
  for(it = gray_codes.begin(); it != gray_codes.end(); it++){
     std::cout << *it << " ";
  }
  std::cout << "\n";
}

void swap(std::vector<int> &num, int i, int j) {
    int temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}

std::vector<std::vector<int> > _permute(std::vector<int> num, int start) {
    std::vector<std::vector<int> > perms;
    if(start == num.size()) {
        print_vector(num);
        return perms;
    }

    for(int i = start; i < num.size(); i++) {
        swap(num, i, start);
        _permute(num, i+1);
        swap(num, i, start);
    }
    return perms;
}

std::vector<std::vector<int> > Solution::permute(std::vector<int> &num) {
    return _permute(num, 0);
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
    std::vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);

    sol->permute(num);
}