#include<iostream>
#include<map>
using namespace std;

  #define FOR(i, a, b) for(int i = a ; i < b ; i++)

  map<char, string> myMap;

  void init() {
      myMap[' ']="00000";
      myMap['A']="00001";
      myMap['B']="00010";
      myMap['C']="00011";
      myMap['D']="00100";
      myMap['E']="00101";
      myMap['F']="00110";
      myMap['G']="00111";
      myMap['H']="01000";
      myMap['I']="01001";
      myMap['J']="01010";
      myMap['K']="01011";
      myMap['L']="01100";
      myMap['M']="01101";
      myMap['N']="01110";
      myMap['O']="01111";
      myMap['P']="10000";
      myMap['Q']="10001";
      myMap['R']="10010";
      myMap['S']="10011";
      myMap['T']="10100";
      myMap['U']="10101";
      myMap['V']="10110";
      myMap['W']="10111";
      myMap['X']="11000";
      myMap['Y']="11001";
      myMap['Z']="11010";
}
  bool increment(int *mod, int *cR, int *cC, int *r1, int *c1, int *iR, int *iC) {
      int m=*mod;
      if(m==1) {
          if((*cC)<((*c1)-1)) {
              (*cC)++;
          } else if((*cR)<((*r1)-1)){
              (*cR)++;(*mod)=2;
              (*iR)++;
          } else {
              return false;
          }
      } else if(m==2) {
          if((*cR)<((*r1)-1)) {
              (*cR)++;
          } else if((*cC)>(*iC)) {
              (*cC)--;(*mod)=3;
              (*c1)--;
          } else {
              return false;
          }
      } else if(m==3) {
          if((*cC)>(*iC)) {
              (*cC)--;
          } else if((*cR)>(*iR)) {
              (*cR)--;(*mod)=4;
              (*r1)--;
          } else {
              return false;
          }
      } else if(m==4) {
          if((*cR)>(*iR)) {
              (*cR)--;
          } else if((*cC)<((*c1)-1)) {
              (*cC)++;*mod=1;
              (*iC)++;
          } else {
              return false;
          }
      }
      return true;
  }

  main() {
      int t,  r, c, m, curR, curC, inc, mod, r1, c1, iR, iC;
      bool b;
      char a[25][25];
      string s;
      char ch;
      init();
      scanf("%d",&t);
      FOR(i, 0, t) {
          scanf("%d%d",&r,&c);
          FOR(i1, 0, r) {
              FOR(j, 0 , c) {
                  a[i1][j]='0';
              }
          }
          getchar();
          m=1;inc=1;mod=1;
          curR=0;curC=0;r1=r;c1=c;
          b=true;
          iR=0;iC=0;
          while((ch=getchar())!=EOF) {
              if(ch=='\n') {
                  break;
              }
              s=myMap[ch];
              FOR(j, 0, 5) {
                  a[curR][curC]=s[j];
                  b=increment(&mod, &curR, &curC, &r1, &c1, &iR, &iC);
              }
          }
         cout<<i+1<<" ";
          FOR(i1, 0, r) {
              FOR(j, 0 , c) {
                  cout<<a[i1][j];
              }
          }
          cout<<endl;
      }
  }
