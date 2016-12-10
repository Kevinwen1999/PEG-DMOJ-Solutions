#include <iostream>
using namespace std;
int three(int );
int five(int );
int main(){
int input;
int use;
int threes;
int fives;
int sum;
cin>>input;
use = input - 1;
threes = use / 3;
fives = use / 5;
int a = three(threes);
int b = five(fives);
sum = a + b;
cout<< sum ;
return 0;
}
int three(int i){
int sum;
for (int ii = i; ii > 0; ii=ii - 1)
  {
  sum += 3 * ii;
  }
  return sum;
}
int five(int i){
int sum;
for (int ii = i; ii > 0; ii=ii - 1)
  {
  sum += 5 * ii;
  }
  return sum;
}
