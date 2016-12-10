#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
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
double magnitude (vec v) {return sqrt(v.x*v.x + v.y*v.y);}
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
double dist_to_lineseg(point p, point a, point b, point &c)
{
    vec ap = tovec(a,p), ab = tovec(a,b);
    double u = dot(ap,ab) / norm_sq(ab);
    if (u < 0.0)
    {
        c = point(a.x, a.y); return dist(p,a);
    }
    if (u > 1.0)
    {
        c = point(b.x, b.y); return dist(p,b);
    }
    return dist_to_line(p,a,b,c);
}
double angle(point a, point o, point b) //return angle AOB in rad, times 180.0/pi to get degree
{
    vec oa = tovec(o,a); vec ob = tovec(o,b);
    return acos(dot(oa, ob)/ sqrt(norm_sq(oa)*norm_sq(ob)));
}
double cross(vec a, vec b) {return a.x*b.y - a.y*b.x;}
bool CCW (point p, point q, point r) {return cross(tovec(p,q), tovec(p,r)) > 0;} //return true if point R is on left side of line PQ
bool collinear (point p, point q, point r) {return fabs(cross(tovec(p,q), tovec(p,r)) ) < EPS;}

int main()
{
    double rx, ry, jx, jy;
    cin>>rx>>ry>>jx>>jy;
    point ro = point(rx,ry), ju = point(jx,jy);
    int T, N; cin>>T;
    int cnt = 0;
    point cur;
    for (int q = 0 ; q < T; q++)
    {
        cin>>N;
        bool outside = true, collision = false;
        vec old(0.0,0.0);
        for (int i = 0 ; i < N; i++)
        {
            double a, b;
            cin>>a>>b;
            point c = point(a,b);
            vec cj = tovec(c,ju), jc = tovec(ju, c), rc = tovec(ro, c),  jr = tovec(ju, ro), rj = tovec(ro, ju);
            point w;
            dist_to_line(c, ro, ju, w);
            vec wc = tovec(w, c);
            if (dot(jr, jc) > 0.0 && dot(rj, rc) > 0.0)
                outside = false;
            if (magnitude(wc) < EPS || dot(wc, old) < 0.0)
                collision = true;
            old.x = wc.x;
            old.y = wc.y;
        }
        if (!outside && collision)
            cnt++;
    }
    cout<<cnt<<"\n";
}
