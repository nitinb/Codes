#include <iostream>

using namespace std;

int main(){

    int N, D, prime, total = 0, sum = 1;
    std::cin >> N >> D;
    // Calculate Divisor of N!/D

    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int SIZE = sizeof(primes) / sizeof(int);

    for(int i = 0; i < SIZE && primes[i] <= N; i++){
        prime = primes[i];
        total = 0;

        for(int j = N / prime; j >= 1; j = j / prime){
            total = total + j;
        }

        while(D % prime == 0){
            D = D / prime;
            total--;
        }

        if(total < 0){
            total = 0;
        }
        else{
            sum = sum * (total + 1);
        }
    }

    // N!/D is a fraction
    if(D > 1){
        sum = 0;
    }

    std::cout << "Divisors = " << sum << std::endl;
}
