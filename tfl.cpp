#include <iostream>
using namespace std;
int main()
{

int times, k;
cin>>times>>k;
for (int i = 0; i < times; i++)
{
long con = k;
while(1)
{
unsigned long long conx = (con*con)*con;
if (conx % 1000 == 888)
{cout<<con<<endl;break;}
else
{con++;}
}
cin>>k;
}
return 0;
}
