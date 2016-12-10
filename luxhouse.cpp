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
  string str;
  cin.ignore();
  getline(cin,str);
  stringstream ss;
  ss<<str;
  string temp;
  int* ary = new int[num];
  while(getline(ss, temp,' ')) {
    stringstream(temp)>>ary[i];
    i++;
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
