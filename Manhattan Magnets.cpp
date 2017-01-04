#include <bits/stdc++.h>
#define MAXN 4001
using namespace std;
int M, N;
struct point
{
    int x, y;
} cur;
int mandist(point &a, point &b)
{
    return abs(a.x-b.x) + abs(a.y-b.y);
}
vector <point> mag;
int diff[2*MAXN][2*MAXN];
int tx, ty;
void rot(int &x, int &y)
{
    tx = x;
    ty = y;
    x = tx  + ty;
    y = ty - tx + MAXN;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>M;
    for (int i = 0; i < M; i++)
    {
        cin>>cur.x>>cur.y;
        mag.push_back(cur);
    }
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>cur.x>>cur.y;
        int mindist = 1e10;
        for (int j = 0; j < M; j++)
        {
            mindist = min(mindist, mandist(cur, mag[j]));
        }
        if (--mindist < 0) continue;
        rot(cur.x, cur.y);
        int x1 = max(0, cur.x-mindist), y1 = max(0, cur.y-mindist), x2 = min(2*MAXN-1, cur.x + mindist+1), y2 = min(2*MAXN-1, cur.y + mindist + 1);
        diff[x1][y1]++;
        diff[x1][y2]--;
        diff[x2][y2]++;
        diff[x2][y1]--;
    }
    for (int i = 0; i < 2*MAXN; i++)
    {
        for (int j = 0; j < 2*MAXN; j++)
        {
            if (i > 0) diff[i][j] += diff[i-1][j];
            if (j > 0) diff[i][j] += diff[i][j-1];
            if (i > 0 && j > 0) diff[i][j] -= diff[i-1][j-1];
        }
    }
    int ans = -1e10;
    for (int i = 0, x, y; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            x = i; y = j;
            rot(x, y);
            ans = max(ans, diff[x][y]);
        }
    }
    cout<<ans<<"\n";
}
