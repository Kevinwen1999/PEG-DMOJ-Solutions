#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x, y;
    point(int a, int b)
    {
        x = a; y = b;
    }
};
struct line
{
    int c1, c2, dist;
    line (int a1, int a2, int a3)
    {
        c1 = a1; c2 = a2; dist = a3;
    }
};
bool cmp(const line &a, const line &b)
{
    return b.dist > a.dist;
}
int N;
vector <point> points;
vector <line> lines;
int bestdist[2001], prevbestnum[2001], bestnum[2001];
int main()
{
    cin>>N;
    points.push_back(point(0,0));
    int cnt = 0;
    for (int i = 1, a, b, x1, y1; i <=N; i++)
    {
        cin>>a>>b;
        points.push_back(point(a,b));
        for (int j = i - 1; j >= 0; j--)
        {
            x1 = points[i].x - points[j].x;
            y1 = points[i].y - points[j].y;
            lines.push_back(line(j,i,x1*x1 + y1*y1));
            cnt++;
        }
    }
    sort(lines.begin(), lines.end(), cmp);
    line cur = line(0,0,0);
    for (int i = 0 ; i < lines.size(); i++)
    {
        cur = lines[i];
        if (cur.dist > bestdist[cur.c1])
        {
            bestdist[cur.c1] = cur.dist;
            prevbestnum[cur.c1] = bestnum[cur.c1];
        }
        if (cur.dist > bestdist[cur.c2])
        {
            bestdist[cur.c2] = cur.dist;
            prevbestnum[cur.c2] = bestnum[cur.c2];
        }
        if (cur.c1 == 0)
        {
            bestnum[cur.c1] = max(bestnum[cur.c1], prevbestnum[cur.c2]+1);
        }
        else
        {
            bestnum[cur.c1] = max(bestnum[cur.c1], prevbestnum[cur.c2] + 1);
            bestnum[cur.c2] = max(bestnum[cur.c2], prevbestnum[cur.c1] + 1);
        }
    }
    cout<<bestnum[0]<<"\n";
}
