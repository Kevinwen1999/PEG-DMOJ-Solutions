#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
int total;
int input;
int sum;
cin>>total;
vector<int>ary;
  for (int i = 0; i < total; i++)
  {
  cin>>input;
    if(input == 0)
	{ary.pop_back();}
	else
	{ary.push_back(input);}
  }
  if (ary.empty())
  {
  sum=0;
  }
  else
  { 
	sum=accumulate(ary.begin(),ary.end(),0);
  }
cout<<sum;

return 0;
}
