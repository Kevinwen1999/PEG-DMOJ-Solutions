#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x, y;
    string op;
}a,b,cur;
int R, C;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin>>T;
    while (T--)
    {
        cin>>R>>C;
        int ax, ay, bx, by, dx, dy; // dx::NS, dy::EW
        string dd;
        cin>>ax>>ay>>bx>>by>>dd;
        dx = dd[0] == 'N' ? 1 : -1; dy = dd[1] == 'E' ? 1 : -1;
        int tot = 0, lc = 0;
        int disttohor, disttover;
        bool found = false;
        while (lc++ <= 50000)
        {
            //int disttohor, disttover;
            if (dy==1)
                disttover = C - ay;
            else
                disttover = ay;

            if (dx==1)
                disttohor = R - ax;
            else
                disttohor = ax;

            if ((ax-bx) * dy == (ay-by)*dx)
            {
                found = true;
                tot += abs(ax-bx);
                break;
            }

            if (disttover < disttohor)
            {
                int mv = disttover;
                ax += mv * dx; ay += mv * dy;
                tot += mv;
                dy = -dy;
            }
            else if (disttohor < disttover)
            {
                int mv = disttohor;
                ax += mv * dx; ay += mv * dy;
                tot += mv;
                dx = -dx;
            }
            else
            {
                int mv = disttohor;
                ax += mv * dx; ay += mv * dy;
                tot += mv;
                dx = -dx;
                dy = -dy;
            }
        }
        if (found)
            printf("B can be reached from A after %d move(s).\n", tot);
        else
            printf("B cannot be reached from A.\n");
    }
}
