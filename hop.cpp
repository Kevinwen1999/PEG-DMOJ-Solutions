#include <iostream>
using namespace std;
    int rowCount;
	int colCount;
	int Max;
	int k;
//----------------------------------
void check(int** ary,int i,int j){
if(ary[i][j]!=ary[rowCount-1][colCount-1])
{k++;}
for (int a =i; a<rowCount; a++ )
  {
    for (int b = j; b<colCount; b++)
	{
	if(a!=i&&a!=rowCount-1&&b!=j&&b!=colCount-1&&ary[a][b]!=ary[i][j])
	  {
	    check(ary,a,b);
	  }
	}
  }  

}
//----------------------------------
int main()
{


    cin>>rowCount;
	cin>>colCount;
	cin>>Max;

int** ary = new int*[rowCount];
for(int i = 0; i < rowCount; i++)
   { ary[i] = new int[colCount];}
   int test ;
    for(int i = 0; i < rowCount; i++){
     for(int j = 0; j < colCount; j++){
          cin>>test;
        ary[i][j]=test;
     }
    }
//----------------------------------
	
	check(ary,0,0);
	
	cout<<k;
	
	
	
return 0;	
}
