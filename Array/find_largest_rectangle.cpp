#include <iostream>

using namespace std;

#define max(a, b) a > b ? a : b

struct rect{
    public:
        int width;
        int height;
        rect(){
            width = 0;
            height = 0;
        }
};

void print_array(int *input, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << *(input + m*i + j) << " ";
        }
       std::cout << std::endl;
    }
    std::cout << std::endl;
}

void find_largest_rectangle(int *input, int n, int m){
    rect store[n][m];
    int max_area = 0;

    if(*input == 1){
       store[0][0].width = 1;
       store[0][0].height = 1;
       max_area = 1;
    }

    for(int i = 1; i < n; i++){
        int j = 0;
        if(*(input + i * m + j) == 1){
            store[i][j].height = store[i - 1][j].height + 1;
            store[i][j].width = 1;
            if(store[i][j].width * store[i][j].height > max_area){
                max_area = store[i][j].width * store[i][j].height;
            }
        }
    }

    for(int j = 1; j < n; j++){
        int i = 0;
        if(*(input + i * m + j) == 1){
            store[i][j].width = store[i][j - 1].width + 1;
            store[i][j].height = 1;
            if(store[i][j].width * store[i][j].height > max_area){
                max_area = store[i][j].width * store[i][j].height;
            }
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(*(input + i * m + j) == 1){
                if((*(input + (i - 1) * m + j) == 0) && (*(input + i * m + j - 1) == 0)){
                    store[i][j].width = 1;
                    store[i][j].height = 1;
                }
                else if(*(input + (i - 1) * m + j) == 0){
                    store[i][j].width = store[i][j - 1].width + 1;
                    store[i][j].height = 1;
                }
                else if(*(input + i * m + j - 1) == 0){
                    store[i][j].height = store[i - 1][j].height + 1;
                    store[i][j].width = 1;
                }
                else{
                    store[i][j].width = min(store[i][j - 1].width + 1, store[i - 1][j].width);
                    store[i][j].height = min(store[i][j - 1].height, store[i - 1][j].height + 1);
                }

                if(store[i][j].width * store[i][j].height > max_area){
                    max_area = store[i][j].width * store[i][j].height;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << "(" << store[i][j].width << "," << store[i][j].height << ")";
        }
       std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << max_area << std::endl;
}

int main(){

    int n, m;
    std::cin >> n >> m;

    int input[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> input[i][j];
        }
    }

   print_array(&input[0][0], n, m);

   find_largest_rectangle(&input[0][0], n, m);
}
