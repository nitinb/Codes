/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : FeeLuck.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 16 May 2011 06:36:08 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0
#define MAX_SIZE 100

int main(){
    int A, rel;
    std::string url;
    
    std::cin >> A;
    for(int i=0; i<A; i++){
       std::map<int,std::string> data;
       std::map<int,int> count;
       
       for(int j=0; j<10; j++){
          std::cin >> url >> rel;
          if(count.find(rel) == count.end()){
             count[rel]=1;
          }else{
             count[rel] += 1;
          }   
          data[rel*MAX_SIZE-count[rel]]=url;
       }
       
       std::map<int,std::string>::reverse_iterator it = data.rbegin();
       int temp = (*it).first/MAX_SIZE;
       std::cout << "Case #"<< i+1 << ":" << std::endl;
       for(; it != data.rend(); it++){
           if( (*it).first/MAX_SIZE == temp){
              std::cout << (*it).second << std::endl;
           }
           else{
              break;
           }
       }
    }
}
