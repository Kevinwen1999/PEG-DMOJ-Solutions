#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int ary[10];
int checker[4782970];
bool isPossible[4782970];
int INF = 9999999;
int W;
int D;
int V;
long answer;
void recur(int curvalue, int times)
{
        if (times==W)
        {
            isPossible[curvalue] = true;
        }
    if(times<checker[curvalue])
    {
        checker[curvalue] = times;
        if(times<W)
        {

            for (int j = 0 ; j < D; j++)
            {
                recur(curvalue+ary[j],times+1);
            }
            for (int j = 0 ; j < D; j++)
            {
                recur(curvalue*ary[j],times+1);
            }
        }
    }
}

int main()
{
    for (int i = 0 ; i < 4782970; i++)
    {
        checker[i] = INF;
        isPossible[i] = false;
    }
    cin>>W>>D;
    for (int i = 0 ; i < D; i++)
    {
        cin>>ary[i];
    }
    for (int j = 0 ; j < D; j++)
    {
        recur(ary[j],0);
    }
    cin>>V;
    for (int i = 0 ; i < V; i++)
    {
        cin>>answer;
        //cout<<checker[answer]<<endl;
        if(isPossible[answer]==true)
        {
            cout<<"Y"<<endl;
        }
        else
        {
            cout<<"N"<<endl;
        }
    }
}
