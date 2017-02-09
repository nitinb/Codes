#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int count(int posx, int posy, int M, int N, bool **grid){
    if(posx < 0 || posx >= M || posy < 0 || posy >= N ||
       grid[posx][posy]){
        return 0;
    }

    grid[posx][posy] = true;
    int subtotal = count(posx, posy+1, M, N, grid);
    subtotal += count(posx, posy-1, M, N, grid);
    subtotal += count(posx+1, posy, M, N, grid);
    subtotal += count(posx-1, posy, M, N, grid);
    grid[posx][posy] = false;

    return subtotal;
}

int main(){
    int M, N, total = 0;
    std::cin >> M >> N;

    bool **grid;
    grid = (bool**)malloc(sizeof(char*)*M);
    for(int i = 0; i < M; i++){
        grid[i] = (bool*)malloc(sizeof(bool)*N);
    }


    total += count(0, 0, M, N, grid);

    std::cout << total / 4 << std::endl;
}
