#include <bits/stdc++.h>
#define B 32000
using namespace std;
int N;
int num[110];
bool dp[110][B+B+10];
bool visited[110][B+B+10];
int op(int a, int b, int op)
{
    if (op==1)
        return a+b;
    else if (op==2)
        return a-b;
    else if (op==3)
        return a*b;
    else
        return a/b;
}
int choice[110];
bool recur (int n, int sum)
{
    if (visited[n][sum+B]) return dp[n][sum+B];
    visited[n][sum+B] = true;
    if (n==N-2)
    {
        bool OK = false;
        for (int i = 1; i <= 4 && !OK; i++)
        {
            if (i==4 && (abs(sum) % num[n]!=0)) continue;
            int result = op(sum,num[n],i);
            if (abs(result) <= 32000 && result == num[N-1])
            {
                OK = true;
                choice[n] = i;
                return OK;
            }
        }
        return OK;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (i==4 && (abs(sum) % num[n]!=0)) continue;
        int result = op(sum,num[n],i);
        if (abs(result) > 32000) continue;
        if (recur(n+1,result))
        {
            choice[n] = i;
            return dp[n][sum+B]=true;
        }
    }
    return dp[n][sum+B]=false;
}
char mp[5] = {' ','+','-','*','/'};
int main()
{
    int T; cin>>T;
    while (T--)
    {
        memset(visited,0,sizeof visited);
        cin>>N;
        N+=1;
        for (int i = 0; i < N; i++)
        {
            cin>>num[i];
        }
        if (N==2)
        {
            if (num[0]==num[1])
                cout<<num[0]<<"="<<num[1]<<"\n";
            else
                cout<<"NO EXPRESSION\n";
        }
        else
        {
            if (recur(1,num[0]))
            {
                for (int i = 0; i < N-1; i++)
                {
                    if (i>0)cout<<mp[choice[i]];
                    cout<<num[i];
                }
                cout<<"="<<num[N-1]<<"\n";
            }
            else
                cout<<"NO EXPRESSION\n";
        }
    }
}
