/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : heap.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Friday 13 May 2011 07:58:00 PM IST

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

struct node{
  public:
   int data;
   struct node *left ;
   struct node *right;
     node(){
        data = -1;
        left = right = NULL;
     }
};
/*
 * GLOBAL variable representing the root
 *  node of tree
 */
node * root = NULL;

for Min Heap : ---
insert
delMin
heapify
decreaseKey
merge

HeapSort
http://en.wikipedia.org/wiki/Selection_algorithm
http://en.wikipedia.org/wiki/Prim%27s_algorithm
http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

BinomialHeap
BinaryHeap

