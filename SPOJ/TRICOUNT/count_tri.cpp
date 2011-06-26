#include <iostream>
#include <cmath>
#include <climits>
int main(){
    long long int N, n;
    unsigned long long int ans;
    
    std::cin >> N;
    for(long long int i=0; i<N; i++){
       std::cin >> n;
       ans = n*(n+2)*(2*n+1)/8;      
       std::cout << ans << std::endl;
    }
}
