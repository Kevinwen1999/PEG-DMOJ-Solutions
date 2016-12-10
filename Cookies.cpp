#include <bits/stdc++.h>
using namespace std;
struct point
{
    double x, y;
} cur;
inline double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
vector <point> v;
double m = 0.0;
int main()
{
    int N;
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>cur.x>>cur.y;
        v.push_back(cur);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                double a = dist(v[i], v[j]);
                double b = dist(v[j], v[k]);
                double c = dist(v[i], v[k]);
                double d = 0;
                if (a*a+b*b<c*c||a*a+c*c<b*b||c*c+b*b<a*a)
                {
                    d=  max(a,max(b,c));
                }
                else
                {
                    double s = (a+b+c)/2.0;
                    double area = sqrt(s*(s-a)*(s-b)*(s-c)); //herons' formula
                    double radius = (a*b*c)/(4.0*area); //radius of circumcircle
                    d = radius*2;
                }
                m = max(m,d);
            }
        }
    }
    printf("%.2lf", m);
}
