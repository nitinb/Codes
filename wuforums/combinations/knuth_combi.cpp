#include<iostream>

using namespace std;

void printAllSubsets(int* arr, unsigned int n, unsigned int k) {
  // sanity check
  if (k == 0 || k > n) return;

  // current subset is given by array of indexes
  unsigned int *idx = new unsigned int[k];
  for(int i = 0; i < k; i++) idx[i] = i;

  // loop through all subsets
  for( ; ; ) {
    // print current subset
    for(int i = 0; i < k; i++) cout << (i > 0 ? "," : "") << arr[idx[i]];
    cout << endl;

    // check for termination
    if (idx[0] == n - k) break;

    // advance to next subset
    for(int i = 0; i < k; i++) {
      // if idx[i] has room to increment
      if (i + 1 == k || idx[i] + 1 < idx[i+1]) {
        // increment index and stop here
        idx[i]++;
        break;
      } else {
        // otherwise reset index
        idx[i] = i;
      }
    }
  }

  // clean up
  delete[] idx;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    printAllSubsets(arr, 5, 3);
}
