/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : stack.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Tuesday 12 July 2011 01:48:21 PM IST

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

#define DEBUG 1

int main(){

   std::stack<int> S; // empty stack of type int

   for (int i = 1; i <= 10; i++) { S.push(i); }
   std::cout << " size of stack: " << S.size() << std::endl;

   while( !S.empty() ){
      std::cout << S.top() << "  ";
      S.pop();
   }
   std::cout << std::endl << " size of stack: " << S.size() << std::endl;


}
