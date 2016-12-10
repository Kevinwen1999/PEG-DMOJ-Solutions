// Example program http://cpp.sh/9evj
#include <iostream>
int main(){

     int i = 0;
     int j = 0;
     std::cin >> i;
     while(1)
     {
         if (i == 1 )
         {
          std::cout<<j; return 0;   
         }
     if (i%2==0)
     {
         i = i / 2;
         j++;
     }
         else
         {i = i*3 + 1;
         j++;}
         
         
         
         
     }
     
    return 0;
}