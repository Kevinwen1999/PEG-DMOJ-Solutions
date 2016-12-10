#include <bits/stdc++.h>
using namespace std;
struct point
{
    double x, y;
};
double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
point allp[60], cur;
int N;
double per[60];
int main()
{
    while (scanf("%d", &N) && N)
    {
        for (int i = 0; i < N; i++)
        {
            double x, y;
            cin>>x>>y;
            allp[i].x = x; allp[i].y = y;
            per[i] = 0;
        }
        for (double i = 0.01; i <= 10; i+= 0.01)
        {
            for (double j = 0.01; j <= 10; j+= 0.01)
            {
                int idx;
                double min = 9999999999.9;
                cur.x = i; cur.y = j;
                for (int k = 0; k < N; k++)
                {
                    if (dist(cur, allp[k]) < min)
                    {
                        min = dist(cur, allp[k]);
                        idx = k;
                    }
                }
                per[idx]++;
            }
        }
        for (int i = 0; i < N; i++)
        {
            double p = per[i] / 10000.0;
            printf("Restaurant at (%.0lf,%.0lf) serves %.0lf%% of the population.\n", allp[i].x, allp[i].y, p);
        }
    }
}
