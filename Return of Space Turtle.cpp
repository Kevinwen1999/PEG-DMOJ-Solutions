#include <bits/stdc++.h>
using namespace std;
int sm,tmm;
struct point
{
    double x, y;
}s, t;
double dist (point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
vector <point> turtle, gold;
int main()
{
    cin>>s.x>>s.y>>sm;
    for (int i = 0; i < sm; i++)
    {
        double d; char op;
        cin>>d>>op;
        if (op=='X')
            for (int i = 0; i < abs(d); i++)
            {
                if (d < 0) s.x--;
                else s.x++;
                turtle.push_back(s);
            }
        else
            for (int i = 0; i < abs(d); i++)
            {
                if (d < 0) s.y--;
                else s.y++;
                turtle.push_back(s);
            }
    }
    cin>>t.x>>t.y>>tmm;
    for (int i = 0; i < tmm; i++)
    {
        int d; char op;
        cin>>d>>op;
        if (op=='X')
            for (int i = 0; i < abs(d); i++)
            {
                if (d < 0) t.x--;
                else t.x++;
                gold.push_back(t);
            }
        else
            for (int i = 0; i < abs(d); i++)
            {
                if (d < 0) t.y--;
                else t.y++;
                gold.push_back(t);
            }
    }
    double mindist = 1e10;
    for (int i = 0; i < turtle.size()*gold.size(); i++)
    {
        mindist = min(mindist, dist(turtle[i%turtle.size()], gold[i%gold.size()]));
    }
    printf("%.2lf", mindist);
}
