#include <iostream>
int main(){
    int N, n;
    long long unsigned int ans;
    
    std::cin >> N;
    for(int i=0; i<N; i++){
       std::cin >> n;
       ans = n*(n+2)*(2*n+1)/8;
       std::cout << ans << std::endl;
    }
}
