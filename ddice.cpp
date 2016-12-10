#include<iostream>
using namespace std;
int main()
{
int a = 0;
int b = 100;
int c = 100;
int e;
int f;
cin>>a;
for (int i = 1; i <=a; i++)
  {
    cin>>e;
	cin>>f;
	if (e == f)
	{continue;}
	else if(e > f)
	{c-=e;}
	else if(e < f)
	{b-=f;}
  }
  cout<<b<<endl<<c<<endl;
return 0;
}
