#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
int N, M;
struct point
{
    double x, y;
    int cir;
    point() {x = y = 0.0;}
    point(double a, double b) {x = a; y = b;}
}p1, p2, p3;
double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
vector <point> allo, ans;
vector <int> ecs;
double tl;
int tot = 0, valid = 0;
bool pos[100*500+10];
int main()
{
    //cout<<dist(point(100,100), point(110,90));
    double a, b;
    cin>>a>>b>>N>>M;
    p1 = point(a,b);
    for (int i = 0; i < N; i++)
    {
        int v; cin>>v;
        ecs.push_back(v);
        tl += v;
    }
    sort(ecs.begin(), ecs.end());
    for (int i = 0; i < M; i++)
    {
        int sn;
        cin>>a>>b>>sn;
        p2 = point(a,b);
        p2.cir = sn;
        allo.push_back(p2);
    }
    bool found = false;
    for (int i = 0; i < M; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            if (allo[i].cir == allo[j].cir)
                continue;
            double d1 = dist(allo[i], p1);
            double d2 = dist(allo[j], p1);
            memset(pos,0,sizeof pos);
            pos[0] = true;
            for (int k = 0; k < N; k++)
            {
                for (int l = min(d1, d2); l >= 0; l--)
                {
                    if (pos[l])
                        pos[l+ecs[k]] = true;
                }
            }
            for (int k = min(d1, d2); k <= tl - max(d1,d2); k++)
            {
                if (pos[k])
                {
                    found = true;
                    printf("Harry can connect to outlets at (%.1lf, %.1lf) and (%.1lf, %.1lf).\n", allo[i].x, allo[i].y, allo[j].x, allo[j].y);
                    return 0;
                }

            }

        }
    }
    printf("Harry is helpless.\n");
}
