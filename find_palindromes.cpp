/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : find_palindromes.cpp

* Purpose :

* Creation Date : 06-04-2011

* Last Modified : Tuesday 10 May 2011 06:21:26 PM IST

* Created By : Nitin 

_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
 
struct pair {
  char c;
  int first;
  int last;
  int num_inner_pairs;
  struct pair * * inner_pairs;
};
 
void add_to_inner(struct pair * outer, struct pair * inner) {
  struct pair * * temp;
  int i;
 
  temp = (struct pair * *)malloc((outer->num_inner_pairs + 1) * sizeof(struct pair *));
  for(i = 0; i < outer->num_inner_pairs; i++) {
    temp[i] = outer->inner_pairs[i];
  }
  if (outer->num_inner_pairs > 0) {
    free(outer->inner_pairs);
  }
  temp[outer->num_inner_pairs++] = inner;
  outer->inner_pairs = temp;
}

void print_ds(struct pair *root){
  std::cout << root->first << " --- " << root->last << " *** " << root->c <<  " xxx " << root->num_inner_pairs << std::endl;

  struct pair * temp;
  for(int i = 0; i < root->num_inner_pairs; i++){
    temp = root->inner_pairs[i];    
    std::cout << temp->first << " ''' " << temp->last << " ``` " << temp->c << " ^^^ " << temp->num_inner_pairs << std::endl;

    if(temp->num_inner_pairs){
      temp = temp->inner_pairs[0];
      std::cout << temp->first << " ''' " << temp->last << " ``` " << temp->c << std::endl;
    }
    else
      std::cout << "No second lvl of branching" << std::endl;
  }
}

 
void print_palindromes(const struct pair * p, char * pre){
  int i;
 
  printf("%s", pre); putc(p->c, stdout);
  if (p->first < p->last) { // Ignoring the equality ones
    putc(p->c, stdout);
  }
  for(i = strlen(pre); i > 0; i--) putc(pre[i-1], stdout);
  printf("\n");
  pre[strlen(pre)] = p->c;
  for(i = 0; i < p->num_inner_pairs; i++) {
    print_palindromes(p->inner_pairs[i], pre);
  }
  pre[strlen(pre) - 1] = 0;
}
 
int main(int argc, const char ** argv) {
  int i, j, k;
  struct pair g, * p;
  char * buf;
 
  if (argc != 2) {
    fprintf(stderr, "usage: %s string\n", argv[0]);
    return -1;
  }
 
  g.first = -1;
  g.last = strlen(argv[1]);
  g.num_inner_pairs = 0;
 
  for(i = 0; i < strlen(argv[1]); i++) {
    for(j = i; j < strlen(argv[1]); j++) {
      if (argv[1][i] == argv[1][j]) {
        struct pair * p = (struct pair *)malloc(sizeof(struct pair));
        p->c = argv[1][i];
        p->first = i;
        p->last = j;
        p->num_inner_pairs = 0;
        for(k = 0; k < g.num_inner_pairs; k++) {
          if (g.inner_pairs[k]->first < i && j < g.inner_pairs[k]->last) {
            add_to_inner(g.inner_pairs[k], p);
          }
        }
        add_to_inner(&g, p);
      }
    }
  }

  /*
   *  print complete DS
   */
//  print_ds(&g);
 
  buf = (char *)malloc(strlen(argv[1]) + 1);
  memset(buf, 0, strlen(argv[1]) + 1);
 
  for(k = 0; k < g.num_inner_pairs; k++) {
    if (g.inner_pairs[k]->first < g.inner_pairs[k]->last) { // To avoid 1-Len palindrome
      print_palindromes(g.inner_pairs[k], buf);
    }
  }

  /*
   *  Free Memory
   */ 
  for(k = 0; k < g.num_inner_pairs; k++) {
    if (g.inner_pairs[k]->num_inner_pairs > 0) {
      free(g.inner_pairs[k]->inner_pairs);
    }
    free(g.inner_pairs[k]);
  }
  free(g.inner_pairs);
  free(buf);
 
  return 0;
}
