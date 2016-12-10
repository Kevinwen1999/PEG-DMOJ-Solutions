#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define EPS 1e-9
using namespace std;
double X1,X2,X3,Y1,Y2,Y3;
struct point
{
    double x, y;
    point() {x = y = 0.0;}
    point(double a, double b) {x = a; y = b;}
}p1, p2, p3;
double dist(point a, point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}
struct line { double a, b, c;};
void point_to_line(point a, point b, line &l)
{
    if (fabs(a.x-b.x) < EPS)
    {
        l.a = 1.0; l.b = 0.0; l.c = -a.x;
    }
    else
    {
        l.a = -(double) (a.y-b.y) / (a.x-b.x);
        l.b = 1.0;
        l.c = -(double) (l.a * p1.x) - p1.y;
    }
}
struct vec {double x, y; vec(double a, double b) {x = a; y = b;}};
vec tovec(point a, point b){return vec(b.x - a.x, b.y-a.y);}
vec scale (vec v, double s) {return vec(v.x*s, v.y*s);}
point translate (point p, vec v) { return point(p.x + v.x, p.y + v.y);}
double dot(vec a, vec b) {return (a.x*b.x + a.y*b.y);}
double norm_sq(vec v) {return v.x*v.x + v.y*v.y;}
double dist_to_line(point p, point a, point b, point &c)
{
    // c = a + u * ab
    // projection : dot(ap,ab) / sq(ab)
    vec ap = tovec(a,p), ab = tovec(a,b);
    double u = dot(ap,ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p,c);
}
int main()
{
    int T; cin>>T;
    while (T--)
    {
        cin>>X1>>Y1>>X2>>Y2>>X3>>Y3;
        p1 = point(X1,Y1); p2 = point(X2, Y2); p3 = point(X3,Y3);
        double per = dist(p1, p2) + dist(p1, p3) + dist(p2, p3);
        point tmp;
        double area = dist_to_line(p1,p2,p3,tmp) * dist(p2,p3) / 2;
        cout<<fixed<<setprecision(2)<<area<<" "<<per<<"\n";
    }
}
