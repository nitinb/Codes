#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int count(char**field,  char*word, int posx, int posy, int M, int N,
          bool **grid){
    if(*word == '\0'){
        return 1;
    }

    if(posx < 0 || posx >= M || posy < 0 || posy >= N ||
       grid[posx][posy] || field[posx][posy] != *word){
        return 0;
    }

    grid[posx][posy] = true;
    int subtotal = count(field, word+1, posx, posy+1, M, N, grid);
    subtotal += count(field, word+1, posx, posy-1, M, N, grid);
    subtotal += count(field, word+1, posx+1, posy, M, N, grid);
    subtotal += count(field, word+1, posx-1, posy, M, N, grid);
    grid[posx][posy] = false;

    return subtotal;
}

int main(){
    int M, N;
    std::cin >> M >> N;

    char **field;
    field = (char**)malloc(sizeof(char*)*M);
    for(int i = 0; i < M; i++){
        field[i] = (char*)malloc(sizeof(char)*(N+1));
    }

    bool **grid;
    grid = (bool**)malloc(sizeof(char*)*M);
    for(int i = 0; i < M; i++){
        grid[i] = (bool*)malloc(sizeof(bool)*N);
    }

    // Read field
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            std::cin >> field[i][j];
        }
        field[i][N] = '\0';
    }

    // Read word to search
    char word[M+1];
    std::cin >> word;
    word[M+1] = '\0';

    int total = 0;
    for(int x = 0; x < M; x++){
        for(int y = 0; y < N; y++){
            total += count(field, word, x, y, M, N, grid);
        }
    }

    std::cout << total / 4 << std::endl;
    // Free memory
}
