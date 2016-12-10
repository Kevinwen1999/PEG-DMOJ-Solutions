// Example program http://cpp.sh/45o7
#include <iostream>
#include <string>

int main()
{
int i = 0;   
std::cin>>i;
int* array;
array = new int[i];
for (int ii= 0; ii< i; ii++)
{
 std::cin>>array[ii];   
}
/*for (int ii= 0; ii< i; ii++)
{
 std::cout<<array[ii];   
}*/
int j = 0;
int k = 1;
for (int jj = 0; jj<i; jj++)
{
 if(jj==i-1)
 {
   if(k>j)
   {j = k;}
   
   std::cout<<j;
   return 0;;
 }
 if(array[jj]<=array[jj+1])
 {
  k= k + 1; 
 }
if  (array[jj]>array[jj+1])
 {
 if(k>j)
 {j = k;}
 k = 1;
 }
}

}