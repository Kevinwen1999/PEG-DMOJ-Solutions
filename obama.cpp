// Example program
#include <iostream>
using namespace std;
int main()
{
    int rowCount;

    cin>>rowCount;

int** ary = new int*[rowCount];
for(int i = 0; i < rowCount; i++)
   { ary[i] = new int[rowCount];}
   int test ;
    for(int i = 0; i < rowCount; i++){
     for(int j = 0; j < rowCount; j++){
          cin>>test;
        ary[i][j]=test;
     }
    }


	
bool* check= new bool[rowCount];
bool isone = false;
int k = 0;
int g = 0;
for(int i = 0; i < rowCount; i++)
{check[i]=true;}


for (int i = 0; i < rowCount; i++){
 for (int j = 0; j < rowCount; j++) {
  if(ary[i][j]==0)
  {
      check[j] = false;
	  for (int jj=0; jj<rowCount; jj++)
	  {
	  if (ary[jj][j]==0)
	  {ary[jj][j]=1;}
      else
	  {ary[jj][j]=0;}
	  }
  }
}

 
 
    for (int iii=0;iii<rowCount; iii++)
	{
	for (int jjj=0;jjj<rowCount; jjj++)
	{
	if (ary[iii][jjj]==1)
	{isone=true;}
	else if(ary[iii][jjj]==0)
	{isone=false;break;}
	}
	if(isone == true)
	{k=k+1;}
	isone = true;
	}
	
	if (k >= g)
	{g = k;
	k = 0;}
	else
	{k = 0;}
	
	
	for (int jjjj=0; jjjj<rowCount; jjjj++)
	{
	if (check[jjjj]==false)
	{
	for (int jj=0; jj<rowCount; jj++)
	  {
	  if (ary[jj][jjjj]==0)
	  {ary[jj][jjjj]=1;}
      else
	  {ary[jj][jjjj]=0;}
	  }
	check[jjjj]=true;
	}
	}
	

	
}
cout << g;
return 0;
}
