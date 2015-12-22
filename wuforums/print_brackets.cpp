#include <iostream>

using namespace std;

void print_brackets(int num, int open_brackets, int closed_brackets,
                    std::string output){
    if(closed_brackets == num){
        std::cout << output << std::endl;
        return;
    }

    if(open_brackets < num){
        print_brackets(num, open_brackets + 1, closed_brackets, output+"(");
    }

    if(closed_brackets < open_brackets){
        print_brackets(num, open_brackets, closed_brackets + 1, output+")");
    }
}

int main(){
    int num;
    std::cin >> num;

    print_brackets(num, 0, 0, "");
}
