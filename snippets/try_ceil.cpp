/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : try_ceil.cpp

* Purpose :

* Creation Date : 01-07-2011

* Last Modified : Friday 01 July 2011 12:08:25 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

/*STL *algorithm* */
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1

int main(){

  int d1 = ceil(2.3);
  int d2 = ceil(7.0/3);
  int d3 = ceil(7/3);

  std::cout << d1 << " " << d2 << " " << d3 << std::endl;
}
