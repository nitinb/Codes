#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
string c_s(string num1, string num2){
string o_p;
char ch;

int len1, len2, carry, sum, p1, p2;
len1=num1.length(); len2=num2.length();
carry=0;
while( len1 > 0 || len2 > 0 ){
p1=len1 > 0 && (num1[len1-1] !=' ')? num1[len1-1] - '0' : 0;
p2=len2 > 0 && (num2[len2-1] !=' ')? num2[len2-1] - '0' : 0;

sum=carry + p1 + p2;
carry=sum/10;
ch=sum%10+'0';
o_p=ch + o_p;
len1--; len2--;
}
if(carry > 0){
ch=carry + '0';
o_p=ch + o_p;
}
return o_p;
}

string c_s_pdt(std::vector<string> p_m){
string o_p;
while(p_m.size() > 1){
o_p=c_s(p_m[0], p_m[1]);
p_m[1]=o_p;
p_m.erase(p_m.begin(), p_m.begin()+1);
}
return p_m[0];
}

string c_m(string num1, string num2){
string o_p;
vector<string> p_m;
map<int, string> m_m;
char ch;

int len1, len2, carry, mult, p1, p2, count;
len1=num1.length(); len2=num2.length();
count=0;
m_m[0]='0';

while(len2 > 0 ){
o_p=""; carry=0;
p2=num2[len2-1] - '0';

if(m_m.find(p2) !=m_m.end()){
 o_p=m_m[p2];
}
else{
 len1=num1.length();
 while(len1 > 0){
p1=num1[len1-1] - '0'; 
mult=carry + p1*p2;
carry=mult/10;
ch=mult%10+'0';
o_p=ch + o_p; 
len1--;
 }
 if(carry > 0){
ch=carry + '0';
o_p=ch + o_p;
 }
 m_m[p2]=o_p;
}

ch=' ';
for(int i=0; i < count; i++){ o_p +=ch; }
p_m.push_back(o_p);
len2--; count++;
}
return c_s_pdt(p_m);
}

int main(){
int n_t_c, num;
scanf("%d",&n_t_c);

string ans;
ostringstream _temp;
for(int i=0; i < n_t_c; i++){
scanf("%d",&num);
ans="1";
for(int j=1; j <=num; j++){
_temp << j;
ans=c_m(ans, _temp.str());
_temp.str("");
}
printf("%s\n",ans.c_str());
}
}
