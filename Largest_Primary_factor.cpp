// Example program
#include <iostream>
using namespace std;
int main()
{
 int re = 0;
 int i = 2 ;
 long ori = 600851475143;
 while (true){
 if (ori % i == 0)
 {
 ori = ori / i;
 re = i;
 if (ori == 1){break;}
 }
 else
 {i = i + 1;}
 }
    cout << re;
    return 0;
}