/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : set.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Thursday 12 May 2011 02:20:58 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1

int main(){
   std::set<int> S; // empty queue of type int

   for (int i = 1; i <= 10; i++) { S.insert(i); }
   std::cout << " size of set: " << S.size() << std::endl;

   while( !S.empty() ){
      std::cout << *S.begin() << "  ";
      S.erase(S.begin());
   }
   std::cout << std::endl << " size of set: " << S.size() << std::endl;

   S.insert(1);
   S.insert(11);
   std::cout << " size of set: " << S.size() << std::endl;
   S.clear();
   std::cout << " size of set: " << S.size() << std::endl;

}
