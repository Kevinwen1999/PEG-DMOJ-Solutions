#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int M;
int Q;
int INF = 9999999;
int timex[150];
string name[150];
int group[150];
int dp[150];
bool isEnd[150];
int main()
{
    cin>>M>>Q;
    timex[0] = 0;
    name[0] = "empty";
    for (int i = 0 ; i < 150; i++)
    {
        group[i] = 0;
        dp[i] = INF;
        isEnd[i] = false;
    }
    dp[0] = 0;
    dp[1] = timex[1];
    for (int i = 1 ; i <= Q; i++)
    {
        cin>>name[i]>>timex[i];
    }
//--------------------------------------------------------
    for (int i = 1; i <= Q; i++)
    {
        int curmin = INF;
        for (int j = 0; (i-j-1)>=0 && j < M; j++)
        {
            int tempmax = -1;
            for (int k = (i-j); k <= i; k++)
            {
                if(timex[k] > tempmax)
                {
                    tempmax = timex[k];
                }
            }
            int tempmin = tempmax + dp[i-j-1];
            if (tempmin < curmin)
            {
                curmin = tempmin;
                group[i] = j;
            }
        }
        dp[i] = curmin;
    }
//--------------------------------------------------------
    cout<<"Total Time: "<<dp[Q]<<endl;
    isEnd[Q] = true;
    for (int i = Q; i >=1; i-= 1)
    {
        int temp = i-group[i]-1;
        if (isEnd[i] == true)
        {
            isEnd[temp] = true;
        }
    }
    for (int i = 1 ; i <= Q; i++)
    {
        if (!isEnd[i])
        {
            cout<<name[i]<<' ';
        }
        else
        {
            cout<<name[i]<<endl;
        }
    }
}
