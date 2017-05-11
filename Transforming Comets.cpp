#include <bits/stdc++.h>
#define MAXN 500010
#define EPS 1e-9
using namespace std;
// POINTS, LINES, VECTORS, DOT/CROSS PRODUCT
const double PI = acos(-1.0);
bool dequals(double a, double b) {
    return fabs(a - b) < EPS;
}
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
vec scale (vec v, double s) {return vec(v.x*s, v.y*s);}
point translate (point p, vec v) { return point(p.x + v.x, p.y + v.y);}
double magnitude (vec v) {return sqrt(v.x*v.x + v.y*v.y);}
double dot(vec a, vec b) {return (a.x*b.x + a.y*b.y);}
double norm_sq(vec v) {return v.x*v.x + v.y*v.y;}
double angle(point a, point o, point b) //return angle AOB in rad, times 180.0/pi to get degree
{
    vec oa = tovec(o,a); vec ob = tovec(o,b);
    return acos(dot(oa, ob)/ sqrt(norm_sq(oa)*norm_sq(ob)));
}
double cross(vec a, vec b) {return a.x*b.y - a.y*b.x;}
double CCW (point p, point q, point r) {return cross(tovec(p,q), tovec(p,r));}
int N;
point PA[MAXN], PB[MAXN];
struct info {
    double ang;
    double rat;
    bool operator != (const info &a) const {
        return !dequals(ang, a.ang) || !dequals(rat, a.rat);
    }
};
info N1[MAXN], N2[MAXN*3];
double calcang(int i, point p[]) {
    int A = i, B = (i+1)%N, C = (i+2)%N;
    double ang = 0;
    double ta = angle(p[A], p[B], p[C]);
    if (CCW(p[A], p[B], p[C]) < 0) ang += PI + (PI-ta);
    else ang = ta;
    return ang;
}
void process (point p[], info n[]) {
    for (int i = 0; i < N; i++) {
        int A = i, B = (i+1)%N, C = (i+2)%N;
        n[i].rat = magnitude(tovec(p[A], p[B])) / magnitude(tovec(p[B], p[C]));
        n[i].ang = calcang(i, p);
    }
}
int b[MAXN];
void kmpPre() {
    memset(b, 0, sizeof b);
    int i = 0, j = -1; b[0] = -1;
    while (i < N) {
        while(j >= 0 && N1[i] != N1[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}
int ans = -1;
void kmpSearch() {
    ans = -1;
    int i = 0, j = 0;
        while(i < 2*N) {
            while(j >= 0 && N2[i] != N1[j]) j = b[j];
            i++; j++;
            if (j == N) {
                ans = i - j;
                return;
            }
        }
}
void rekt() {
    cin>>N;
    for (int i = 0, x, y; i < N; i++) {
        cin>>x>>y;
        PA[i] = point(x,y);
    }
    for (int i = 0, x, y; i < N; i++) {
        cin>>x>>y;
        PB[i] = point(x,y);
    }
    process(PA, N1);
    process(PB, N2);
    for (int i = N; i < 2*N; i++)
        N2[i] = N2[i-N];
    kmpPre();
    kmpSearch();
    printf("%d\n", ans+1);
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        rekt();
    }
}
