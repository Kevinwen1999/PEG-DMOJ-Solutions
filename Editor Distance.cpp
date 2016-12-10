#include <bits/stdc++.h>
using namespace std;
struct pos
{
    int i,j,d;
};
int C[100010];
bool visited[100010][90];
int R;
int sr, sc, er, ec;
int main()
{
    cin>>R;
    for (int i = 0; i < R; i++)
        cin>>C[i];
    cin>>sr>>sc>>er>>ec;
    sr--; er--;
    visited[sr][sc] = true;
    queue <pos> buff;
    buff.push((pos){sr,sc,0});
    while (!buff.empty())
    {
        pos ct = buff.front();
        buff.pop();
        if (ct.i == er && ct.j == ec)
        {
            cout<<ct.d;
            return 0;
        }
        int ni, nj;
        // <---
        if (!(ct.i==0 && ct.j == 1))
        {
            if (ct.j==1)
            {
                ni = ct.i-1; nj = C[ni];
            }
            else
            {
                ni = ct.i; nj = ct.j - 1;
            }
            if (!visited[ni][nj])
            {
                visited[ni][nj] = true;
                buff.push((pos){ni,nj,ct.d+1});
            }
        }
        // --->
        if (!(ct.i==R-1 && ct.j==C[ct.i]))
        {
            if (ct.j == C[ct.i])
            {
                ni = ct.i+1; nj = 1;
            }
            else
            {
                ni = ct.i; nj = ct.j+1;
            }
            if (!visited[ni][nj])
            {
                visited[ni][nj] = true;
                buff.push((pos){ni,nj,ct.d+1});
            }
        }
        // up
        if (ct.i > 0)
        {
            ni = ct.i-1;
            nj = min(ct.j, C[ni]);
            if (!visited[ni][nj])
            {
                visited[ni][nj] = true;
                buff.push((pos){ni,nj,ct.d+1});
            }
        }
        //down
        if (ct.i < R-1)
        {
            ni = ct.i+1;
            nj = min(ct.j, C[ni]);
            if (!visited[ni][nj])
            {
                visited[ni][nj] = true;
                buff.push((pos){ni,nj,ct.d+1});
            }
        }
    }
}
