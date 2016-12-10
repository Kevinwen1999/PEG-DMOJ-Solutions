#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int R, C, P;
int si, sj, ei, ej;
int grid[20][20];
int di[9] = {0,1,0,-1,0,1,1,-1,-1};
int dj[9] = {0,0,1,0,-1,1,-1,1,-1};
bool visited[20][20][25][25];
struct node
{
    int i, j, si, sj, dist;
};
void bfs()
{
    bool found = false;
    memset(visited,0,sizeof visited);
    queue <node> buff;
    buff.push((node){si,sj,0,0,0});
    while (!buff.empty())
    {
        int ii = buff.front().i, jj = buff.front().j, vi = buff.front().si, vj = buff.front().sj, ds = buff.front().dist;
        buff.pop();
        if (ii == ei && jj == ej)
        {
            cout<<"Optimal solution takes "<<ds<<" hop(s).\n";
            found = true;
            break;
        }
        if (visited[ii][jj][vi+4][vj+4]) continue;
        visited[ii][jj][vi+4][vj+4] = 1;
        for (int s = 0; s < 9; s++)
        {
            int speedi = vi + di[s], speedj = vj + dj[s];
            if (speedi < -3 || speedi > 3 || speedj < -3 || speedj > 3) continue;
            int ni = ii + vi + di[s], nj = jj + vj + dj[s];
            if (ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
            if (grid[ni][nj]) continue;
            if (visited[ni][nj][speedi+4][speedj+4]) continue;
            buff.push(node{ni,nj,speedi,speedj,ds+1});
        }
    }
    if (!found)
        cout<<"No solution.\n";
}
int main()
{
    int T; cin>>T;
    while (T--)
    {
        memset(grid,0,sizeof grid);
        cin>>R>>C;
        cin>>si>>sj>>ei>>ej;
        cin>>P;
        for (int i = 0; i < P; i++)
        {
            int x1, x2, y1, y2;
            cin>>x1>>x2>>y1>>y2;
            for (int i = x1; i <= x2; i++)
            {
                for (int j = y1; j <= y2; j++)
                    grid[i][j] = 1;
            }
        }
        bfs();
    }
}
