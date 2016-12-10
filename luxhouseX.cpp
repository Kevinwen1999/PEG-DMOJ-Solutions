#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
int main()
{
  int i = 0;
  int num;
  cin>>num;
  int it = 0;
  cin>>it;
  int* ary = new int[num];
  for (int j = num-1; j >= 0; j--)
  {
      ary[j]=it % 10;
      it /= 10;
  }
  for (int i = 0; i < num ; i++)
    {
    if (*(max_element(ary+i,ary+num))==ary[i])
	  {
	  cout<<0;
	  }
	else
      {
	  cout<<(*(max_element(ary+i,ary+num))+1) - ary[i];
	  }
    }
	return 0;
}
