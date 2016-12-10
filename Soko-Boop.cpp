#include <bits/stdc++.h>
using namespace std;
int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};
int R, C;
int si, sj, bi, bj, xi, xj;
char grid[31][31];
int dist[31][31][31][31];

struct node
{
    int i, j, bi, bj;
};
bool valid(int i, int j)
{
    if (i<0||j<0||i>=R||j>=C||grid[i][j]=='#') return false;
    return true;
}
queue <node> buff;
node cur,nex;
int main()
{
    cin>>R>>C;
    for (int i = 0 ; i < R; i++)
    {
        cin>>grid[i];
        for (int j = 0 ; j < C; j++)
        {
            if (grid[i][j]=='P') si = i, sj = j;
            if (grid[i][j]=='B') bi = i, bj = j;
            if (grid[i][j]=='X') xi = i, xj = j;
        }
    }
    memset(dist, -1, sizeof dist);
    cur.i = si; cur.j = sj; cur.bi = bi; cur.bj = bj;
    dist[si][sj][bi][bj] = 0;
    buff.push(cur);
    bool flag = false;
    int ci, cj, cbi, cbj;
    while (!buff.empty())
    {
        cur.i = buff.front().i; cur.j = buff.front().j; cur.bi = buff.front().bi; cur.bj = buff.front().bj;
        //cout<<"new one\n"<<cur.i<<" "<<cur.j<<" "<<cur.bi<<" "<<cur.bj<<"\n";
        buff.pop();
        //ci = cur.i; cj = cur.j; cbi = cur.bi; cbj = cur.bj;
        if (cur.bi==xi&&cur.bj==xj)
        {
            cout<<dist[cur.i][cur.j][cur.bi][cur.bj];
            flag = true;
            break;
        }
        for (int i = 0 ; i < 4; i++)
        {
            ci = cur.i + di[i]; cj = cur.j + dj[i];
            if (!valid(ci,cj)) continue;

            if (ci==cur.bi && cj == cur.bj) {cbi = cur.bi+di[i]; cbj = cur.bj + dj[i];}
            else {cbi = cur.bi; cbj = cur.bj;}
            if (!valid(cbi,cbj)) continue;

            if (dist[ci][cj][cbi][cbj]!=-1) continue;

            dist[ci][cj][cbi][cbj] = dist[cur.i][cur.j][cur.bi][cur.bj] + 1;

            nex.i = ci; nex.j = cj; nex.bi = cbi; nex.bj = cbj;
            buff.push(nex);
        }
    }
    if (!flag)
        cout<<-1;
}
