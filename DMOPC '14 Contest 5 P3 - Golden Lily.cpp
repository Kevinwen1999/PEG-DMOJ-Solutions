#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#define INF 0x3f3f3f3f
using namespace std;
int D, L,tari,tarj;
int field[1010][1010];
int dp[1010][1010];
int diri[] = {1,0,0};
int dirj[] = {0,1,-1};
void bfs()
{
    queue < pair <int,int> > buff;
    buff.push(make_pair(0,0));
    while(!buff.empty())
    {
        pair <int,int> v = buff.front();
        buff.pop();
        int i = v.first, j = v.second;
        for (int cnt = 0; cnt < 3; cnt++)
        {
        if (i+diri[cnt]<0||j+dirj[cnt]<0||i+diri[cnt]>tari||j+dirj[cnt]>=L)
            continue;
        if (dp[i][j]+field[i+diri[cnt]][j+dirj[cnt]]<dp[i+diri[cnt]][j+dirj[cnt]])
        {
            dp[i+diri[cnt]][j+dirj[cnt]] = dp[i][j]+field[i+diri[cnt]][j+dirj[cnt]];
            buff.push(make_pair(i+diri[cnt],j+dirj[cnt]));
        }
        }
    }
}
int main()
{
    cin>>L>>D;
    for (int i = 0 ; i < D; i++)
        for (int j = 0 ; j < L; j++)
            cin>>field[i][j];
    cin>>tarj>>tari;
    memset(dp,63,sizeof dp);
    dp[0][0] = field[0][0];
    bfs();
    cout<<dp[tari][tarj]<<endl;

}
