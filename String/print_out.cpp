#include <iostream>

using namespace std;

void output(std::string out, int size){
    if (size <= 0) {
        return;
    }

    if (out.length() == 0) {
        out = "1";
    }

    if (out.length() == size) {
        std::cout << out << ", ";
        return;
    }

    char ch = out[out.length() - 1];
    char ch2 = ch - 1;
    if (ch2 != '0') {
        output(out + ch2, size);
    }

    output(out + ch, size);

    ch2 = ch + 1;
    output(out + ch2, size);
}

int main(){
   int n = 1;
   output("", n);
   std::cout << std::endl;

   n = 2;
   output("", n);
   std::cout << std::endl;

   n = 3;
   output("", n);
   std::cout << std::endl;

   n = 4;
   output("", n);
   std::cout << std::endl;
}
