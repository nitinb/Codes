#include <iostream>

using namespace std;

void print_matrix(int *a, int rows, int cols){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      std::cout << *( a + i*cols + j) << " ";
    }
    std::cout << std::endl;
  }
}

void swap(int *mat, int i, int j, int n){
    int temp = *(mat + i*n + j);
    *(mat + i*n + j) = *(mat + j*n + i);
    *(mat + j*n + i) = temp;
}

void transpose(int *mat, int i, int j, int n){
    if(i >= n || j >= n || j > i){
        return;
    }

    transpose(mat, i + 1, j, n);
    swap(mat, i, j, n);
    transpose(mat, i, j + 1, n);
}

int main(){

    int n = 3;
    int mat[3][3] = { {1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9} };

    transpose(&mat[0][0], 0, 0, n);
    print_matrix(&mat[0][0], n, n);
}
