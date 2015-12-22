/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : queue.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Thursday 12 May 2011 02:12:04 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <cmath>

/*STL *algorithm* */
#include <queue>
#include <list>
#include <vector>
#include <map>

#define DEBUG 1

int main(){
   std::queue<int> Q; // empty queue of type int

   for (int i = 1; i <= 10; i++) { Q.push(i); }
   std::cout << " size of Queue: " << Q.size() << std::endl;

   while( !Q.empty() ){
      std::cout << Q.front() << "  ";
      Q.pop();
   }
   std::cout << std::endl << " size of Queue: " << Q.size() << std::endl;
}
