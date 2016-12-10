#include <iostream>
#include <cstring>
using namespace std;
int N, M,color,mx , mi, mj;
string temp;
char grid[110][110];
int dp[110][110];
int diri[4] = {1, -1, 0, 0};
int dirj[4] = {0, 0, 1, -1};
bool mxf[11000], tempf[11000];
int totall = 0;
void dfs(int i, int j , int color)
{
    if (i<0||j<0||i>=N||j>=M) return;
    if (dp[i][j]!=0) return;
    dp[i][j] = color;
    for (int a = 0 ; a < 4; a++)
        dfs(i+diri[a],j+dirj[a],color);
}

int main()
{
    cin>>N>>M;
    for (int i = 0 ; i < N; i++)
    {
        cin>>temp;
        for (int j = 0 ; j < M; j++)
            grid[i][j] = temp[j];
    }
    for (int i = 0 ; i < N; i++)
        for (int j = 0 ; j < M; j++)
            if (grid[i][j]=='X')
                dp[i][j] = -1;
    for (int i = 0 ; i < N; i++)
        for (int j = 0 ; j < M; j++)
        {
            if (dp[i][j]==0)
            {
                color++;
                dfs(i,j,color);
            }
        }
    for (int i = 0 ; i < N; i++)
        for (int j = 0 ; j < M; j++)
        {
            if (dp[i][j]==-1)
            {

                memset(tempf,0,sizeof tempf);
                totall = 0;
                for (int a = 0 ; a < 4; a++)
                {
                    int ii = i+diri[a], jj = j+dirj[a];
                    if (ii>=0&&jj>=0&&ii<N&&jj<M)
                    {
                        if (dp[ii][jj]!=-1)
                        {
                            if(tempf[dp[ii][jj]]==false)
                             {
                                totall++;
                                tempf[dp[ii][jj]] = true;
                             }
                        }
                    }
                }
                if (totall>mx&&totall>1)
                {
                    mx = totall;
                    memset(mxf,0,sizeof mxf);
                    mi = i; mj = j;
                    for (int i = 1; i <= color; i++)
                        if (tempf[i]) mxf[i] = true;
                }
            }
        }
    if (mx<=1) cout<<-1<<endl;
    else
    {
        cout<<mx<<endl;
        cout<<mj<<" "<<mi<<endl;
        for (int i = 1; i <= color; i++)
            if (mxf[i]) cout<<i<<" ";
    }
}
