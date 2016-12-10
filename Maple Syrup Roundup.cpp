#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
int N;
struct point
{
    double x, y;
    point() {x = y = 0.0;}
    point(double a, double b) {x = a; y = b;}
    bool operator == (point other) const
    {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
}p1, p2, p3;
struct vec {double x, y; vec(double a, double b) {x = a; y = b;}};
vec tovec(point a, point b){return vec(b.x - a.x, b.y-a.y);}
double cross(vec a, vec b) {return a.x*b.y - a.y*b.x;}
double CCW (point p, point q, point r) {return cross(tovec(p,q), tovec(p,r)) > 0;}
bool collinear (point p, point q, point r) {return fabs(cross(tovec(p,q), tovec(p,r)) ) < EPS;}
bool cmp(point a, point b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
point pivot(0,0);
bool angleCmp(point a, point b)
{
    if (collinear(pivot, a, b))
    {
        return dist(pivot, a) < dist(pivot, b);
    }
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x) < 0);
}
vector <point> CH(vector <point> &P)
{
    int i, j, n = (int)P.size();
    if (n <= 3)
    {
        if (!(P[0] == P[n-1])) P.push_back(P[0]);
        return P;
    }
    int P0 = 0;
    for (int i = 1; i < n; i++)
    {
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    }
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    //ccw test
    vector <point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
    i = 2;
    while (i < n)
    {
        j = (int)S.size()-1;
        if (CCW(S[j-1], S[j], P[i]))
            S.push_back(P[i++]);
        else
            S.pop_back();
    }
    return S;
}
vector <point> monotone_chain(vector <point> P)
{
    vector <point> CH;
    sort(P.begin(), P.end(), cmp);
    int m= 0, t, n = (int)P.size();
    for (int i = 0; i < n; i++)
    {
        while(m >= 2 && CCW(CH[m-2], CH[m-1], P[i]) <= 0)
            CH.pop_back(), m--;
        CH.push_back(P[i]), m++;
    }
    for (int i = n-1, t = m + 1; i > 0; i--)
    {
        while (m > t && CCW(CH[m-2], CH[m-1], P[i]) <= 0)
            CH.pop_back(), m--;
        CH.push_back(P[i]), m++;
    }
    return CH;
}
vector <point> X;
int main()
{
    int T; cin>>T;
    while (T--)
    {
        X.clear();
        cin>>N;
        for (int i = 0, a,b; i < N; i++)
        {
            cin>>a>>b;
            X.push_back(point(a,b));
        }
        X = CH(X);
        double d = 0;
        for (int i = 0; i < X.size(); i++)
        {
            p1 = X[i], p2 = X[i+1==(int)X.size()?0:i+1];
            if (p1==p2) continue;
            d += dist(p1,p2);
        }
        printf("%.2lf\n", d);
    }
}
