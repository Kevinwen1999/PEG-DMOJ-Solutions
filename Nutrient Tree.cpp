#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
string in;
int X;
int tree[MAXN*4];
int dp[MAXN*4][2510],dpl[MAXN*4][2510], dpr[MAXN*4][2510];
int idx = 0;
char cur;
void read()
{
    cur = in[idx++];
    while (isspace(cur))
        cur = in[idx++];
}
void build(int index)
{
    read();
    if (isdigit(cur))
    {
        int value = cur - '0';
        cur = in[idx++];
        while (isdigit(cur))
        {
            value *= 10;
            value += cur - '0';
            cur = in[idx++];
        }
        idx--;
        tree[index] = value;
        return;
    }
    else if (cur == '(')
    {
        build(index*2);
        build(index*2+1);
        read();
    }
}
void dfs(int index)
{
    if (tree[index]==0) //is not a leaf
    {
        dfs(index*2);
        dfs(index*2+1);
        //left side
        for (int i = 0; i <= X; i++)
            for (int j = 0; j <= i; j++)
                dpl[index][i] = max(dpl[index][i], min((1+j)*(1+j), dp[index*2][i-j]));
        //right side
        for (int i = 0 ; i <= X; i++)
            for (int j = 0 ; j <= i; j++)
                dpr[index][i] = max(dpr[index][i], min((1+j)*(1+j), dp[index*2+1][i-j]));
        //current node
        for (int i = 0; i <= X; i++)
            for (int j = 0 ; j <= i; j++)
                dp[index][i] = max(dp[index][i], dpl[index][j] + dpr[index][i-j]);
    }
    else
    {
        for (int i = 0 ;i <= X; i++)
            dp[index][i] = tree[index]+i;
    }
}
int main()
{
    getline(cin, in);
    build(1);
    cin>>X;
    memset(dp, 0, sizeof dp);
    memset(dpl, 0, sizeof dpl);
    memset(dpr, 0 ,sizeof dpr);
    dfs(1);
    cout<<dp[1][X]<<"\n";
}
