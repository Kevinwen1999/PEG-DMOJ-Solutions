#include<iostream>
using namespace std;
int main()
{
int times;
cin>>times;
int ary[times];
bool direction[times];
int hours[times];
for (int i = 0; i < times; i++ )
{
int d,h,s;
cin>>d>>h>>s;
if(d==12||d==6)
{
direction[i]=true;
if(d==12)
{s=s;}
if(d==6)
{s=-s;}
}
if(d==3||d==9)
{
direction[i]=false;
if(d==3)
{s=s;}
if(d==9)
{s=-s;}
}
ary[i]=s;
hours[i]=h;
}
int x = 0;
int y = 0;
int rest = 0;
int counter = 0;

for(int i = 0; i < times; i++)
{
for (int j = 0; j < hours[i]; j++)
{
int xx = x;
int yx = y;
if (direction[i]==true)
{y += ary[i];}
if (direction[i]==false)
{x += ary[i];}
//cout<<x<<" "<<y<<" "<<xx<<" "<<yx<<endl;
if ((xx==0&&yx<0&&y>=0)||(xx==0&&yx>0&&y<=0)||(yx==0&&xx>0&&x<=0)||(yx==0&&xx<0&&x>=0))
{cout<<counter;return 0;}
rest++;
if(rest==5)
{counter++;rest=0;}
}
}
cout<<-1;
return 0;
}
