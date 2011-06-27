/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : goal.cpp

* Purpose :

* Creation Date : 12-05-2011

* Last Modified : Monday 27 June 2011 03:12:08 PM IST

* Created By : Nitin

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstdio>
#include <iomanip>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 0
#define MAX_SIZE 10000

int main(){
    long long int N;
    float ball_x, ball_y, goal_x, goal_y, rad, dist, temp;
    
    scanf("%lld",&N);
    for(long long int i=0; i<N; i++){
        scanf("%f %f", &ball_x, &ball_y);
        scanf("%f %f %f", &goal_x, &goal_y, &rad);
        
        dist = (ball_y-3.66)*goal_x + (52.5-ball_x)*goal_y + (3.66-ball_y)*ball_x - (52.5-ball_x)*ball_y;
        temp = (ball_y-3.66)*(ball_y-3.66) + (ball_x-52.5)*(ball_x-52.5);
        temp = sqrt(temp);
        if( temp == 0){ printf("Goal!\n"); continue; }
        else{
             dist = dist/temp;
             if(dist>rad){ printf("Goal!\n"); continue; }
        }
        
        dist = (ball_y+3.66)*goal_x + (52.5-ball_x)*goal_y + (-3.66-ball_y)*ball_x - (52.5-ball_x)*ball_y;
        temp = (ball_y+3.66)*(ball_y+3.66) + (ball_x-52.5)*(ball_x-52.5);
        temp = sqrt(temp);
        if( temp == 0){ printf("Goal!\n"); continue; }
        else{
             dist = dist/temp;
             if(dist>rad){ printf("Goal!\n"); continue; }
        }
        printf("No goal...\n");
    }
}
