/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : levenshtein_distance.cpp

* Purpose :

* Creation Date : 11-05-2011

* Last Modified : Tuesday 19 July 2011 05:09:02 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>

int min(int a, int b, int c){
  return a <= b ? ( a <= c ? a : c ) : ( b <= c ? b : c);
}


void print_matrix(int *a, int rows, int cols){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      std::cout << *( a + i*cols + j) << " ";
    }
    std::cout << std::endl;
  }
}


int levenshtein_dist(std::string src, std::string dest){
  int src_len  = src.length();
  int dest_len = dest.length();

  int dist[src_len+1][dest_len+1];

  for(int i = 0; i <= src_len; i++) { dist[i][0] = i; }
  for(int j = 0; j <= dest_len; j++){ dist[0][j] = j; }

  for(int i = 1; i <= src_len; i++){
    for(int j = 1; j <= dest_len; j++){
       if(src[i-1] == dest[j-1]){
         dist[i][j] = dist[i-1][j-1];
       }
       else{
         dist[i][j] = min(dist[i-1][j] + 1, dist[i][j-1] + 1, dist[i-1][j-1] + 1);
       }
    }
  }

  print_matrix(&dist[0][0], src_len+1, dest_len+1);
  return dist[src_len][dest_len]; 
}


int main(){
  std::string src  = "sitting";
  std::string dest = "kitten";

  int dist = levenshtein_dist(src, dest);
  std::cout << "final res: " << dist << std::endl;
}
