#include<iostream>
#include<vector>
using namespace std;
//0 1 2 3 4 5 6 7 8 9
int main()
{
int k; 
int m;
cin>>k;
cin>>m;
vector<int> ary;
vector<int>::iterator it;

  for (int i =1; i<=k; i++)
  {ary.push_back(i);}

int* row = new int[m];
  for (int a = 0; a < m; a++)
  {cin>>row[a];}
  //----------
  for (int b =0; b < m; b++)
  {
    int timer = 0;
    for (it = ary.begin(); it != ary.end();)
	{
	timer ++;
	  if (timer == row[b])
	  {
	  it = ary.erase(it);
	  timer = 0;
	  }
	  else
	  {
	  it++;
	  }
	}
  }
  for (int d =0; d<ary.size(); d++)
  {
	cout<<ary[d]<<endl;
  }
return 0 ;
}
