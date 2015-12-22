#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n);
    int singleNumber2(int A[], int n);
};

int Solution::singleNumber(int A[], int n) {
    int retval = 0;
    for(int i = 0; i < n; i++) {
        retval = retval ^ A[i];
    }
    return retval;
}


int Solution::singleNumber2(int A[], int n) {
    std::map <int, bool> cache;
    for(int i = 0; i < n; i++) {
        if(cache.find(A[i]) == cache.end()){
            cache[A[i]] = true;
        }
        else{
            cache[A[i]] = !cache[A[i]];
        }
    }
    
    for(std::map<int, bool>::iterator it = cache.begin(); it != cache.end(); it++) {
        if(it->second == true) {
            return it->first;
        }
    }
    return -100000;
}

int main() {
    Solution *sol = new Solution();
    int arr[] = {2, 0, 0};
    int num = sol->singleNumber(arr, sizeof(arr)/sizeof(int));
    std::cout << num << std::endl;
}
    
    