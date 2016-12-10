#include <iostream>
#include <vector>
using namespace std;
int row;
int col;
int floors;
/*char** plan;*/
int** check;
int k = 1;
void groupx(int i, int j)
{
    if (i>=0&&i<row&&j>=0&&j<col&&check[i][j]==0)
    {

    check[i][j]= k;
    groupx(i-1,j);
    groupx(i+1,j);
    groupx(i,j-1);
    groupx(i,j+1);
    }
}


int main()
{

    cin>>floors;
    cin>>row;
    cin>>col;
    char plan[row][col];
    /*int check[row][col];*/
    /*plan = new char*[row];
    for (int i = 0; i < row; i++)
        plan[i] = new char [col];*/

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            cin>>plan[i][j];
        }
    }
    /*for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<plan[i][j];
        }
        cout<<endl;
    }*/
    check = new int*[row];
    for (int i = 0; i < row; i++)
        check[i] = new int [col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (plan[i][j]=='I')
            {
                check[i][j]= -1;
            }
            else if (plan[i][j]=='.')
            {
                check[i][j]= 0;
            }
        }
    }
    //cout<<"ARRAY CONSTRUCTION COMPLETE"<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (check[i][j]==0)
            {
                groupx(i,j);
                k++;
            }
        }
    }

    //cout<<"RECURSION COMPLETE"<<endl;
    /*for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<check[i][j];
        }
        cout<<endl;
    }*/
    vector<int> recorder;
    for (int i = 0; i < k +1; i++)
    {
        recorder.push_back(0);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (check[i][j]!= -1)
            {
                int temp = check[i][j];
                recorder[temp]++;
            }

        }
    }
    /*for (int i = 0; i <= k; i++)
    {
        cout<<recorder[i]<<endl;
    }*/
    recorder.erase(recorder.begin());
    recorder.pop_back();
    //cout<<endl;
    /*for (int i = 0; i < recorder.size(); i++)
    {
        cout<<recorder[i]<<endl;
    }*/
    int curmax = 0;
    int bigindex = 0;
    int rooms = 0;
    //cout<<"READY TO WHILE"<<endl;
    while (1)
    {
        if (!recorder.empty())
        {

        for (int i = 0; i < recorder.size(); i++)
        {
            if (recorder[i]>curmax)
            {
                curmax = recorder[i];
                bigindex = i;

            }
        }
        if (floors>=curmax)
        {
            floors-=curmax;
            curmax = 0;
            recorder.erase(recorder.begin()+bigindex);
            bigindex = 0;
            rooms++;

        }
        else
        {
            if (rooms==1)
            {
                cout<<rooms<<" room, "<<floors<<" square metre(s) left over";
                return 0;
            }
            else
            {
                cout<<rooms<<" rooms, "<<floors<<" square metre(s) left over";
                return 0;
            }
        }
        }
        else
        {
            if (rooms==1)
            {
                cout<<rooms<<" room, "<<floors<<" square metre(s) left over";
                return 0;
            }
            else
            {
                cout<<rooms<<" rooms, "<<floors<<" square metre(s) left over";
                return 0;
            }

        }
    }
/*cout<<"yeah ag!"<<endl;
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
*/
    return 0;
}
