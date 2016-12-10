#include <iostream>
#include <vector>
using namespace std;
int row;
int col;
int floors;
char** plan;
int** check;
vector<int> recorder (1,0);
vector<int> counter (1,0);
void groupx(int rowx, int colx)
{
    if (plan[rowx][colx]=='.')
    {

    cout<<"called"<<endl;

   /* if (rowx!=0&&rowx!=row&&colx!=0&&colx!=col&&plan[rowx-10][colx]=='I'&&plan[rowx][colx-1]=='I'&&plan[rowx+10][colx]=='I'&&plan[rowx][colx+1]=='I')
    {
        check[rowx][colx]= (recorder.back()+1);
        recorder.push_back(recorder.back()+1);
        counter.push_back(1);
    }
    */


    if (check[rowx][colx]==0)
    {


    if (rowx!=0&&plan[rowx-1][colx]=='.')
    {
        cout<<"up"<<endl;
        if(check[rowx-1][colx]!=0)
        {
            cout<<"nei not 0"<<endl;
            check[rowx][colx]=check[rowx-1][colx];
            //int temp = check[rowx-1][colx] ;
            //counter[temp]+=1;
            cout<<"assign over"<<endl;
        }
    }
     if (rowx!=(row-1)&&plan[rowx+1][colx]=='.')
    {
        cout<<"down"<<endl;
        //cout<<"bibibobi"<<endl;
        if(check[rowx+1][colx]!=0)
        {
            cout<<"nei not 0"<<endl;
            check[rowx][colx]=check[rowx+1][colx];
            //int temp = check[rowx+1][colx] ;
            //counter[temp]+=1;
            cout<<"assign over"<<endl;
        }
    }
     if (colx!=0&&plan[rowx][colx-1]=='.')
    {
        cout<<"left"<<endl;
        //cout<<"bibibobi"<<endl;
        if(check[rowx][colx-1]!=0)
        {
             cout<<"nei not 0"<<endl;
            check[rowx][colx]=check[rowx][colx-1];
            //int temp = check[rowx][colx-1] ;
            //counter[temp]+=1;
            cout<<"assign over"<<endl;
        }
    }
     if (colx!=(col-1)&&plan[rowx][colx+1]=='.')
    {
        cout<<"right"<<endl;
        //cout<<"bibibobi"<<endl;
        if(check[rowx][colx+1]!=0)
        {
             cout<<"nei not 0"<<endl;
            check[rowx][colx]=check[rowx][colx+1];
            //int temp = check[rowx][colx+1] ;
            //counter[temp]+=1;
            cout<<"assign over"<<endl;
        }
    }
    //cout<<"over..."<<endl;
    if (check[rowx][colx]==0)
    {
        cout<<"no neighbor assigned";
       check[rowx][colx]= recorder.back()+1;
        recorder.push_back(recorder.back()+1);
        counter.push_back(1);
        cout<<"ini over"<<endl;
    }
   }
   //cout<<"check?"<<endl;
   /*if (check[rowx][colx]==0)
   {
       cout<<"ohohoh";
       check[rowx][colx]= recorder.back()+1;
        recorder.push_back(recorder.back()+1);
        counter.push_back(1);
   }*/

   if (rowx!=0&&plan[rowx-1][colx]=='.')
    {
        //cout<<"check up"<<endl;
        groupx(rowx-1,colx);
    }
    if (rowx!=(row-1)&&plan[rowx+1][colx]=='.')
    {
        //cout<<"check down"<<endl;
        groupx(rowx+1,colx);
    }
    if (colx!=0&&plan[rowx][colx-1]=='.')
    {
        //cout<<"check left"<<endl;
        groupx(rowx,colx-1);
    }
    if (colx!=(col-1)&&plan[rowx][colx+1]=='.')
    {
        //cout<<"check right"<<endl;
        groupx(rowx,colx+1);
    }


    }
}
int main()
{

    cin>>floors;
    cin>>row;
    cin>>col;
    plan = new char*[row];
    for (int i = 0; i < row; i++)
        plan[i] = new char [col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>plan[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<plan[i][j];
        }
        cout<<endl;
    }
    check = new int*[row];
    for (int i = 0; i < row; i++)
        check[i] = new int [col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            check[i][j] = 0;
        }
    }
    //cout<<"yeah:"<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (plan[i][j]=='.'&&check[i][j]==0)
            {
                groupx(i,j);
            }
        }
    }
cout<<"yeah ag!"<<endl;
    int floorsx=floors;
    int rooms = recorder.back();
    int total = recorder.back();
    bool* ava = new bool[total+1];
    for (int k = 0; k < total; k++)
        ava[k]=true;
    //cout<<"yeah again!!!"<<endl;
    while(1)
    {
        int bigindex = 0;
        int bigvalue = 0;
        for (int i = 1; i <= total; i++ )
        {
            if (counter[i]>bigvalue&&ava[i]==true)
            {
                bigvalue = counter[i];
                bigindex = i;
            }
        }
        if (bigvalue<=floorsx)
        {
            floorsx-=bigvalue;
            ava[bigindex]=false;
            rooms--;
        }
        else if (bigvalue>floorsx)
        {
            break;
        }
    }

    cout<<rooms<<" rooms, "<<floorsx<<" square metre(s) left over";

    return 0;
}
